#include "sorting.h"

t_count	merge_sort(int , int []);

t_count	merge_sort(int len, int arr[])
{
	/*
	병합 정렬 알고리즘: 
	1. 배열을 절반으로 나누고, 각각을 병합 정렬한다.
	-> 각각의 배열은 정렬된 상태이다.
	2. 각 배열의 처음끼리 비교하면서 배열을 합친다.

	재귀적으로 정렬이 일어나는 것에 주목하자.

	시간복잡도:
	한 번의 병합 정렬을 보자.
	- 절반의 크기만큼(n /2)의 병합 정렬을 두 번 실행하고
	- 두 배열을 합치기 위해 n * k번의 연산이 필요하다.
	따라서 T(n) = 2 * T(n / 2^1) + k * n이다.

	이때 T(n / 2^1) = 2 * T(n / 2^2) + k * (n / 2^1)이므로, 
	T(n) = (2^2) * T(n / 2^2) + 2 * k * n이고, 이는 n / 2^m = 1일 때 까지 반복된다.

	n / 2^m = 1이 되도록 하는 m = log_2_n이므로, 
	T(n) = 2^m * T(1) + k * m * n
	= n + k * log_2_n * n
	따라서 O(n lg n)의 시간복잡도를 가진다.

	공간복잡도:
	배열을 반으로 나누어 정렬하기 위해서 같은 크기만큼의 임시 배열이 필요하다. 임시 배열은 재귀 스택을 따라, n에서 n/2, ... 1까지 필요하다.
	sigma k=1 to log_2_n of n / (2^k) = n - 1.
	따라서 O(n)의 공간복잡도를 가진다. 
	*/
	int access = 0, write = 0;
	int lside_size = len / 2, rside_size = len / 2 + len % 2;
	int lside[lside_size], lside_idx = 0;
	int rside[rside_size], rside_idx = 0;

	// 재귀의 종료조건
	if (len <= 1)
		return (t_count){0, 0};

	// 배열을 반으로 나눈다
	for (int i=0; i<lside_size; i++, access++)
		lside[i] = arr[i];
	for (int i=0; i<rside_size; i++, access++)
		rside[i] = arr[i + lside_size];
	
	// 각각에 대해 분할정렬을 반복한다
	t_count temp = merge_sort(lside_size, lside);
	access += temp.access;
	write += temp.write;
	temp= merge_sort(rside_size, rside);
	access += temp.access;
	write += temp.write;

	// 배열을 합친다
	for (int i=0; i<len; i++)
	{
		write++;
		// 어느 한 쪽에서 다 꺼낸 경우
		if (lside_idx >= lside_size)
			arr[i] = rside[rside_idx++];
		else if (rside_idx >= rside_size)
			arr[i] = lside[lside_idx++];

		// 왼쪽 배열에 더 작은 원소가 있는 경우
		else if (lside[lside_idx] < rside[rside_idx])
			arr[i] = lside[lside_idx++];
		// 오른쪽 배열에 더 작은 원소가 있는 경우
		else
			arr[i] = rside[rside_idx++];
	}
	return (t_count){access, write};
}