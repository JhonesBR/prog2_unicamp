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
    char cpfAluguel[15];
};

struct locacoes
{
    int id;
    int tipo;
    char cpf[15];
    char name[100];
    char placa[10];
    char marca[50];
    char modelo[75];
    char telefone[20];
    int ano;
    char data[20];
    char dataDev[20];
};

void clearScreen();

void reallocSizeCliente(struct clientes p[], int n);
void reallocSizeVeiculo(struct veiculos p[], int n);
void reallocSizeLocacao(struct locacoes p[], int n);

int verifyExistCliente(struct clientes cliente[], char cpf[15], int qnt_cliente);
int verifyExistVeiculo(struct veiculos veiculo[], char placa[10], int qnt_veiculo);

void organizeListCliente(struct clientes cliente[], int qnt_cliente, int *qnt_cliente_excluido);
void organizeListVeiculo(struct veiculos veiculo[], int qnt_veiculo, int *qnt_veiculo_excluido);

#endif
