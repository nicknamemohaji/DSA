#include <iostream>
#include <iomanip>

int Fibonacci(int n);
int RecurFibonacci(int n);

int RecurFibonacci(int n)
{
    switch(n)
    {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
    }
}

int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else 
    {
        int fn = 0;

        for (int i = 2, fn_prev = 1; i <= n; i++)
        {
            int temp = fn;
            fn = fn + fn_prev;
            fn_prev = temp;
        }

        return fn;
    }
}

int main(void)
{
    std::cout << "Input : ";
    for (int i = 0; i < 15; i++)
        std::cout << std::setw(3) << i << " ";
    std::cout << std::endl;

    std::cout << "RecurFibonacci:  ";
    for (int i = 0; i < 15; i++)
        std::cout << std::setw(3) << RecurFibonacci(i) << " ";
    std::cout << std::endl;

    std::cout << "Fibonacci:  ";
    for (int i = 0; i < 15; i++)
        std::cout << std::setw(3) << Fibonacci(i) << " ";
    std::cout << std::endl;

    return 0;
}