#include <iostream>

int BinarySearch(int arr[], int size, int target);
int RecurBinarySearch(int arr[], int left, int right, int target);

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
            return middle ;
        else if (arr[middle] > target)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}

int RecurBinarySearch(int arr[], int left, int right, int target)
{

    int middle = (left + right) / 2;
    std::cout << "[" << left << ", " << right << "]" << std::endl;
    std::cout << "middle: " << middle << std::endl;

    if (left > right)
        return -1;
    
    if (arr[middle] == target)
        return middle;
    else if (arr[middle] > target)
        return RecurBinarySearch(arr, left, middle - 1, target);
    else
        return RecurBinarySearch(arr, middle + 1, right, target);
}

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << BinarySearch(arr, size, -2) << std::endl;
    std::cout << RecurBinarySearch(arr, 0, size - 1, -2) << std::endl;
}
