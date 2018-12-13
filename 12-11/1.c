#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>  
#include<stdlib.h>  
#include<time.h>
#include<math.h>  
void px(int a[], int n)
{
	int i, temp, j;
	for (i = 0; i<n; i++)
	{
		for (j = i; j<n; j++)
		{
			if (a[i] <= a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	int sum = 0;
	int n, i, j, k, l;
	int a[105], b[105];
	clock_t begin,end;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	begin=clock();

	px(a, n);
	for (i = n - 1; i>0; i--)
	{
		sum += a[i] + a[i - 1];
		a[i - 1] = a[i] + a[i - 1];
		px(a, i);
		for (k = 0; k<i; k++)
		{
			b[k] = a[k];
		}
		memset(a, 0, sizeof(a));
		for (j = 0; j<i; j++)
		{
			a[j] = b[j];
		}
		memset(b, 0, sizeof(b));
	}
	printf("%d\n", sum);
	end=clock();
	printf("%0.16f\n",(double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}
