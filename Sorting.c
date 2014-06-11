///**********************************************************************///
///********     	   		   Sorting Techniques     		   	 ********///
///********   Title: SelectionSort, InsertionSort, BubbleSort  	 ********///
///********                  QuickSort, MergeSort             	 ********///
///********                  			                 		 ********///
///********  		     [DataStructure Course, 2014]  			 ********///
///********		   Biomedical Engineering, Cairo University	 	 ********///
///**********************************************************************///
///*                                                             	    *///
///*   		  	 	Copyright by Ahmed Abdelhadi (C) 2014  	   	  	    *///
///*                                                               		*///
///*              	 Please report bugs & suggestions to              	*///
///*                   <ahmed.abdelhady@eng.cu.edu.eg>               	*///
///**********************************************************************///


#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

void selectionSort(int* array, int n);
void bubbleSort(int* array, int n);
void quickSort(int* array, int left, int right);
void insertionSort(int* array, int n);
void mergesort(int *a, int low, int high);
void merge(int *a, int low, int mid, int high);



int main ()
{
	
	int arr[MaxSize];
	
	/// Initialization of the array with random numbers 
	for(int i=0; i<MaxSize; i++)
	arr[i]=rand()%100;
	
	/// print all array elements before sorting
	for(int i=0; i<MaxSize; i++)
	printf("Arr[%d]=%d\n", i, arr[i]);
	
	/// call the sorting function
	selectionSort(arr, MaxSize);
	//~ insertionSort(arr, MaxSize);
	//~ bubbleSort(arr, MaxSize);
	//~ quickSort(arr, 0, MaxSize-1);
	//~ mergesort(arr, 0, MaxSize-1);
	
	
	/// print all array elements after sorting
	for(int i=0; i<MaxSize; i++)
	printf("SortedArr[%d]=%d\n", i, arr[i]);
	
	
}




/// Selection Sort
void selectionSort(int* array, int n)
{
	for(int x=0; x<n; x++)
	{
		int index_of_min = x;
	
		for(int y=x+1; y<n; y++)
		{
			if(array[index_of_min]>array[y])
			{
				index_of_min = y;
			}
		}

		int temp = array[x];
		array[x] = array[index_of_min];
		array[index_of_min] = temp;
	}
}



/// Bubble Sort
void bubbleSort(int* array, int n)
{
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n-1; y++)
		{
			if(array[y]>array[y+1])
			{
				int temp = array[y+1];
				array[y+1] = array[y];
				array[y] = temp;
			}
		}
	}
}



/// Insertion Sort
void insertionSort(int* array, int n)
{
	int temp;
	
	for (int i = 1 ; i <= n - 1; i++) 
	{
		for (int d=i ; d>0 ; d--)
		{
			if (array[d] < array[d-1])
			{
				temp = array[d];
				array[d] = array[d-1];
				array[d-1] = temp;
			}
		}
	}
}



/// Quick Sort
void quickSort(int* array, int left, int right)
{
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = array[left];
	
	while (left < right)
	{
		while ((array[right] >= pivot) && (left < right))
			right--;
		
		if (left != right)
		{
			array[left] = array[right];
			left++;
		}
		
		while ((array[left] <= pivot) && (left < right))
			left++;
		
		if (left != right)
		{
			array[right] = array[left];
			right--;
		}
	}
	
	array[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	
	if (left < pivot)
		quickSort(array, left, pivot-1);
	if (right > pivot)
		quickSort(array, pivot+1, right);
}



/// Merge Function that used inside the Merge Sort
void merge(int* array, int low, int mid, int high)
{
    int temp[high+1];
    int i = low, j = mid + 1, k = 0;
  
    while (i <= mid && j <= high) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
  
    while (j <= high)
        temp[k++] = array[j++];
  
    k--;
    while (k >= 0) {
        array[low + k] = temp[k];
        k--;
    }
}


/// Merge Sort
void mergesort(int *array, int low, int high)
{
    if (low < high) {
        int m = (high + low)/2;
        mergesort(array, low, m);
        mergesort(array, m + 1, high);
        merge(array, low, m, high);
    }
}
