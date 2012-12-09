#ifndef MEMORY_H
#define MEMORY_H

typedef unsigned short address;
typedef unsigned int byte;

enum MemErrors {
    errValue,
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
        byte ram[0xFFFF]; // 64K of memory
        bool ick(address);
};

#endif // MEMORY_H
