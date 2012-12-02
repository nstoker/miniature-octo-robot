/***************************************************************
 * Name:      HexUtils.h
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

#ifndef HEXUTILS_H
#define HEXUTILS_H

#include <wx/string.h>

unsigned int HexToInt(wxString theLine, int start,int size);


#endif
