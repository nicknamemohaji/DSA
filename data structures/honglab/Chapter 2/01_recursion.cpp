#include <iostream>

// void Func1();
// void Func2();

// void Func1()
// {
//     int j = 1;
//     std::cout << "This is Func1() " << j << std::endl;
//     Func2();
// }

// void Func2()
// {
//     int i = 2;
//     std::cout << "This is Func2() " << i << std::endl;
// }

// int main(void)
// {
//     Func1();
//     return 0;
// }

void RecurFunc(int count);

void RecurFunc(int count)
{
    if (count == 0)
        return ;
    
    // std::cout << count << std::endl;
    RecurFunc(count - 1);
    std::cout << count << std::endl;
}

int main(void)
{
    RecurFunc(5);
    return 0;
}
