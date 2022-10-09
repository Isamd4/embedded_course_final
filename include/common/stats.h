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
 * @file stats.h
 * @brief This defines the functions for the implementation of the project
 *
 * <Add Extended Description Here>
 *
 * @author Muhammad Isa
 * @date 28/08/2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief prints out the mean median maximum and minum number of an usinged array char
 *
 * This function takes an usngined array of char as an input. This will then
 * pass it into the subfunctions of then prints the corresponding results.
 *
 * @param array of unsigned char 
 * @param lenght of the array as unsigned int
 *
 * @return it return nothing as it is a void funtion
 */
void print_statistics(unsigned char arr[],unsigned int length);

/**
 * @brief prints out all the elements of an unsigned char array
 *
 * This function takes an usngined array of char and its length as input
 * then it iterates the through the array and prints each element 
 *
 * @param array of unsigned char 
 * @param lenght of the array as unsigned int
 *
 * @return it return nothing as it is a void funtion
 */
void print_array(unsigned char arr[], unsigned int length);

/**
 * @brief find the median of an unsigned char array and returns the value
 *
 * This function takes an usngined array of char and its length as input
 * then it finds the median and then returns it
 *
 * @param array of unsigned char 
 * @param lenght of the array as unsigned int
 *
 * @return it returns an integer 
 */
unsigned int find_median(unsigned char arr[],unsigned int length);

/**
 * @brief finds the mean of an unsigned char array and returns the value
 *
 * This function takes an usngined array of char and its length as input
 * then it finds the mean and then returns it
 *
 * @param array of unsigned char 
 * @param  lenght of the array as unsigned int
 *
 * @return it returns an integer 
 */
unsigned int find_mean(unsigned char arr[],unsigned int length);

/**
 * @brief finds the maximum element in an  unsigned char array and returns the value
 *
 * This function takes an usngined array of char and its length as input
 * then it finds the maxiumum number and then returns it
 *
 * @param array of unsigned char 
 * @param lenght of the array as unsigned int
 *
 * @return it returns an unsigned char
 */
unsigned char find_maximum(unsigned char arr[],unsigned int length);

/**
 * @brief finds the minimum element in an  unsigned char array and returns the value
 *
 * This function takes an usngined array of char and its length as input
 * then it finds the minimum number and then returns it
 *
 * @param array of unsigned char 
 * @param lenght of the array as unsigned int
 *
 * @return it returns an unsigned char
 */
unsigned char find_minimum(unsigned char arr[],unsigned int length);

/**
 * @brief sorts an  unsigned char array in a descending order
 *
 * This function takes an usngined array of char and its length as input
 * then it swaps the ith position with n-ith postion
 *
 * @param array of unsigned char 
 * @param lenght of the array as unsigned int
 *
 * @return it returns an nothings
 */
void sort_array(unsigned char arr[],unsigned int length);
#endif /* __STATS_H__ */
