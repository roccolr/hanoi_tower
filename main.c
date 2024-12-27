#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"


int main(int argc, char ** argv){
    int dim = atoi(argv[1]);
    printf("[MAIN]\tSTARTING A %d ORDER PROBLEM\n", dim);

    struct hanoi_problem * hp = create_hanoi_problem(dim);
    printf("[MAIN]\tPROBLEM CREATED\n");

    display_towers_status(hp);
    solve(hp, hp->dim, hp->A, hp->C, hp->B);

    printf("[MAIN]\tPROBLEM SOLVED\n");
    display_towers_status(hp);

    destroy_hanoi_problem(hp);

    return 0;
}