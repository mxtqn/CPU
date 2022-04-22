#include <stdio.h>

int soma(int primeiroregistrador, int segundoregistrador){
    int resultadosoma;
    primeiroregistrador = primeiroregistrador + segundoregistrador;
    return(resultadosoma);
};

unsigned int mbr = 0, mar, imm, pc = 0;
unsigned int reg[8];
unsigned char ir, ro0, ro1, e, l, g;
char memoria[154];

int main(void) {
    //Instruções
    int hlt     = 0x0,
        nop     = 0x1,
        add     = 0x2,
        sub     = 0x3,
        mul     = 0x4,
        div     = 0x5,
        cmp     = 0x6,
        movr    = 0x7,
        and     = 0x8,
        or      = 0x9,
        xor     = 0xA,
        not     = 0xB,
        je      = 0xC,
        jne     = 0xD,
        jl      = 0xE,
        jle     = 0xF,
        jg      = 0x10,
        jge     = 0x11,
        jmp     = 0x12,
        ld      = 0x13,
        st      = 0x14,
        movi    = 0x15,
        addi    = 0x16,
        subi    = 0x17,
        muli    = 0x18,
        divi    = 0x19,
        lsh     = 0x1A,
        rsh     = 0x1B;

    reg[0] = 000;
    reg[1] = 001;
    reg[2] = 010;
    reg[3] = 011;
    reg[4] = 100;
    reg[5] = 101;
    reg[6] = 110;
    reg[7] = 111;

    pc = 0;

    //Memória falsa
    memoria[0] = 0x13;
    memoria[1] = 0x0;
    memoria[2] = 0x0;
    memoria[3] = 0x1E;

    memoria[4] = 0x13;
    memoria[5] = 0x20;
    memoria[6] = 0x0;
    memoria[7] = 0x24;

    memoria[8] = 0x2;
    memoria[9] = 0x4;
    memoria[10] = 0x0; //??????????
    memoria[11] = 0x0;

    memoria[12] = 0x16;
    memoria[13] = 0x0;
    memoria[14] = 0x0;
    memoria[15] = 0x14;
    memoria[30] = 0x15;

    //Carregar mbr - buscar instrução -
    mbr = memoria[pc++] << 8;
    mbr = (mbr | memoria[pc++]) << 8;
    mbr = (mbr | memoria[pc++]) << 8;
    mbr = mbr | memoria[pc++];

    // Pegar o Opcode da instrução dentro do mbr
    ir = (mbr) >> 24;

    printf("MBR = %08x\n", mbr);
    printf("IR = %08x\n", ir);

    //achar instrução
    if (ir == hlt) {};
    if (ir == nop) {};
    if (ir == add) {};
    if (ir == sub) {};
    if (ir == mul) {};
    if (ir == div) {};
    if (ir == cmp) {};
    if (ir == movr) {};
    if (ir == and) {};
    if (ir == or) {};
    if (ir == xor) {};
    if (ir == not) {};
    if (ir == je ) {};
    if (ir == jne ) {};
    if (ir == jl ) {};
    if (ir == jle ) {};
    if (ir == jg) {};
    if (ir == jge) {};
    if (ir == jmp) {};
    
    if (ir == ld) {
        int posicao = (mbr & 0x001fffff);
        int tmp     = (mbr & 0x00e00000) >> 21;

            if (tmp == reg[0]){ reg[0] = memoria[posicao]; };
            if (tmp == reg[1]){ reg[1] = memoria[posicao]; };
            if (tmp == reg[2]){ reg[2] = memoria[posicao]; };
            if (tmp == reg[3]){ reg[3] = memoria[posicao]; };
            if (tmp == reg[4]){ reg[4] = memoria[posicao]; };
            if (tmp == reg[5]){ reg[5] = memoria[posicao]; };
            if (tmp == reg[6]){ reg[6] = memoria[posicao]; };
            if (tmp == reg[7]){ reg[7] = memoria[posicao]; };

        printf("Conteúdo registrador = %x\n", reg[0]);
    };
    
    if (ir == st) {};
    if (ir == movi) {};
    if (ir == addi) {};
    if (ir == subi ) {};
    if (ir == muli ) {};
    if (ir == divi ) {};
    if (ir == lsh ) {};
    if (ir == rsh) {};

    return 0;
}
