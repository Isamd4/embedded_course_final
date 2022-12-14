#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../include/common/memory.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
   int i=0;
    if (data<0){
        *(ptr + i)='-';
        i++;
        data=data* -1;
    }
   while(data!=0){
    *(ptr+i)= (data%base)+'0';
    data=data/base;
    i++;
   }
   i++;
   *(ptr+i)='\0';
   my_reverse(ptr,i-1);
   return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int i=0;
    int flag=0;
    int32_t value=0;
    if (*(ptr+i)=='-'){
        flag=1;
        i++;
    }
    for(int j=i;j<digits-1;j++){
        value= value * base + *(ptr+j) -'0';
    }
    if(flag==1){
        value =value*-1;
    }
    return value;
}