#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

int main(){
    int N, i, busca; 
    float X[MAXL][4],curso,sex;
    char res;

    // Entrada de dados     
    do{
        printf("Quantidade de alunos: ");
        scanf("%d", &N); 
        if(N > MAXL || N <= 0)            
            printf("Quantidade invalida\n");
    } 
    while (N > MAXL || N <= 0);

    for(i = 0; i < N; i++) {    
        printf("Digite a matricula: ") ;
        scanf("%f", &X[i][0]);

        printf("Digite o sexo: ");     
        scanf("%f", &X[i][1]);

        printf("Digite o curso: ");     
        scanf("%f", &X[i][2]);

        printf("Digite a media: ");     
        scanf("%f", &X[i][3]);
    }

    do {
        printf("Entre com o curso: ");    
        scanf("%f", &curso);
        
        printf("Entre com o sexo: ");    
        scanf("%f", &sex);
        busca = 0;
        i = 0;
        float nota = 0;
        float matricula = 0;
        while (i < N)  {
            if (X[i][2] == curso && X[i][1] == sex) {
                if (nota<X[i][3]){
                        nota = X[i][3];
                        matricula = X[i][0];
                    }
            }
            i = i + 1; 
        } 
        printf("Matricula = %f nota = %f", matricula, nota);
        if (busca == 0)
            printf("Deseja consultar mais um aluno? (S/N)");     
        res = getchar();
            
    }while (toupper(res) == 'S');
}