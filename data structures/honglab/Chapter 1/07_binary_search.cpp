#include <iostream>

int BinarySearch(int arr[], int size, int target);

int main(void)
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 8, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    BinarySearch(arr, size, 7);

    return 0;
}

int BinarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;
    int middle;

    while (left <= right)
    {
        middle = (left + right) / 2;

        std::cout << "[" << left << ", " << right << "]" << std::endl;
        std::cout << "middle: " << middle << std::endl;

        if (arr[middle] == target)
            break ;
        else if (arr[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;
    }

    // 최초의 값을 찾기 위해 추가 처리
    if (left > right)
    {
        std::cout << "[" << left << ", " << right << "]" << std::endl;
        std::cout << "not found" << std::endl;
        return -1;
    }
    while (arr[middle] == target)
        middle--;
    
    std::cout << "Found " << arr[middle] << " - index " << middle << std::endl;
    return ++middle;
}
