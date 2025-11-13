#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

static int* RES_ARR = NULL;


void init_res_arr(unsigned cap)
{
    int* temp = (int*)malloc(cap * sizeof(int));
    if (!temp)
    {
        printf("Недостаточно памяти\n");
	exit(1);
    }
    RES_ARR = temp;
}


void free_res_arr()
{
    free(RES_ARR);
    RES_ARR = NULL;
}


int* calculate_res(char** operations, unsigned n_symbols)
{
    int res;
    size_t len = 0;

    for (size_t i = 0; i < n_symbols; i += 3)
    {
        char op = *operations[i + 1];
        switch (op)
	{
	    case '+':
	        res = atoi(operations[i]) + atoi(operations[i + 2]);
		break;
	    case '-':
	        res = atoi(operations[i]) - atoi(operations[i + 2]);
		break;
	    case '*':
	        res = atoi(operations[i]) * atoi(operations[i + 2]);
		break;
	    case '%':
	        res = atoi(operations[i]) % atoi(operations[i + 2]);
		break;
	}

        RES_ARR[len] = res;
        ++len;    
    }

    return RES_ARR;
}


void print_res_arr(int* res_arr, unsigned n_ops)
{
    for (size_t i = 0; i < n_ops; ++i)	    
    {
        printf("Ответ №%zu: %d\n", i + 1, res_arr[i]);
    }
}


