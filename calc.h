#pragma once

void init_res_arr(int cap);
void free_res_arr();
int* calculate_res(char** operations, int n_symbols);
void print_res_arr(int* res_arr, int n_ops);

