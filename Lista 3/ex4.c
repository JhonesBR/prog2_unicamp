#include <stdlib.h>
#include <stdio.h>

int main(){
    int *v, i;
    v = (int *) malloc(100*sizeof(int));

    for (i=0; i<100; i++){
        *(v+i) = i+1;
        printf("v[%d] (%d) = %d\n", i, (v+i), *(v+i));
    }

    return 0;
}