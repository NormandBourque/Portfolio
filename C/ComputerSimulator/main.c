/**
* Grace Hopper
* CIS 205 – L1
* Lab
*
* Simulates
*/



#include <stdio.h>
#include <stdlib.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

    struct computer
    {
        int *ip;
        unsigned int pc;
        unsigned int ir;
        int accumulator;
        unsigned int size;
        unsigned int opcode;
        unsigned int address;
    };

//prototypes
void enterCommands(struct computer *cpu);
void fetch(struct computer *cpu);
void decode(struct computer *cpu);
void execute(struct computer *cpu);
void read(struct computer *cpu);
void write(struct computer *cpu);
void load(struct computer *cpu);
void store(struct computer *cpu);
void add(struct computer *cpu);
void subtract(struct computer *cpu);
void multiply(struct computer *cpu);
void divide(struct computer *cpu);
void branch(struct computer *cpu);
void branchneg(struct computer *cpu);
void branchzero(struct computer *cpu);
void print_cpu_and_memory(struct computer *cpu);

int main()
{
    //initialize struck computer to cpu
    struct computer cpu;
    //insure all registers are clear before execution.
    cpu.pc = 0;
    cpu.ir = 0;
    cpu.accumulator = 0;
    cpu.size = 0;
    cpu.opcode = 0;
    cpu.address = 0;

    //skip guard insure range is between 10 and 1000 per power point
    do
    {
        printf("%s", "How much memory do you need? At least 10 at most 1000: ");
        scanf("%u", &cpu.size);
    }
    while(cpu.size >= 1001 || cpu.size <= 9);

    //set pointer equil to the size of memory needed.
    cpu.ip = malloc(sizeof(int) * cpu.size);

    //enters commands into memory.
    enterCommands(&cpu);

    //keeps on fetch, decode, execute cycle until opcode is a HALT prints at the end of the cycle to watch what happens.
    while(cpu.opcode != HALT)
    {
        fetch(&cpu);
        decode(&cpu);
        execute(&cpu);
        print_cpu_and_memory(&cpu);
    }

    //frees memory.
    free(cpu.ip);
    return 0;
}

/**
* Prints out the contents of the "cpu" and memory.
*
* pre: program loaded into memory.
* post: Printed out contents.
*
*/
void print_cpu_and_memory(struct computer *cpu)
{
    int count = 0;
    printf("%s\n","Cpu");
    printf("pc = %u\n", cpu->pc);
    printf("ir = %u\n", cpu->ir);
    printf("accumulator = %d\n", cpu->accumulator);
    printf("size = %u\n", cpu->size);
    printf("opcode = %u\n", cpu->opcode);
    printf("address = %u\n", cpu->address);

    printf("%s","Memory\n");
    for(count = 0;count < cpu->size;count++)
    {
        printf("%03d %d\n", count, cpu->ip[count]);
    }
}

/**
* Calls the apropreate method for the opcode
*
* pre: instructions loaded into op code.
* post: one execution of a op code to memory.
*
*/
void execute(struct computer *cpu)
{
    switch(cpu->opcode)
    {
        case READ:
            read(cpu);
        break;
        case WRITE:
            write(cpu);
        break;
        case LOAD:
            load(cpu);
        break;
        case STORE:
            store(cpu);
        break;
        case ADD:
            add(cpu);
        break;
        case SUBTRACT:
            subtract(cpu);
        break;
        case MULTIPLY:
            multiply(cpu);
        break;
        case DIVIDE:
            divide(cpu);
        break;
        case BRANCH:
            branch(cpu);
        break;
        case BRANCHNEG:
            branchneg(cpu);
        break;
        case BRANCHZERO:
            branchzero(cpu);
        break;
        case HALT:
        break;
    }
}

/**
* Reads keyboard input into memory location at address and increases program counter.
*
* pre: program loaded into memory.
* post: memory filled with opcode and memory location. pc increased.
*
*/
void read(struct computer *cpu)
{
    scanf("%d",&cpu->ip[cpu->address]);
    cpu->pc++;
}

/**
* writes the value stored at address to the screen
*
* pre: Program loaded into memory.
* post: Prints out of memory at address. pc incremented
*
*/
void write(struct computer *cpu)
{
    printf("%d", cpu->ip[cpu->address]);
    cpu->pc++;
}

