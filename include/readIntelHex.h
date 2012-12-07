/***************************************************************
 * Name:      readIntelHex.h
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

#ifndef READINTELHEX_H
#define READINTELHEX_H

#include <map>
#include <wx/string.h>
#include "memory.h"

enum errHRec {
	HRecEOF=-100,
	HRecInvalidStart,
	HRecInvalidCount,
	HRecInvalidAddress,
	HRecInvalidType,
	HRecTooShort,
	HRecChecksumErr,
	HRecFail,
	HRecFile,
	HFileNotFound,
	HRecOk=0
};
enum tHRec {
	hRecDataRecord=0,
	hRecEOFRecord,
	hRecExtSegment,
	hRecStartSegment,
	hRecExtendedLinear,
	hRecStartLinear
};
class readIntelHex
{
    public:
        /** Default constructor */
        //readIntelHex();
        /** Default destructor */
        //virtual ~readIntelHex();
        bool openFile(wxString fName,Memory *ram);
        wxString getError(void);
    protected:
    private:
    wxString errMessage;

    errHRec loadLine(wxString theLine,Memory *ram);
    bool validChecksum(wxString theLine);
};

#endif // READINTELHEX_H
