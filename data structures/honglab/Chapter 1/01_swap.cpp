#include <iostream>

void MySwapRef(int &n1, int &n2);
void MySwapPtr(int *n1, int *n2);
bool CheckSorted(int n1, int n2);

int main(void)
{
    //////////////////////////// SWAP ////////////////////////////
    {
        int a = 3;
        int b = 2;

        std::cout << a << " " << b << std::endl;

        // 1. 직접 변경
        // int temp = a;
        // a = b;
        // b = temp;
        
        // 2. 함수 활용
        // MySwapPtr(&a, &b);  // Call by Value (Pointer)
        MySwapRef(a, b);    // Call by Reference 

        std::cout << a << " " << b << std::endl;
    }
    //////////////////////////////////////////////////////////////

    /////////////////////////// SORT /////////////////////////////
    {
        int arr[] = { 7, 50 };

        std::cout << arr[0] << " " << arr[1] << std::endl;

        if (arr[0] > arr[1])
            MySwapRef(arr[0], arr[1]);

        std::cout << arr[0] << " " << arr[1] << std::endl;
    }
    //////////////////////////////////////////////////////////////

    /////////////////////////// TEST /////////////////////////////
    {
        std::cout << std::boolalpha;
        int arr[2];

        for (int n2 = 0; n2 < 5; n2++)
        {
            for (int n1 = 0; n1 < 5; n1++)
            {
                arr[0] = n1;
                arr[1] = n2;

                // std::cout << "prev: " << arr[0] << " " << arr[1]<< " " << CheckSorted(arr[0], arr[1]) << std::endl;
                if (!CheckSorted(arr[0], arr[1]))
                    std::swap(arr[0], arr[1]);
                std::cout << "sorted: " << arr[0] << " " << arr[1]<< " " << CheckSorted(arr[0], arr[1]) << std::endl;
            }
        }
    }
    //////////////////////////////////////////////////////////////

    return 0;
}

void MySwapPtr(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void MySwapRef(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

bool CheckSorted(int n1, int n2)
{
    // return n1 <= n2;
    return !(n1 > n2);
}
