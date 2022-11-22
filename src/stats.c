/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief it is where the implementation of the project
 *
 * <Add Extended Description Here>
 *
 * @author Muhammad Isa
 * @date 28/08/2022
 *
 */

#include <stdio.h>
#include "stats.h"
#include "platform.h"
/* Size of the Data Set */
#define SIZE (40)

// void main() {

//   unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                               114, 88,   45,  76, 123,  87,  25,  23,
//                               200, 122, 150, 90,   92,  87, 177, 244,
//                               201,   6,  12,  60,   8,   2,   5,  67,
//                                 7,  87, 250, 230,  99,   3, 100,  90};

//   /* Other Variable Declarations Go Here */
//   unsigned int length=sizeof(test)/sizeof(test[0]);
//   /* Statistics and Printing Functions Go Here */
//   puts("------STATISTICS BEFORE SORTING---");
//   print_statistics(test,length);
//   puts("--------------------");
//   puts("\n---------Content of the array Before sorting----------- ");
//   print_array(test,length);
//   puts("--------------------");
//   puts("\n---------Content of the array After sorting----------- ");
//   sort_array(test,length);
//   print_array(test,length);
//   puts("\n------STATISTICS AFTER SORTING---");
//   print_statistics(test,length);
// }

/* Add other Implementation File Code Here */
void print_array(unsigned char arr[], unsigned int length)
{
#ifdef VERBOSE
  int i = 0;
  for (i = 0; i < length; i++)
  {
    PRINTF("index %d : %u\n", i, *(arr + i));
  }
#endif
}
unsigned int find_mean(unsigned char arr[], unsigned int length)
{
  unsigned int sum = 0;
  int i = 0;
  for (i = 0; i < length; i++)
  {
    sum += (int)*(arr + i);
  }
  return sum / length;
}
unsigned int find_median(unsigned char arr[], unsigned int length)
{
  int index = length / 2;
  unsigned int median;
  if (length % 2 != 0)
  {
    return (int)*(arr + index);
  }
  else
  {
    median = (int)*(arr + index - 1) + (int)*(arr + index);
    return median / 2;
  }
}
unsigned char find_maximum(unsigned char arr[], unsigned int length)
{
  int i = 0;
  unsigned char max = *arr;
  for (i = 0; i < length; i++)
  {
    if (max < *(arr + i))
    {
      max = *(arr + i);
    }
  }
  return max;
}
unsigned char find_minimum(unsigned char arr[], unsigned int length)
{
  int i = 0;
  unsigned char min = *arr;
  for (i = 0; i < length; i++)
  {
    if (min > *(arr + i))
    {
      min = *(arr + i);
    }
  }
  return min;
}
void sort_array(unsigned char arr[], unsigned int length)
{
  int i = 0, j = 0;
  unsigned char cpy;
  for (i = 0; i < length; i++)
  {
    for (j = 0; j < length; j++)
    {
      if (arr[i] >= arr[j])
      {
        cpy = arr[j];
        arr[j] = arr[i];
        arr[i] = cpy;
      }
    }
  }
}
void print_statistics(unsigned char arr[], unsigned int length)
{
  printf("the maximum number  is %d \n", find_maximum(arr, length));
  printf("the minimum number  is %d \n", find_minimum(arr, length));
  printf("the mean is %d \n", find_mean(arr, length));
  printf("the median is %d \n", find_median(arr, length));
}