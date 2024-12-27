#include "utils.h"


struct hanoi_problem * create_hanoi_problem(int dim){
    struct hanoi_problem * hp = (struct hanoi_problem *)malloc(sizeof(struct hanoi_problem)); 
    hp->dim = dim;
    hp->A = (int *) malloc(sizeof(int)*dim);
    hp->B = (int *) malloc(sizeof(int)*dim);
    hp->C = (int *) malloc(sizeof(int)*dim);
    for(int i = 0; i<dim; i++){
        hp->A[i] = i+1;
        hp->B[i] = 0;
        hp->C[i] = 0;
    }
    return hp;
}

void display_towers_status(struct hanoi_problem * hp){
    printf("[TOWER STATUS]\n");
    printf("[A]:\t");
    for(int i=0; i<hp->dim; i++){
        printf("%d\t", hp->A[i]);
    }
    printf("\n[B]:\t");
    for(int i=0; i<hp->dim; i++){
        printf("%d\t", hp->B[i]);
    }
    printf("\n[C]:\t");
    for(int i=0; i<hp->dim; i++){
        printf("%d\t", hp->C[i]);
    }
    printf("\n");

}

void move_disk(struct hanoi_problem * hp, int * source, int * dest){
    //find the top disk in the source tower 
    int disk = 0;
    for(int i = hp->dim-1; i >= 0; i--){
        if(source[i] != 0){
            disk = source[i];
            source[i] = 0;
            break;
        }
    }

    //replace the disk in the first space available on dest
    for(int i=0; i<hp->dim; i++){
        if(dest[i] == 0){
            dest[i] = disk;
            break;
        }
    }
}

void solve(struct hanoi_problem * hp, int n, int * source, int * dest, int * auxilar){
    if(n == 1) {
        move_disk(hp,source, dest);
        return;
    }
    solve(hp, n-1, source, auxilar, dest);
    move_disk(hp, source, dest);
    solve(hp, n-1, auxilar, dest, source);
}

void destroy_hanoi_problem(struct hanoi_problem * hp){
    free(hp->A);
    free(hp->B);
    free(hp->C);
    free(hp);
}






