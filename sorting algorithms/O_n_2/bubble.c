#include "sorting.h"

t_count bubble_sort(int , int []);

t_count bubble_sort(int len, int array[])
{
	/*
	버블 정렬 알고리즘: 
	1. 첫 원소(a[0])와 다음 원소(a[1])를 비교해 정렬한다. 
	2. 다음 원소(a[1])와 그 다음 원소(a[2])를 비교해 정렬한다. 
	3. 이 과정을 마지막 원소(a[n-1])까지 반복한다.
	--> 마지막 원소(a[n-2])에는 배열에서 가장 큰 원소가 들어있다.

	4. 1 ~ 3을 마지막 원소 이전까지(a[n-2]) 반복한다.
	--> 마지막 원소 이전(a[n-2]에는 두 번째로 큰 원소가 들어있다.

	5. 4를 첫 원소까지(a[0]) 반복한다. 

	시간복잡도:
	자료와 상관없이 n-1 + n-2 + ... + 1, 즉 sigma_1_n-1번 비교연산을 수행한다.
	따라서 O(n^2)의 시간복잡도를 가진다.

	공간복잡도:
	두 원소를 교환하는(swap) 과정에서 하나의 임시 변수가 필요한 것을 제외하면 추가적인 메모리가 요구되지 않는다.
	따라서 O(1)의 공간복잡도를 가진다. 
	*/
	int access = 0, write = 0;
	int	temp;

	for (int i = (len - 1); i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			access++;
			if (array[j] > array[j + 1])
			{
				access += 2;
				write += 2;
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}

	return (t_count){access, write};
}