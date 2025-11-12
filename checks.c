#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static int check_num_el(int argc)
{
    if (argc < 6 || argc % 3 != 0)
    {
        printf("Введено некорректное количество аргументов.\n");
	return 1;
    }
    return 0;
}


static int is_int(char* str_int)
{
    char* endptr = NULL;
    strtol(str_int, &endptr, 10);
    return *endptr == '\0';
}


static int is_correct_op(char* str_op)
{
    char* str_ops = "+-*%";
    return strlen(str_op) == 1 && strstr(str_ops, str_op) != NULL;
}


static int check_order(int argc, char** argv)
{
    for (int i = 1; i < argc - 4; i += 3)
    {
        if (!(is_int(argv[i]) && is_correct_op(argv[i + 1]) && is_int(argv[i + 2])))
	{
	    printf("Аргументы введены в неправильном порядке или не являются целыми числами/знаками мат. операций/флагами.\n");
	    return 1;
	}	
    }
    return 0;
}


static int check_flag_val(int argc, char** argv)
{
    if (strcmp(argv[argc - 2], "-k") != 0)
    {
        printf("Неверно указан флаг.\n");
	return 1;
    }

    if (!is_int(argv[argc - 1]))
    {
        printf("Ключ указан неверно.\n");
	return 1;
    }
    return 0;
}


void check_input(int argc, char** argv)
{
    if (check_num_el(argc) || check_order(argc, argv) || check_flag_val(argc, argv))
        exit(1);
}
