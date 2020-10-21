#include <stdio.h>
#include <stdlib.h>

float calcImposto(float salario);
float novoSalario(float salario);
int classify (float salario);

int main(){
    int escolha;
    float salario, imposto;

    printf("Menu de opcões:\n");
    printf("\t1. Impostos\n");
    printf("\t2. Novo salario\n");
    printf("\t3. Classificacao\n");
    scanf("%d", &escolha);

    salario = 0;
    printf("\nInsira o salario: ");
    scanf("%f", &salario);

    switch (escolha){
          case 1:
               printf("O imposto sera de %.2f\n", calcImposto(salario));
               break;

          case 2:
               printf("O novo salario sera de %.2f\n", novoSalario(salario));
               break;

          case 3:
               if (classify(salario) == 0){
                    printf("O salario é considerado mal remunerado");
               }
               if (classify(salario) == 1){
                    printf("O salario é considerado bem remunerado");
               }
               break;

          default:
               printf("Opcao invalida");
               break;
    }

    return 0;
}

float calcImposto(float salario){
    float imposto;

    if (salario >= 0 && salario < 500){
        imposto = salario * 0.05;
    }
    if (salario >= 500 && salario <= 850){
        imposto = salario * 0.10;
    }
    if (salario > 850){
        imposto = salario * 0.15;
    }
    return imposto;
}

float novoSalario(float salario){
    if (salario > 1500){
        salario = salario + 25;
    }
    if (salario >= 750 && salario < 1500){
        salario = salario + 50;
    }
    if (salario >= 450 && salario < 750){
        salario = salario + 75;
    }
    if (salario >= 0 && salario < 450){
        salario = salario + 100;
    }
    return salario;
}

int classify (float salario){
    if (salario >= 0 && salario <= 700){
        return 0;
    }
    if (salario > 700){
        return 1;            
    }
}