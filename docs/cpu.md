# CPU

## Architecture

6502 address 16-bits 0-65535 ($0000-$FFFF)

65C816 address 24-bits $00000-$FFFFF

## Memory

First 256 bytes ($0000-$00FF) known as Zero Page.

Second 256 bytes ($0100-$01FF) is a fixed stack.

Non Maskable Interrupt handler $FFFA/B.

Power on Reset location $FFFC/D.

Break interupt handler $FFFE/F.

## Registers

### Program Counter

16-bit register pointing to the next instruction to be executed.

24-bit in 65C816.

### Stack Pointer

Points to an area between $0100 and $01FF.

The stack pointer holds the lower 8-bits of the address to be accessed.

Pushing bytes to the SP causes the pointer to be decremented. Incremented by pulling bytes.

The CPU does not check for over/underflows of the SP. If it does, you're program is probably toast.

### Databank

8-bits providing the upper 8 bits of the address. (65C816 only).

### Accumulator

6502 An 8-bit register used for all Arithmetic and Logical operations.

65C816 also has an 8-bit register

### Index Register X

An 8-bit register used to hold counters for offsets to memory. It can get a copy of the stack pointer, or change it's value.

### Index Register Y

Similar to X, but no special operations.

### Processor Status

Short|Name|Purpose
-|-|-
C|Carry|Set if the last operation causes an overflow from bit 7 of the result, or an underflow from bit 0. Set during arithmetic, comparison, and logical shifts
Z|Zero|Set if the last operation result was 0
||Interrupt Disable|When set (by `SEI`) the processor will not respond to interrupts until `CLI` instruction
||Decimal|Sets decimal mode
||Break| set when a `BRK` instruction executed
V|Overflow|Set during arithmetic operations if the operation resulted in an invalid 2's complement result
N|Negative|Set if the result of the last operation had bit 7 set to 1
m||65C816 only
x||65C816 only
D||65C816 only

