/***************************************************************
 * Name:      HexUtils.cpp
 * Purpose:   A variety of hex routines
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

#include "HexUtils.h"

unsigned int HexToInt(wxString theLine, int start,int size)
{
    long rv=0;
    wxString ss=theLine.substr(start,size);
    bool valid=ss.ToLong(&rv,16);
//    bool valid=theLine.substr(start,size).ToLong(&rv,16);
    if (valid)
        return rv;
    else
        return -1;
}
