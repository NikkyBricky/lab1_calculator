#pragma once

void init_res_arr(unsigned cap);
void free_res_arr();
int* calculate_res(char** operations, unsigned n_symbols);
void print_res_arr(int* res_arr, unsigned n_ops);

