#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 100
int compare(const void* x,const void* y)
{
	return *((int*)x)-*((int*)y);
}
int Huffman(int* arr, int n)
{
	if (n == 2)
		return arr[0] + arr[1];
	else{
		qsort(arr, n, sizeof(int), compare);
		arr[1] += arr[0];
		int tmp = arr[1];
		return tmp+Huffman(arr+1,n-1);
	}
}

int main()
{
	int arr[M] = {0};
	int n;
	int i;
	clock_t begin,end;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &arr[i]);
	begin = clock();
	printf("%d\n",Huffman(arr, n));
	end = clock();
	printf("%0.16f\n", (double)(end - begin) / CLOCKS_PER_SEC);
	return 0;
}
