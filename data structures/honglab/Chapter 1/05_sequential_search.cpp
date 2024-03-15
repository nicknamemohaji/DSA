#include <iostream>

int Count(int arr[], int size, int target);
int SotedCount(int arr[], int size, int target);
int SortedCountHelper(int arr[], int size, int target, int index);
int SequentialSearch(int arr[], int size, int target);
void InsertionSort(int arr[], int size);
bool CheckSorted(int* arr, int size);
void Print(int arr[], int size);

int main(void)
{
    std::cout << std::boolalpha;

    {
        int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2, 1, 1 };
        int size = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Count 9 = " << Count(arr, size, 9) << std::endl;
        std::cout << "Count 2 = " << Count(arr, size, 2) << std::endl;
        std::cout << "Count 8 = " << Count(arr, size, 8) << std::endl;
        std::cout << "Count 1 = " << Count(arr, size, 1) << std::endl;

        std::cout << "Search 2 = " << SequentialSearch(arr, size, 2) << std::endl;
        std::cout << "Search 5 = " << SequentialSearch(arr, size, 5) << std::endl;
        std::cout << "Search 9 = " << SequentialSearch(arr, size, 9) << std::endl;

        InsertionSort(arr, size);
        Print(arr, size);

        std::cout << "Sorted Count 9 = " << Count(arr, size, 9) << std::endl;
        std::cout << "Sorted Count 2 = " << Count(arr, size, 2) << std::endl;
        std::cout << "Sorted Count 8 = " << Count(arr, size, 8) << std::endl;
        std::cout << "Sorted Count 1 = " << Count(arr, size, 1) << std::endl;
    }

    return 0;
}

int Count(int arr[], int size, int target)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            count++;
    }
    return count;
}

int SotedCount(int arr[], int size, int target)
{
    int i = SequentialSearch(arr, size, target);

    if (i >= 0)
        return SortedCountHelper(arr, size, target, i + 1) + 1;
    else
        return 0;
}

int SortedCountHelper(int arr[], int size, int target, int index)
{
    // if (index >= size || arr[index] != target)
    //     return 0;
    // return SortedCountHelper(arr, size, target, index + 1) + 1;

    int count = 0;
    for (int i = index; i < size; i++)
    {
        if (arr[i] == target)
            count++;
        else
            break;
    }
    return count;
}

int SequentialSearch(int arr[], int size, int target)
{
    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] == target)
    //         return i;
    // }
    // return -1;

    int i;
    for (i = 0; i < size && arr[i] != target; i++) { /* Do Nothing */ }
    return i == size ? -1 : i;
}

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        int key = arr[i];

        for (; j > 0 && arr[j - 1] > key; j--)
            arr[j] = arr[j - 1];
        arr[j] = key;
    }
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
