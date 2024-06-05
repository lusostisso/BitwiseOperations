#include <stdio.h>

void exibe(unsigned int x);
int testBit(unsigned int x, int bit);
int setBit(unsigned int x, int bit);
int invertBit(unsigned int x, int bit);
int clearBit(unsigned int x, int bit);

void exibe(unsigned int x) {
    int total = sizeof(x) * 8; // total de bits a exibir
    unsigned int mascara = (1 << (total-1));
    printf("Binario: ");
    for(int i=0; i<total; i++) {
        if((x & mascara) != 0)
            printf("1");
        else
            printf("0");
        x = x << 1;
    }
    printf("\n");
}

int testBit(unsigned int x, int bit) {
    unsigned int mascara = (1 << bit);
    if ((x & mascara) != 0)
        return 1;
    return 0;
}

int invertBit(unsigned int x, int bit){
    unsigned int mascara = 1 << bit; //00000001 que forma por 1 é deslocado bit vezes para a esquerda
    return x ^ mascara; // xor tudo sendo 0 só o bit que quero inverter é 1, V V -> F; F V -> V
}

int setBit (unsigned int x, int bit) {
    unsigned int mascara = 1 << bit; 
    return x | mascara; // or tudo sendo 0 só o bit que quero definir é 1, resulta em 1 sempre
}

int clearBit (unsigned int x, int bit) {
    unsigned int mascara = ~(1 << bit); //00000001 que forma por 1 é deslocado bit vezes para a esquerda e negado, forma 1111110
    return x & mascara; // and sempre zera o bit que é 0
}

int main()
{
    unsigned int v = 65535;
    printf("Decimal: %u\n", v);
    exibe(v);
    printf("\n");

    printf("Bit 16: %d\n", testBit(v, 16));
    printf("Bit 15: %d\n", testBit(v, 15));
    printf("\n");

    
    v = invertBit(v, 5);
    printf("Decimal: %u\n", v);
    exibe(v);
    printf("\n");

    v = setBit(v, 18);
    printf("Decimal: %u\n", v);
    exibe(v);
    printf("\n");

    v = clearBit(v, 9);
    printf("Decimal: %u\n", v);
    exibe(v);
}
