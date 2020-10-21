#include <stdio.h>
#include <stdlib.h>

typedef struct contribuinte{
    char CPF[15];
    int dependentes;
    float renda;
    float coef;
    float imposto;

} contribuinte;

int main(){
     int i, salmin, qtd;

     printf("Quanto é o valor atual do salário mínimo?  \n");
     scanf("%d", &salmin);
     printf("Quantos contribuintes serão analisados?  \n");
     scanf("%d", &qtd);

     struct contribuinte *a;
     a = (struct contribuinte *)malloc(qtd * sizeof(struct contribuinte));

     for (i = 0; i < qtd; i++){
          printf("\nInsira o CPF do contribuinte número %d\n", i + 1);
          scanf("%s", a[i].CPF);
          printf("Quantos dependentes possui o contribuinte número %d?\n", i + 1);
          scanf("%d", &a[i].dependentes);
          printf("Insira a renda do contribuinte número %d\n", i + 1);
          scanf("%f", &a[i].renda);
     }


     for (i = 0; i < qtd; i++){
          a[i].renda = a[i].renda - ((0.05 * a[i].renda) * a[i].dependentes);
     }

     printf("\n\n");
     for (i = 0; i < qtd; i++){
          a[i].coef = a[i].renda / salmin;

          if (a[i].coef < 2){
               a[i].imposto = 0;
          }

          else if ((3 > a[i].coef) && (a[i].coef>= 2 )){
               a[i].imposto = a[i].renda * 0.05;
          }

          else if ((5 > a[i].coef) && (a[i].coef>= 3 )){
               a[i].imposto = a[i].renda * 0.1;
          }

          else if ((7 > a[i].coef) && (a[i].coef>= 5 )){
               a[i].imposto = a[i].renda * 0.15;
          }

          else if (a[i].coef>= 7 ){
               a[i].imposto = a[i].renda * 0.2;
          }

          printf("O valor a ser pago do IR do contribuinte %d (CPF: %s) é de %0.2f reais\n", i+1, a[i].CPF, a[i].imposto);
     }

     return 0;
}