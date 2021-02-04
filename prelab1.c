#include <stdio.h>
#include <stdlib.h>

/*Prelab Week 1 Spring Semester January 2021, Kent Studer - CS 2050*/

int findLEQ(float* array, int arraySize, float num, float* result); 
float* createRandomArray(int arraySize);
void printArray(float* array, int arraySize);

//This function will take an array of floats and a user-provided number (float) and provides the user with the sum of
//the largest number in the array that is less than the user-provided number and the smallest number that is
//greater than the user provided number.
//Inputs:
//	array: array of floats
//	arraySize: size of array
//	num: user-provided number
//	result: a float pointer that will hold the sum 
//Outputs:
//	An error code, -1 for failure and a 1 for success
int findLEQ(float* array, int arraySize, float num, float* result)
{	
	float min;
	float max;

	min = max = array[0];

	/*This determines our maximum and minimum values so that we will know if our query number is valid*/
	for(int i = 1; i < arraySize; i++)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	printf("The max is %.2f and the min is %.2f\n", max, min);

	if(num >= min && num <= max) //if our user-provided number is within bounds we will loop through again
	{
		float high;
		float low;

		high = max;
		low = min;

		for(int i = 0; i < arraySize; i++)
		{
			if(array[i] < num && array[i] > low)
			{
				low = array[i];
			}
			if(array[i] > num && array[i] < high)
			{
				high = array[i];
			}
		}
	
		printf("The new low is %.2f\n", low);
		printf("The new high is %.2f\n", high);

		*result = high + low;
		return 1;
	}
	else //the number is not within bounds we will return -1 for failure
	{
		printf("The provided number is not within bounds\n");
		return -1;
	}

	return 0;
}
//This function will take an empty array with a specified size and populate it with random float numbers
//Inputs:
//	arraySize: size of array of type int
//Outputs:
//	A populated array with given size parameter
float* createRandomArray(int arraySize)
{
	float *array;
	array = malloc(arraySize * sizeof(float));
	if(array == NULL)
	{
		printf("ERROR: Malloc Failed\n");
		return NULL;
	}
	else
	{
		for(int i = 0; i < arraySize; i++)
		{
			array[i] = (rand() % 20);
		}
		return array;
	}
	return 0;
}
//This function will simply print out the array for analysis to ensure the sum calculation is being performed
//properly
//Input:
//	array: an array of random floats
//	arraySize: size of said array
//Outputs:
//	void output but will print the array contents
void printArray(float* array, int arraySize)
{
	for(int i = 0; i < arraySize; i++)
	{
		printf("Array[%d] = %.2f\n", i, array[i]);
	}
}
int main(void)
{
	float *arr = createRandomArray(10);

	printArray(arr, 10);
	
	float result;
	
	printf("The user defined number is 10.1\n");

	findLEQ(arr, 10, 10.1, &result);
	printf("The specified sum is %.2f\n", result);
}


