#ifndef MEMORY_H
#define MEMORY_H

typedef int address;
typedef int byte;

#define MAX_RAM 65536

enum MemErrors {
    errData,
    errAddress,
    errNoMemory,enu
    };
class Memory
{
    public:
        Memory();
        virtual ~Memory();
        void write(address addr,byte data);
        byte read(address addr);
        void dump(void);
    protected:
    private:
        byte ram[MAX_RAM]; // 64K of memory
};

#endif // MEMORY_H
