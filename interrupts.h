#pragma once
typedef struct {
    word edi;
    word esi;
    word ebp;
    word esp;
    word ebx;
    word edx;
    word ecx;
    word eax;

    hword gs;
    hword gap1;
    hword fs;
    hword gap2;
    hword es;
    hword gap3;
    hword ds;
    hword gap4;

    word vector;
    word error_code;

    word eip;
    hword cs;
    hword gap5;
    word eflags;
} context;

void panic(context*);
void make_idt();
void make_idtr();
