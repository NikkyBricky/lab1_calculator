#include <stdio.h>
#include "calc.h"
#include "checks.h"

int main(int argc, char** argv)
{   
    check_input(argc, argv);

    char** operations = argv + 1;

    int n_symbols = argc - 3;
    int n_ops = argc/3 - 1;
    
    init_res_arr(n_ops);

    int* res_arr = calculate_res(operations, n_symbols);
    
    print_res_arr(res_arr, n_ops);
    free_res_arr();
    return 0;

}
