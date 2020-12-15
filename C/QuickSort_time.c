#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000
 
void swap(int* a, int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
 
void quick_sort(int* array, int start, int end){
 
    if(start>=end) return;
 
    int mid=(start+end)/2;
    int pivot=array[mid];
 
    swap(&array[start],&array[mid]);
 
    int p=start+1,q=end;
 
    while(1){
        while(array[p]<=pivot){ p++; }
        while(array[q]>pivot){ q--; }
 
        if(p>q) break;
 
        swap(&array[p],&array[q]);
    }
 
    swap(&array[start],&array[q]);
 
    quick_sort(array,start,q-1);
    quick_sort(array,q+1,end);
 
}
 
int main(void){
    int array[MAX];
    int i;
	char c;
	clock_t start, finish;
	double duration;
	FILE* in;
	
	in = fopen("rand.txt", "r");
	for(i = 0; i < MAX; i++){
		fscanf(in, "%d", &array[i]);
		printf("%d ", array[i]);
	}
	
	printf("\nstart sort(y/n)? ");
	scanf("%c", &c);
	if(c == "n" || c == "N"){
		exit(1);
		printf("finish");
	}
	
	start = clock();
 
    quick_sort(array, 0, sizeof(array)/sizeof(int)-1);
 
    for(i = 0; i < MAX; i++)
		printf("(%d, %d)\n", i+1, array[i]);
	
	finish = clock();
	
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n time = %f", duration);
	
	fclose(in);
 
    return 0;
}