#include <iostream>

bool CheckSorted(int* arr, int size);
void Print(int arr[], int size);


int main(void)
{
    std::cout << std::boolalpha;

    /////////////////////// 버블정렬 ////////////////////////
    {
        int arr[] = { 1, 2, 3, 5, 4 };
        int n = sizeof(arr) / sizeof(arr[0]);

        bool swapped = true;
        for (int i = 0; i < n && swapped; i++)
        {
            swapped = false;
            for (int j = 0; j < (n - 1) - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);            
                    swapped = true;
                }
                Print(arr, n);
            }
            std::cout << "swapped: " << swapped << std::endl;
        }
        Print(arr, n);
    }
    ///////////////////////////////////////////////////////

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