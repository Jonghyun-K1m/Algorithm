#include<stdio.h> 
#include<time.h> 
#include<stdlib.h> 
int n = 100;

int find_random_pivot(int *w_array,int lefts, int rights) /* */
{


	int count = 0, i, count2 = 0, setRand = 0,randn;
	int rand_out;
	srand((unsigned)time(NULL));
	randn = rand();
	for (i = lefts;i < rights;i++) {
		count++;
	}
	setRand = randn%count;

	for (i = lefts;i < rights;i++)
	{
		count2++;
		if (count2 == setRand)
		{
			rand_out = i;
			break;
		}
		else rand_out = rights;
	}
	return rand_out;
}

int inPlaceQuickSort(int *w_array, int left, int right) /* 재귀적 제자리 퀵정렬함수 */
{
	int k, newnum;					
	if (left >= right)
		return 0;
	k = find_random_pivot(w_array,left,right);

		newnum = inPlacePartition(w_array, left, right, k);
		inPlaceQuickSort(w_array, left, newnum - 1);
		inPlaceQuickSort(w_array, newnum + 1, right);
	
}



void printHeap(int *A, int n)
/* 1부터n까지의 힙프린트함수 */
{
	int i;
	for (i = 0;i < n;i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}
int inPlacePartition(int *w_array, int left, int right, int k) /* 오름차순 퀵 정렬 함수*/
{
	int i, j, temp, pivot;

	temp = 0;
	pivot = w_array[k];					//피봇숨기기

	temp = w_array[k];				
	w_array[k] = w_array[right];
	w_array[right] = temp;

	i = left;
	j = right - 1;
	while (i <= j)			//더이상할필요없게만드는조건
	{
		while (i <= j && w_array[i] <= pivot)		//피봇값보다 큰애들 색출
			i = i + 1;
		while (j >= i && w_array[j] >= pivot)		//피봇값보다 작은애들색출
			j = j - 1;
		if (i < j)			//스왑
		{
			temp = w_array[i];
			w_array[i] = w_array[j];
			w_array[j] = temp;
		}
	}

	temp = w_array[i];			//피봇스왑
	w_array[i] = w_array[right];
	w_array[right] = temp;
	return i;
}

int main(void)
{
	int *A;

	scanf("%d", &n);
	A = (int *)malloc(sizeof(int)*n);

	
	for (int i = 0;i < n;i++) {
		scanf("%d", &A[i]);
	}
	
	inPlaceQuickSort(A, 0, n - 1);
	printHeap(A, n);
	return 0;
}
