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
#include <assert.h>
#include "memory.h"
#include <string>
#include <iostream>
#include <iomanip>

Memory::Memory()
{
    //ctor
    for(address a=0;a<MAX_RAM;a++)
        ram[a]=0;
}

Memory::~Memory()
{
    //dtor
    //
//    delete ram;
}

void Memory::write(address addr, byte data)
{
    if((data>0xFF) ||(data<0x00)) throw errData;
    if((addr>0xFFFF)||(addr<0x0000)) throw errAddress;

    ram[addr]=data;
}

byte Memory::read(address addr)
{
    if ((addr>0xFFFF)||(addr<0x0000)) throw errAddress;

    return ram[addr];
}

void Memory::dump(void)
{
    std::cout<<"Dumping memory"<<std::endl;

    std::cout.setf(std::ios::hex,std::ios::basefield);

    for(int a=0x0000;a<0x100;a+=16)
    {
        int line=0;
        for(int b=a;b<a+0x10;b++)
            line+=ram[b];
        if(line>0)
        {
            std::cout<<std::setw(4)<<a<<" : ";
            for(int b=a;b<a+0x10;b++)
            {
                std::cout<<std::setw(2)<<ram[b]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    std::cout<<"End of dump"<<std::endl;
}
