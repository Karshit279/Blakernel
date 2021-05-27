#include "print.c"
#include "idt.c"
#include "outb_inb.c"
#include "cursor.c"
#include "keyboard.c"
#include "memory_mapping.h"

extern void StartIDT();

int _start()
{
	enable_cursor(0,25);
	char String[20] = "Kernel Loaded...    ";
    PrintStringXY(String,20,0,10);
    InitializeIDT();
    PrintStringXY("IDT Loaded",10,0,11);
    PrintStringXY("KeyBoard Input Enabled",22,0,12);
    PrintStringXY("Number Of Memory Regions Present :",34,0,13);PrintStringXY(IntegerToString(MemRegCounts),1,34,13);
    ValidMemRegs();
    //heapMemory is the Heap in form of Struct which conains every information abt Heap
    PrintStringXY((IntegerToString(heapMemory.Length/1048576)),5,0,14);
    PrintStringXY((IntegerToString(heapMemory.Address)),8,0,15);
    //Enabled Cursor and Remember Text Mode Stays in 80x25
    while(1);
}