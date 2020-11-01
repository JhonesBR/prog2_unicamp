#ifndef _VEICULO_H
#define _VEICULO_H

void cadastrarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo);
void excluirVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido);
void consultarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido);
void listarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido);

#endif