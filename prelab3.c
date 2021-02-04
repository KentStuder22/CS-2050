#include <stdio.h>
#include <stdlib.h>

double* createDoubleArray(int, int);
void freeDoubleArray(double*, int);

int main(void)
{
	double* rainfall;

	FILE* fp = fopen("rainfall.txt", "r");
	if(!fp)
	{
		printf("ERROR: Cannot open specified file\n");
		return -1;
	}

	rainfall = createDoubleArray(1900, 2000);
	for(int i = 1900; i < 2000; i++)
	{
		fscanf(fp, "%lf", &(rainfall[i]));
	}

	double sum = 0.0;

	for(int j = 1900; j < 1910; j++)
	{
		sum += rainfall[j];
	}

	printf("Avg rainfall in the 1900s: %lf\n", sum / 10);

	freeDoubleArray(rainfall, 1900);
}
//This function will create an array dynamically with the passed parameters as the starting and 
//ending index, allows for indexes to start at something other than 0
//Inputs:
//	minIndex: the minimum index that will be treated as array[0]
//	maxIndex: the maximum index that will be treated as array[size-1]
//Outputs:
//	A populated double array that has user defined bounds
double* createDoubleArray(int minIndex, int maxIndex)
{
	double* arr;
	double range = maxIndex - minIndex + 1;

	arr = malloc(range*sizeof(double));
	if(arr == NULL)
	{
		printf("ERROR: Malloc Failed\n");
		return NULL;
	}
	else
	{
		arr = arr + minIndex;
		for(int i = 0; i < range; i++)
		{
			arr[i] = 0.0;
		}
	}
	return arr;
}
//This function will free the array by subtracting the minIndex using pointer arithmetic so we free
//the right location in memory
//Inputs:
//	array = populated double array
//	minIndex = the "[0]" index specified in calling
//Outputs:
//	The array will be freed appropriately
void freeDoubleArray(double* array, int minIndex)
{
	if(array == NULL)
	{
		printf("ERROR: No array to free\n");
		return;
	}
	else
	{
		free(array - minIndex);
	}
}

