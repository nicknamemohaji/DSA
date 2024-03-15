#include <iostream>

typedef struct {
    int key;
    char value;
} Element;

bool CheckSorted(Element arr[], int size);
void Print(Element arr[], int size);

int main(void)
{
    std::cout << std::boolalpha;

    ///////////////////////////////// 선택 정렬 ////////////////////////////
    {
        Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'}};
        int size = sizeof(arr) / sizeof(arr[0]);
        Print(arr, size);

        for (int i = 0; i < size - 1; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[min_index].key > arr[j].key)
                    min_index = j;
            }

            if (min_index != i)
                std::swap(arr[i], arr[min_index]);
            Print(arr, size);
        }

        Print(arr, size);
    }
    //////////////////////////////////////////////////////////////////////

    return 0;
}

bool CheckSorted(Element arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        if (arr[i].key > arr[i + 1].key)
            return false;
    return true;
}

void Print(Element arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i].key << " ";
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << arr[i].value << " ";
    std::cout << CheckSorted(arr, size) << std::endl;
}
