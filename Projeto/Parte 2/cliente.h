#ifndef _CLIENTE_H
#define _CLIENTE_H

void novoCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente);
void editarCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente);
void excluirCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente, int *qnt_cliente_excluido);
void consultarCliente(struct clientes cliente[], struct veiculos veiculo[], int *qnt_cliente, int *qnt_max_cliente, int *qnt_veiculo, int *qnt_max_veiculo);
void listarCliente(struct clientes cliente[], int *qnt_cliente);

#endif