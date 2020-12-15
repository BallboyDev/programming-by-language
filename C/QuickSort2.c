#include <stdio.h>
#include <stdlib.h>

#define max 10

void QuickSort(int A[], int start, int end){
	int index;
	if (start < end){
		
		index = partition(A, start, end);
		QuickSort(A, start, index - 1);
		QuickSort(A, index + 1, end);
	}
	
	else{
		return;
	}
}

int Partition(int A[], int start, int end){
	int pivot = A[end];
	int i;
	int index = start;
	int temp;
	
	for(i = start; i < end; i++){
		if(A[i] <= pivot){
			temp = A[i];
			A[i] = A[index];
			A[index] = temp;
			index++;
		}
	}
}

int main(){
	int A[max] = {40, 30, 100, 60, 80, 70, 90, 10, 20, 50}
	int i;
	
	printf("\n before sorting");
	for(i = 0; i < max; i++){
		printf("%d ", A[i]);
	}
	
	QuickSort(A, 0, max - 1);
}