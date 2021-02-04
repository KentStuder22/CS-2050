#include <stdio.h>
#include <stdlib.h>

float* readFloatFileIntoArray(FILE* fptr, int* length);
void freeFloatArray(float** arr);

int main(void)
{
	FILE* ptr = fopen("numbers.txt", "r");
	if(!ptr)
	{
		printf("The file was not successfully opened\n");
		return -1;
	}
	int length;
	float* array = readFloatFileIntoArray(ptr, &length);
	for(int i = 0; i < length; i++)
	{
		printf("Array[%d] = %.2f\n", i, array[i]);
	}

	freeFloatArray(&array);

	if(array == NULL)
	{
		printf("Null set successful\n");
	}

}

//This function will allocate and return a float array containing values pulled from a file. The
//first value in the file will be an integer stating the number of floats that follows.
//Inputs:
//	FILE fptr: file pointer for opening and storing float values
//	length: int pointer that we will store the length of the array for the calling program to use
//Outputs:
//	A populated float array and a changed length variable for the calling
float* readFloatFileIntoArray(FILE* fptr, int* length)
{
	int size;
	float* arr;
	
	/*Scanning through the first integer and storing it in our size variable*/
	fscanf(fptr, "%d\n", &size);

	/*Allocating memory based on size indicated in file*/
	arr = malloc(size*sizeof(float));
	if(arr == NULL)
	{
		printf("ERROR: Malloc Failed\n"); //error handling
		return NULL;
	}
	else
	{
		for(int i = 0; i < size; i++) //Looping through the array
		{
			fscanf(fptr, "%f\n", &(arr[i])); //scanning each float into the array one by one
		}
	}
	*length = size; //setting our length pointer equal to the size indicated for calling program usage
	return arr;
}

//This function will free the array and will also set the user's array variable/pointer to NULL to 
//avoid accidentally referencing freed memory. 
//Inputs:
//	arr: a pointer to an array of floats
//Outputs:
//	the array will be freed, and variable set to NULL
void freeFloatArray(float** arr)
{
	if(arr == NULL) //error checking
	{
		return;
	}
	else
	{
		free(*arr); //we dereference here and for the NULL set because we are passing a reference to the array, not the array itself 
		*arr = NULL;
	}

}

