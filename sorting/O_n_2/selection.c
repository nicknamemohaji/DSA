#include "sorting.h"

t_count selection_sort(int , int []);

t_count selection_sort(int len, int array[])
{
	/*
	선택 정렬 알고리즘: 
	1. 배열의 처음부터 끝까지 선회하면서 가장 작은 원소를 찾는다.
	2. 배열의 처음과 가장 작은 원소를 교환한다. 
	--> 배열의 처음(a[0])에 가장 작은 원소가 있다.

	3. 두 번째 위치부터 끝까지 1~2를 반복한다. 
	--> 배열의 두 번째(a[1])에 두 번째로 작은 원소가 있다.
	
	4. 3을 마지막 원소(a[n-1])까지 반복한다.

	시간복잡도:
	자료와 상관없이 n-1 + n-2 + ... + 1, 즉 sigma_1_n-1번 비교연산을 수행한다.
	따라서 O(n^2)의 시간복잡도를 가진다.

	공간복잡도:
	가장 작은 원소의 위치를 기억하는 곳과 교환하는 곳, 총 두 곳 외에는 추가적인 공간이 필요하지 않다.
	따라서 O(1)의 공간복잡도를 가진다. 
	*/
	int access = 0, write = 0;
	int min_pos, temp;

	for (int i = 0; i < len; i++)
	{
		min_pos = i;
		for (int j = i; j < len; j++)
		{
			access += 2;
			if (array[min_pos] > array[j])
				min_pos = j;
		}
		access += 2;
		write += 2;
		temp = array[min_pos];
		array[min_pos] = array[i];
		array[i] = temp;
	}

	return (t_count){access, write};
}
