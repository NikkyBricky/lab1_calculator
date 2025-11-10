#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decode_res_str(int* res_arr, unsigned num_el, int k)
{
    char* temp_res_str = (char*)malloc((num_el + 1) * sizeof(char));
    if (!temp_res_str)
    {
        printf("Недостаточно памяти для дешифровки строки.\n");
	exit(1);
    }
    char* res_str = temp_res_str;

    for (size_t i = 0; i <= num_el; ++i)
    {
	if (i == num_el)
	    res_str[i] = '\0';
	else
            res_str[i] = res_arr[i] - k;
    }

    return res_str;
}
