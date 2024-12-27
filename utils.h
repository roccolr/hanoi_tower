#ifndef UTILS_H_
#define utiLS_H_

#include <stdio.h>
#include <stdlib.h>

struct hanoi_problem {
    int * A;
    int * B; 
    int * C;
    int dim;
};

struct hanoi_problem * create_hanoi_problem(int);
void display_towers_status(struct hanoi_problem *);
void move_disk(struct hanoi_problem *, int * , int * );
void solve(struct hanoi_problem *, int, int *, int *, int *);
void destroy_hanoi_problem(struct hanoi_problem *);


#endif