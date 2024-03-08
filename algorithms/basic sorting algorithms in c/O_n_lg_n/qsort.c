#include "sorting.h"

t_count quick_sort(int , int []);
static t_count quicksort_main(int [], int , int );


t_count quick_sort(int len, int array[])
{
	/*
	퀵 정렬 알고리즘:
	1. 피벗을 잡는다.
	2. 피벗보다 작은 원소들은 피벗 앞으로 / 큰 원소들은 피벗 뒤로 이동시킨다.
	-> 각 재귀 실행마다 피벗 앞뒤로 대소가 일정하게 된다.
	이 과정을 배열의 크기가 1이 될 때 까지 분할하며 반복한다.

	시간복잡도:
	평균 O(n lg n)
	최악 O(n^2)

	공간복잡도:
	평균 O(lg n)
	최악 O(n)
	*/
	return quicksort_main(array, 0, len - 1);
}


static t_count quicksort_main(int array[], int low, int high)
{
	int access = 0, write = 0;
	int middle, pivot;
	int pivot_left = low, pivot_right = high;

	if (low >= high) 
		return (t_count){0, 0};
	
	// 배열의 가장 앞 원소를 피봇으로 설정한다.
	pivot = array[pivot_left];

	// 피봇을 기준으로 정렬한다
	for (;;)
	{
		access++;
		// 피봇 우측에 피봇보다 작은 원소가 있으면 피봇이 있던 자리로 이동
		while (pivot_left < pivot_right && pivot <= array[pivot_right])
		{
			access++;
			pivot_right--;
		}
		if (pivot_left >= pivot_right)
			break ;

		access += 2;
		write++;
		array[pivot_left++] = array[pivot_right];

		access++;
		// 피봇 좌측에 피봇보다 큰 원소가 있으면 (위에서 이동된) 원소가 있던 자리로 이동
		while (pivot_left < pivot_right && array[pivot_left] <= pivot)
		{
			access++;
			pivot_left++;
		}
		if (pivot_left >= pivot_right) 
			break ;
	
		access++;
		write++;
		array[pivot_right--] = array[pivot_left];
	}
	// 최종 위치로 피봇을 이동
	write++;
	array[pivot_right] = pivot;
	middle = pivot_right;

	// --> 좌변에는 피봇보다 작은 원소만이, 우변에는 피봇보다 큰 원소만이 있다
	// 각각을 다시 정렬한다.
	t_count temp = quicksort_main(array, low, middle - 1);
	access += temp.access;
	write += temp.write;
	temp = quicksort_main(array, middle + 1, high);
	access += temp.access;
	write += temp.write;

	return (t_count){access, write};
}