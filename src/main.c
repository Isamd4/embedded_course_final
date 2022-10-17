#include <stdio.h>
#include "../include/common/course1.h"
// #include "../include/common/memory.h"
// #include "../include/common/data.h"

int main(){
    #ifdef COURSE1
    printf("Hello its printing \n");
    course1();
    #endif
    return 0;
}