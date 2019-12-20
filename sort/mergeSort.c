#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *buf;
void Merge(int *w_array, int left, int mid, int right);

void rMergeSort(int *w_array, int left, int right) /* 재귀적 합병 정렬 */
{
	int mid;
	mid = (left + right) / 2;			

	if (left < right)		//더이상쪼갤게없으면 재귀탈출
	{
		rMergeSort(w_array, left, mid);						//분할하려고 한쪽을 왼쪽,중앙값으로 분할
		rMergeSort(w_array, mid + 1, right);				// 상동, 한쪽을 중앙+1 오른값으로 분할
		Merge(w_array, left, mid, right);					//합병
	}
	return;
}
void Merge(int *w_array, int left, int mid, int right) /* 실제로 정렬하는 Merge 함수*/
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)			//왼쪽분할한값이 mid값에 오고 오른쪽분할한mid+1값이 right값에 올때까지 (원래배열의끝까지)
	{
		if (w_array[i] <= w_array[j]) {				//왼쪽arr와 오른쪽arr중 작은값을 넣기
			buf[k] = w_array[i];
			k++;
			i++;
		}
		else {
			buf[k] = w_array[j];
			k++;
			j++;
		}
	}

	while (i <= mid)		//인덱스상 남은게없으면 다 집어넣기
		buf[k++] = w_array[i++];

	while (j <= right)		//인덱스상 남은게없으면 다 집어넣기
		buf[k++] = w_array[j++];

	for (i = left; i <= right; i++)		//정렬된buf값을 원래쓰던 arr에 집어넣기
	{
		w_array[i] = buf[i];
	}

}
void MergeSort(int *w_array, int n) /* 재귀적 합병정렬 호출함수*/
{
	rMergeSort(w_array, 0, n - 1);  
	return;
}
void printHeap(int *w_array, int n) /* 배열출력함수 */
{
	int i;
	for (i = 0;i < n;i++)printf(" %d", w_array[i]);
	printf("\n");
}

void main(void)
{
	int *arrA;
	int n, i;
	scanf("%d", &n);

	arrA = (int *)malloc(sizeof(int)*n);
	buf = (int *)malloc(sizeof(int)*n);

	for (i = 0;i < n;i++)
	{
		scanf("%d", &arrA[i]);
	}
	MergeSort(arrA, n);
	printHeap(arrA, n);
}
