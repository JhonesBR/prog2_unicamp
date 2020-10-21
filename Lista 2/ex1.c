#include <stdio.h>
#include <stdlib.h>

int somatorio(int);
float somaInverso(int);
float somaInversoFat(int);
long int fat(int);

int main(){
    int n, i;

    // Para numeros maiores que 13 as funções com fatorial não apresentam valores corretos

    printf("Insira um numero N >= 1: ");
    scanf("%d", &n);

    printf("\n\nSomatorio de 1 a N - %d\n", somatorio(n));
    printf("Somatorio b (1 + 1/2 + 1/3 ... + 1/N) - %f\n", somaInverso(n));
    printf("Somatorio c (1 + 1/1! + 1/2! + 1/3! ... + 1/N!) - %f\n\n", somaInversoFat(n));

    return 0;
}

int somatorio(int n){
    if (n <= 1)
        return 1;
    return n + somatorio(n-1);
}

float somaInverso(int n){
    if (n <= 1)
        return 1;
    return (1.0/n + somaInverso(n-1.0));
}

float somaInversoFat(int n){
    if (n == 0)
        return 1;
    return (1.0/fat(n) + somaInversoFat(n-1.0));
}

long int fat(int n){
    if (n <= 1)
        return 1;
    return n * fat(n-1);
}