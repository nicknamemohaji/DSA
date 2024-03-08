#include "sorting.h"

t_count insertion_sort(int , int []);

t_count insertion_sort(int len, int array[])
{
	/*
	삽입 정렬 알고리즘:
	0. 첫 원소(arr[0])는 정렬된 것으로 간주한다.

	1. 두 번째 원소(arr[1])를 첫 원소(arr[0])와 비교해 정렬한다.
	--> 첫 두 원소는 정렬된 상태이다.

	2. 세 번째 원소(arr[2])를 두 번째 원소와 비교해 만약 더 작다면 정렬한다.
	3. 만약 세 번째 원소(* 였던 것)가 두 번째(* 였던 것) 원소보다 작다면 세 번째 원소(* 였던 것)을 첫 원소와 비교해 정렬한다.
	--> 첫 세 원소는 정렬된 상태이다.

	4. 2~3을 마지막 원소(arr[n-1])까지 반복한다. 

	시간복잡도:
	최적의 경우(이미 정렬된 상태)는 n번의 비교연산, 최악의 경우(역순으로 정렬된 상태)는 sigma_1_n-1번 비교연산을 수행한다.
	삽입정렬은 평균적으로 O(n^2)의 시간복잡도를 가진다.

	공간복잡도:
	O(1)의 공간복잡도를 가진다. 
	*/
	int access = 0, write = 0;
	int temp;

	for (int i = 0; i < (len - 1); i++)
	{
		access += 2;
		for (int j = i; j >= 0 && array[j] > array[j + 1]; j--)
		{
			access += 4;
			write += 2;
			temp = array[j + 1];
			array[j + 1] = array[j];
			array[j] = temp;
		}
	}

	return (t_count){access, write};
}