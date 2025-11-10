#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#include "checks.h"
#include "decoder.h"

int main(int argc, char** argv)
{   
    check_input(argc, argv);

    char** operations = argv + 1;

    unsigned n_symbols = argc - 3;
    unsigned n_ops = argc/3 - 1;
    
    init_res_arr(n_ops);

    int* res_arr = calculate_res(operations, n_symbols);
    
    print_res_arr(res_arr, n_ops);

    int k = atoi(argv[argc - 1]);
    char* res_str = decode_res_str(res_arr, n_ops, k);

    printf("Результирующвя строка: %s\n", res_str);

    free_res_arr();
    free(res_str);

    return 0;

}
