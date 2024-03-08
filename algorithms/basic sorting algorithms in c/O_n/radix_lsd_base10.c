#include "sorting.h"
#include <math.h>

t_count radix_sort_base10(int , int []);


t_count radix_sort_base10(int len, int arr[])
{
    /*
    기수 정렬 알고리즘(LSD 우선, 10진수): 
    1. 가장 낮은 자리수를 기준으로 stable sort한다
    2. 다음 자리수를 기준으로 1을 반복
    이때 음수는 음수끼리, 양수는 양수끼리 정렬해야 한다.

    시간복잡도:
    각 원소에 대해 비트 수만큼 반복하므로 T(n) = d * n이다. 이때 비트 수와 각 비트에서의 반복 횟수는 상수이므로
    선형의 시간복잡도를 갖게 된다.
    
    big-O notation에서 상수값은 무시되므로, 시간복잡도는 O(n)
    
    공간복잡도: 
    O(n)
    */

    int access = 0, write = 0;
    int temp_arr[len];

    // int 자료형이 32비트라고 가정하면, signed type의 경우 최상위 비트는 부호를 나타낸다.
    // 일단 음수들을 앞으로, 양수들을 뒤로 정렬한다. 
    int big_count = 0, minus_count = 0;
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
    
    // int 범위 내에서는 10진수로 표현할 수 있는 최대 자리수는 10이다.
    // 따라서 10번 반복하면 된다.
    for (int index = 1; index < 10; index++)
    {
        // pow 함수를 사용하지 않기 위해 base를 미리 계산
        int base = 1;
        for (int i=0; i < index-1; i++)
            base *= 10;
        
        // 해당 base에 대해 counting sort를 수행하기 위해, count 배열을 선언
        int count[10] = {0,};

        // 음수 ㄱㄱ
        // for(int i=0; i < minus_count; i++)
        // {
        //     access++;
        //     printf("%d\n", (arr[i] / base) % 10);
        //     count[(arr[i] / base) % 10]++;
        // }
        // for (int i=1; i < 10; i++)
        //     count[i] += count[i-1];
        // for(int i=minus_count-1; i >= 0; i--)
        // {
        //     access++;
        //     temp_arr[--count[(arr[i] / base) % 10]] = arr[i];
        // }

        // 양수 ㄱㄱ
        for(int i=minus_count; i < len; i++)
        {
            access++;
            count[(arr[i] / base) % 10]++;
        }
        for (int i=1; i < 10; i++)
            count[i] += count[i-1];
        for(int i=len-1; i >= minus_count; i--)
        {
            access++;
            temp_arr[--count[(arr[i] / base) % 10]] = arr[i];
        }

        // 이제 결과를 복사한다
        for (int i=0; i < len; i++, write++)
            arr[i] = temp_arr[i];
    }

    return (t_count){access, write};
}