/***************************************************************
 * Name:      readIntelHex.cpp
 * Purpose:   Reads an Intex Hex format file and inserts into memory
 * Author:    Neil Stoker (neil.stoker@gmail.com)
 * Created:   2012-12-01
 * Copyright: Neil Stoker (https://sites.google.com/site/neilstoker/)
 * License:   LGPL v3
              This file is part of lib65.

             lib65 is free software: you can redistribute it and/or modify
             it under the terms of the GNU Lesser Public License as published by
             the Free Software Foundation, either version 3 of the License, or
             (at your option) any later version.

             lib65 is distributed in the hope that it will be useful,
             but WITHOUT ANY WARRANTY; without even the implied warranty of
             MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
             GNU General Lesser License for more details.

             You should have received a copy of the GNU Lesser Public License
             along with lib65.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************************/

using namespace std;

//#include <fstream>
//#include <iostream>
//#include <sstream>
//#include <streambuf>
#include <wx/Log.h>
#include <wx/textfile.h>
#include "readIntelHex.h"
#include "HexUtils.h"


wxString readIntelHex::getError(void)
{
    return errMessage; // TODO return the error string properly
}


errHRec readIntelHex::loadLine(wxString theLine, Memory *mem)
{
        /* Each line of Intel HEX file consists of six parts:

       Start code, one character, an ASCII colon ':'.
       byte count, two hex digits, a number of bytes (hex digit pairs) in the data field.
       16 (0x10) or 32 (0x20) bytes of data are the usual compromise values between line
       length and address overhead.

       Address, four hex digits, a 16-bit address of the beginning of the memory position
       for the data. Limited to 64 kilobytes, the limit is worked around by specifying higher
       bits via additional record types. This address is big endian.

       Record type, two hex digits, 00 to 05, defining the type of the data field.

       Data, a sequence of n bytes of the data themselves, represented by 2n hex digits.
     */

     int l = theLine.length();

     if(l<11)
     {
         return HRecTooShort;
     }

    if(!theLine.at(0)==':')
    {
        errMessage=wxT("Invalid start character. Expected ':', received '")+theLine.at(0);
        return HRecInvalidStart;
    }

    if(!validChecksum(theLine))
    {
        errMessage=wxT("Invalid checksum, file has '") +theLine.substr(theLine.length()-2)+ wxT(" calculated as ")+errMessage;
        return HRecChecksumErr;
    }

    long numbytes=HexToInt(theLine,1,2);
    address addr=HexToInt(theLine,3,4);
    int recType=HexToInt(theLine,7,2);

    switch (recType)
    {
        case hRecDataRecord:
        for(int i=0;i<numbytes;i++)
        {
            int data=HexToInt(theLine,i*2+9,2);
            mem->write(addr,data);
            addr++;
        }
        break;
        case hRecEOFRecord:
            // TODO (ns#1#): Setup a "program start" address load
            break;
        case hRecExtSegment:
        case hRecStartSegment:
        case hRecExtendedLinear:
        case hRecStartLinear:
            break;
        default:
            break;
    }
    return HRecOk;
}
bool readIntelHex::validChecksum(wxString theLine)
{
        /* Checksum, two hex digits - the least significant byte of the two's complement of the sum of
       the values of all fields except fields 1 and 6 (Start code ":" byte and two hex digits of
       the Checksum). It is calculated by adding together the hex-encoded bytes (hex digit pairs),
       then leaving only the LSB of the result, and making a 2's complement (either by subtracting
       the byte from 0x100, or inverting it by XOR-ing with 0xFF and adding 0x01).

       If you are not working with 8-bit variables, you must suppress the overflow by AND-ing the
       result with 0xFF. The overflow may occur since both 0x100-0 and (0x00 XOR 0xFF)+1 equal 0x100.
       If the checksum is correctly calculated, adding all the bytes (the byte count, both bytes in
       Address, the Record type, each Data byte and the Checksum) together will always result in a
       value wherein the least significant byte is zero (0x00).

       For example, on :0300300002337A1E

       03 + 00 + 30 + 00 + 02 + 33 + 7A = E2, 2's complement is 1E

    */

    int chksum=0;
    int numPairs=(theLine.length()-1)/2-1;

    for(int i=0;i<numPairs;i++)
    {
        unsigned int abyte=HexToInt(theLine,1+(i*2),2);
        chksum += abyte;
        chksum &= 0xFF;
    }

    chksum &= 0xFF;
    chksum ^= 0xFF;
    chksum++;

    long cf=HexToInt(theLine,theLine.length()-2,2);
    bool rv=(chksum==cf);
    if(!rv)
        errMessage=wxString::Format(wxT("%i"),cf);
    return rv;
}

/*-------------------------------------------------------------------
  readIntelHex::openFile

  Purpose: reads the selected file into memory.
           The values will be written into the specified memory locations
*/
bool readIntelHex::openFile(wxString fName,Memory *ram)
{
    // Read entire file, then insert into memory.
    wxString theLine;
    errHRec status=HRecOk;

    wxTextFile tFile;
    if (!tFile.Open(fName))
    {
        status=HFileNotFound;
    } else
    {
        theLine=tFile.GetFirstLine();
    }

    while(status==HRecOk)
    {
        status = loadLine(theLine,ram);
        if (status==HRecTooShort){
            break;
        }
            theLine=tFile.GetNextLine();
            if (theLine.length()==0)
            {
                // No EOF flag? TODO
                break;
            }
    }

    return status==HRecOk;
}
