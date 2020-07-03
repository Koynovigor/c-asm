#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef uint32_t (*callback)(uint32_t);

extern uint32_t do_higload(uint32_t x, callback cb);;

uint32_t process_results(uint32_t x) 
{
    printf("* %d ", x);
    return 0;
}

int main(uint32_t argc, char* argv[]) 
{
    if (argc > 2)
    {
        perror("too many arguments");
        return 1;
    }

    if (argc < 2)
    {
        perror("too few arguments");
        return 1;
    }

    uint32_t number = atoi(argv[1]);
    if (number == 0)
    {
        perror("bad argument");
        return 1;
    }
    
    printf("%d = 1 ", number);
    do_higload(number, process_results);
    printf("\n");
    return 0;
}