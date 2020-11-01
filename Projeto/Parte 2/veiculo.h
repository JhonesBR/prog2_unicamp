#ifndef _VEICULO_H
#define _VEICULO_H

void novoVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo);
void excluirVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido);
void consultarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_cliente, int *qnt_max_cliente, struct clientes cliente[]);
void listarVeiculo(struct veiculos veiculo[], int *qnt_veiculo);

#endif
