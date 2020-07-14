#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef uint32_t (*callback)(uint32_t);

extern uint32_t print_fact(uint32_t x, callback cb);;

uint32_t print_multiplier(uint32_t x) 
{
    printf("* %d ", x);
    return 0;
}

int main(uint32_t argc, char* argv[]) 
{
    if (argc > 2)
    {
        printf("Не правильно ввденено число для факторизации.\nEXE: ./fact 2001\n");
        return 1;
    }

    if (argc < 2)
    {
        printf("Не правильно ввденено число для факторизации.\nEXE: ./fact 2001\n");
        return 1;
    }

    uint32_t number = atoi(argv[1]);
    if (number == 0)
    {
        printf("Нельзя же факторизаровать нуль...\n");
        return 1;
    }
    if (argv[1][0] == '-')
    {
        printf("%d = -1 ", number);
        number *= -1;
    }
    else
    {
        printf("%d = 1 ", number);
    }
    print_fact(number, print_multiplier);
    printf("\n");
    return 0;
}