/**
* loads the accumulator with the memory contents of address
*
* pre: program loaded into memory.
* post: accumulator loaded with a value and pc incremented.
*
*/
void load(struct computer *cpu)
{
    cpu->accumulator = cpu->ip[cpu->address];
    cpu->pc++;
}

/**
* stores current value in accumulator into a memory address.
*
* pre: program loaded into memory.
* post: memory location filled with a value. pc increased
*
*/
void store(struct computer *cpu)
{
    cpu->ip[cpu->address] = cpu->accumulator;
    cpu->pc++;
}

/**
* adds the value stored at memory location with the accumulator and stores it there
*
* pre: program loaded into memory.
* pre: value stored at the address
* post: changed value in accumulator pc increased
*
*/
void add(struct computer *cpu)
{
    cpu->accumulator += cpu->ip[cpu->address];
    cpu->pc++;
}

/**
* subtracts the value stored at memory location with the accumulator and stores it there
*
* pre: program loaded into memory.
* pre: value stored at the address
* post: changed value in accumulator pc increased
*
*/
void subtract(struct computer *cpu)
{
    cpu->accumulator -= cpu->ip[cpu->address];
    cpu->pc++;
}

/**
* multiples the value stored at memory location with the accumulator and stores it there
*
* pre: program loaded into memory.
* pre: value stored at the address
* post: changed value in accumulator pc increased
*
*/
void multiply(struct computer *cpu)
{
    cpu->accumulator *= cpu->ip[cpu->address];
    cpu->pc++;
}

/**
* divides the value stored at memory location with the accumulator and stores it there
*
* pre: program loaded into memory.
* pre: value stored at the address
* post: changed value in accumulator pc incresed
*
*/
void divide(struct computer *cpu)
{
    cpu->accumulator *= cpu->ip[cpu->address];
    cpu->pc++;
}

/**
* Sets the program counter to the address stored in the cpu
*
* pre: program loaded into memory.
* pre: a valid address.
* post: changed value in program counter.
*
*/
void branch(struct computer *cpu)
{
    cpu->pc = cpu->address;
}

/**
* Checks to see if the value in the accumulator is negitive if it is sets the program counter to the address stored in the cpu.
*
* pre: program loaded into memory.
* pre: value stored in the accumulator
* post: Either set program counter to the address stored in cpu or incremented program counter if it didn't branch.
*
*/
void branchneg(struct computer *cpu)
{
    if(cpu->accumulator < 0)
    {
        cpu->pc = cpu->address;
    }
    else
    {
        cpu->pc++;
    }
}

/**
* Checks to see if the value in the accumulator is zero if it is sets the program counter to the address stored in the cpu.
*
* pre: program loaded into memory.
* pre: value stored in the accumulator
* post: Either set program counter to the address stored in cpu or incremented program counter if it didn't branch.
*
*/
void branchzero(struct computer *cpu)
{
    if(cpu->accumulator == 0)
    {
        cpu->pc = cpu->address;
    }
       else
    {
        cpu->pc++;
    }
}

/**
* gets the current value in the instruction register and decodes it into its operation code and memory address.
*
* pre: program loaded into memory.
* pre: value stored in the instruction register.
* post: values stored in operation code and address.
*
*/
void decode(struct computer *cpu)
{
    cpu->opcode = cpu->ir / 1000;
    cpu->address = cpu->ir % 1000;
}

/**
* gets the current value the instruction pointer/program counter is pointing to and loads it into the instruction register.
*
* pre: program loaded into memory.
* pre: value stored at the ip/pc
* post: loaded instruction register.
*
*/
void fetch(struct computer *cpu)
{
    cpu->ir = cpu->ip[cpu->pc];
}

/**
* gets input from keyboard and stores it at the next open memory address.  or anything greater then or equil to 999999
*
* pre: program loaded into memory.
* pre: value stored at the ip/pc
* post: loaded instruction register.
*
*/
void enterCommands(struct computer *cpu)
{
    int count = 0;
    printf("%s", "Enter Commands or 999999 to quit\n");
    for(count = 0;count < cpu->size;count++)
    {
        printf("%03d ", count);
        scanf("%d", &cpu->ip[count]);
        if(cpu->ip[count] >= 999999)
        {
            count = cpu->size;
        }
    }
}
