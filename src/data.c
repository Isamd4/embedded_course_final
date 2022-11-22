#include "data.h"
#include "memory.h"
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    uint8_t i = 0;
    if (data < 0)
    {
        data = data * -1;
        *(ptr + i) = '-';
        i++;
    }
    while (data > 0)
    {
        *(ptr + i) = '0' + (data % base);
        data = data / base;
        i++;
    }
    i++;
    *(ptr + i) = '\0';
    my_reverse(ptr, i - 1);
    return i;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    uint8_t j = 0;
    int flag = 0;
    int32_t value = 0;

    for (j = j; j < digits - 1; j++)
    {

        value = value * base + *(ptr + j) - '0';
        if (*(ptr + j + 1) == '-')
        {
            flag = 1;
            j++;
        }
    }

    if (flag == 1)
    {
        value = value * -1;
    }
    return value;
}