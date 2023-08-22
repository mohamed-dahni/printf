#include <stdio.h>
#include <stdarg.h>

void variadicFunction(int num, ...) {
    va_list args;
    va_start(args, format);
    
    int i = 1;
    while (*format != '\0') {
        if (*format == 'd') {
            int arg = va_arg(args, int);
            printf("Argument %d: %d\n", i, arg);
        }
        format++;
        i++;
    }
    
    va_end(args);
}

int main(void)
{
    variadicFunction("ddddd", 10, 20, 30, 40, 50);

    return (0);
}
