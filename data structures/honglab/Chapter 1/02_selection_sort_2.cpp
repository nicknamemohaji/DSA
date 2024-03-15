#include <iostream>


bool CheckSorted(int* arr, int size);
void Print(int arr[], int size);

int main(void)
{
    std::cout << std::boolalpha;
    
    //////////////////////////// 가장 작은 수 찾기 ////////////////////////////
    {
        int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
        int size = sizeof(arr) / sizeof(arr[0]);

        int min_number = arr[0];
        for (int i = 1; i < size - 1; i++)
        {
            min_number = min_number > arr[i] ? arr[i] : min_number;
            // min_number = std::min(min_number, arr[i]);
        }
        
        std::cout << "Minimum number is " << min_number << std::endl;
    }
    //////////////////////////////////////////////////////////////////////

    //////////////////// 가장 작은 수의 인덱스 찾기 ////////////////////////////
    {
        int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
        int size = sizeof(arr) / sizeof(arr[0]);

        int min_number = arr[0];
        int min_index = 0;
        for (int i = 1; i < size - 1; i++)
        {
            min_index = min_number > arr[i] ? i : min_index;
            min_number = arr[min_index];
        }
        
        std::cout << "Minimum number is " << arr[min_index] << std::endl;
        std::cout << "Minimum index is " << min_index << std::endl;
    }
    //////////////////////////////////////////////////////////////////////

    ///////////////////////////////// 선택 정렬 ////////////////////////////
    {
        int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
        int size = sizeof(arr) / sizeof(arr[0]);

        for (int i = 0; i < size - 1; i++)
        // 선택정렬 알고리즘 상 가장 마지막 원소는 비교할 대상이 없으므로 이전까지만 비교
        {
            int min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[min_index] > arr[j])
                    min_index = j;
            }

            if (min_index != i)
                std::swap(arr[i], arr[min_index]);
        }

        Print(arr, size);
    }
    //////////////////////////////////////////////////////////////////////

    return 0;
}

bool CheckSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << CheckSorted(arr, size) << std::endl;
}
