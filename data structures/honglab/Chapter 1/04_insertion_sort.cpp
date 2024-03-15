#include <iostream>

bool CheckSorted(int* arr, int size);
void Print(int arr[], int size);


int main(void)
{
    std::cout << std::boolalpha;

    ///////////////////////////// 삽입정렬 /////////////////////////////
    {
        int arr[] = { 1, 2, 4, 5, 3, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        Print(arr, n);

        for (int i = 1; i < n; i++)
        {
            int j = i;
            int key = arr[i];

            for (; j > 0 && arr[j - 1] > key; j--)
                arr[j] = arr[j - 1];
            arr[j] = key;
        }

        Print(arr, n);
    }
    /////////////////////////////////////////////////////////////////////

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