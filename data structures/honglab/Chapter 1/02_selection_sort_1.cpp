#include <iostream>

bool CheckSorted(int* arr, int size);

int main(void)
{
    std::cout << std::boolalpha;

    ///////////////////////////// 3개 정렬 ///////////////////////////////
    {
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int arr[3] = {i, j, k};
                    int size = sizeof(arr) / sizeof(arr[0]);

                    for (int e = 0; e < size; e++)
                        std::cout << arr[e] << " ";
                    std::cout << " -> ";

                    // 모든 케이스 나열...
                    // if (arr[0] <= arr[1] && arr[1] <= arr[2])
                    //     ;
                    // else if (arr[2] <= arr[1] && arr[1] <= arr[0])
                    // {
                    //     std::swap(arr[0], arr[2]);
                    // }
                    // else if (arr[0] <= arr[2] && arr[2] <= arr[1])
                    // {
                    //     std::swap(arr[1], arr[2]);
                    // }
                    // else if (arr[1] <= arr[0] && arr[0] <= arr[2])
                    // {
                    //     std::swap(arr[0], arr[1]);
                    // }
                    // else if (arr[1] <= arr[2] && arr[2] <= arr[0])
                    // {
                    //     std::swap(arr[0], arr[1]);
                    //     std::swap(arr[1], arr[2]);
                    // }
                    // else if (arr[2] <= arr[0] && arr[0] <= arr[1])
                    // {
                    //     std::swap(arr[0], arr[2]);
                    //     std::swap(arr[1], arr[2]);
                    // }

                    // 보다 간단한게 최적화...
                    // 1. 가장 큰 원소를 제 위치에 놔두고
                    // 2. 나머지 두 원소를 정렬
                    if (arr[0] > arr[1])
                        std::swap(arr[0], arr[1]);
                    if (arr[1] > arr[2])
                        std::swap(arr[1], arr[2]);
                    if (arr[0] > arr[1])
                        std::swap(arr[0], arr[1]);

                    for (int e = 0; e < size; e++)
                        std::cout << arr[e] << " ";
                    std::cout << CheckSorted(arr, size);
                    std::cout << std::endl;
                }
            }
        }
    }
    ///////////////////////////////////////////////////////////////////
    
    return 0;
}

bool CheckSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}
