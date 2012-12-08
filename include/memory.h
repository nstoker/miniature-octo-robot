#ifndef MEMORY_H
#define MEMORY_H

typedef unsigned short address;
typedef unsigned char byte;

class Memory
{
    public:
        Memory();
        virtual ~Memory();
        void write(address addr,byte data);
        byte read(address addr);
    protected:
    private:
        byte ram[0xFFFF]; // 64K of memory
};

#endif // MEMORY_H
