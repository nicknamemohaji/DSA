#include <iostream>

template <typename T> void Swap(T &v1, T &v2);
void RecurPermutations(char *arr, int left, int right);

template <typename T> void Swap(T &v1, T &v2)
{
    T temp = v2;
    v2 = v1;
    v1 = temp;
}

void RecurPermutations(char *arr, int left, int right)
{
    if (left == right)
    {
        for (int i = 0; i <= right; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
        return ;
    }

    for (int i = left; i <= right; i++)
    {
        Swap(arr[i], arr[left]);

        RecurPermutations(arr, left + 1, right);

        Swap(arr[i], arr[left]);
    }
}

int main(void)
{
    char arr[] = "abcd";
    int size = sizeof(arr) / sizeof(arr[0]);

    RecurPermutations(arr, 0, size - 1 - 1);

    return 0;
}
