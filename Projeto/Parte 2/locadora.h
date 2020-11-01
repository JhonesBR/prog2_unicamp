#ifndef _LOCADORA_H
#define _LOCADORA_H

struct clientes
{
    char name[100];
    char cpf[15];
    char cnh[15];
    char telefone[20];
};
struct veiculos
{
    char marca[50];
    char modelo[75];
    int ano;
    char placa[10];
    int state;
};

void clearScreen();

void makeRight(char *s[]);

void reallocSizeCliente(struct clientes p[], int n);
void reallocSizeVeiculo(struct veiculos p[], int n);
int verifyExistCliente(struct clientes cliente[], char cpf[15], int qnt_cliente);
int verifyExistVeiculo(struct veiculos veiculo[], char placa[10], int qnt_veiculo);

#endif
