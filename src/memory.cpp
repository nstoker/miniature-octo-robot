/*     This file is part of lib65.

    lib65 is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser Public License for more details.

    You should have received a copy of the GNU Lesser Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "memory.h"

Memory::Memory()
{
    //ctor
}

Memory::~Memory()
{
    //dtor
}

void Memory::write(address addr, byte data)
{
    ram[addr]=data;
}

byte Memory::read(address addr)
{
    return ram[addr];
}
