#ifndef _LOCACAO_H
#define _LOCACAO_H

void locacaoVeiculo(struct clientes cliente[], struct veiculos veiculo[], struct locacoes locacao[], int *qnt_cliente, int *qnt_veiculo, int *qnt_locacao, int *qnt_max_locacao);
void devolucaoVeiculo(struct clientes cliente[], struct veiculos veiculo[], struct locacoes locacao[], int *qnt_cliente, int *qnt_veiculo, int *qnt_locacao, int *qnt_max_locacao);
void relatorioLocacao(struct locacoes locacao[], int *qnt_locacao);

#endif
