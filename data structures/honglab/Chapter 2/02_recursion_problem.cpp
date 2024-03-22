#include <iostream>

int Sum(int arr[], int size);
int RecurSum(int arr[], int size);

int Sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int RecurSum(int arr[], int size)
{
    /*
    힌트: 역순으로 더하기
    (1 + 2 + 3 + 4 + ... + 9 + 10)
    = ((1 + 2 + 3 + ... + 9) + 10)
    = (((1 + 2 + 3 + ... + 8) + 9) + 10)
    */
    if (size == 0)
        return 0;
    return RecurSum(arr, size - 1) + arr[size - 1];
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << Sum(arr, n) << std::endl;
    std::cout << RecurSum(arr, n) << std::endl;

    return 0;
}
