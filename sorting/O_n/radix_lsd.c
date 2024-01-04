#include "sorting.h"

t_count radix_sort(int , int []);


t_count radix_sort(int len, int arr[])
{
    /*
    기수 정렬 알고리즘(LSD 우선): 
    1. 가장 낮은 자리수를 기준으로 stable sort한다
    2. 다음 자리수를 기준으로 1을 반복
    이때 음수는 음수끼리, 양수는 양수끼리 정렬해야 한다.

    시간복잡도:
    각 원소에 대해 비트 수만큼 반복하므로 T(n) = d * n이다. 이때 비트 수와 각 비트에서의 반복 횟수는 상수이므로
    선형의 시간복잡도를 갖게 된다. (이 구현에서 비트 수는 32, 각 비트에서 3회 반복하므로 d=66)
    
    big-O notation에서 상수값은 무시되므로, 시간복잡도는 O(n)
    
    공간복잡도: 
    O(n)
    */

    int access = 0, write = 0;
    int temp_arr[len];

    // 귀찮으니 2진수 기수정렬을 구현. 해당 자리의 비트가 1인 원소들의 개수를 세 준다.
    int big_count = 0, minus_count = 0;

    // int 자료형이 32비트라고 가정하면, signed type의 경우 최상위 비트는 부호를 나타낸다.
    // 일단 음수들을 앞으로, 양수들을 뒤로 정렬한다. 
    for(int i=0; i < len; i++)
    {
        access++;
        if (((arr[i] >> 31) & 0x1) == 1)
            big_count++;
    }
    minus_count = big_count;
    for(int i=0, big_index = 0; i < len; i++)
    {
        access++;
        if (((arr[i] >> 31) & 0x1) == 1)
            temp_arr[big_index++] = arr[i];
        else
            temp_arr[big_count++] = arr[i];
    }
    for (int i=0; i < len; i++, write++)
        arr[i] = temp_arr[i];

    // 음수끼리 비교, 양수끼리 비교해주어야 한다.
    for(int index = 0; index <= 31; index++)
    {
        // 음수 ㄱㄱ
        big_count = 0;
        for(int i=0; i < minus_count; i++)
        {
            access++;
            if (((arr[i] >> (index - 1)) & 0x1) == 1)
                big_count++;
        }
        for(int i=0, big_index = 0, small_index = 0; i < minus_count; i++)
        {
            access++;
            if (((arr[i] >> (index - 1)) & 0x1) == 1)
                temp_arr[minus_count - big_count + big_index++] = arr[i];
            else
                temp_arr[small_index++] = arr[i];
        }

        // 양수 ㄱㄱ
        big_count = 0;
        for(int i=minus_count; i < len; i++)
        {
            access++;
            if (((arr[i] >> (index - 1)) & 0x1) == 1)
                big_count++;
        }
        for(int i=minus_count, big_index = 0, small_index = 0; i < len; i++)
        {
            access++;
            if (((arr[i] >> (index - 1)) & 0x1) == 1)
                temp_arr[len - big_count + big_index++] = arr[i];
            else
                temp_arr[minus_count + small_index++] = arr[i];
        }

        // 이제 결과를 복사한다
        for (int i=0; i < len; i++, write++)
            arr[i] = temp_arr[i];
    }

    return (t_count){access, write};
}