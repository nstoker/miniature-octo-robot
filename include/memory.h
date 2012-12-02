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
    protected:
    private:
};

#endif // MEMORY_H
