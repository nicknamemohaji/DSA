#include <iostream>

int main(void)
{
    char arr[] = "ababcdfdceeedfg";
    int size = sizeof(arr) / sizeof(arr[0]) - 1;

    // 방법 1. 정렬하지 않고 출력
    // HASH FOR WIN ARGHHHHHHHHHHHH
    int table[26] = {0};
    for (int i = 0; i < size; i++)
        table[arr[i] - 'a']++;
    
    for (int i = 0; i < 26; i++)
    {
        if (table[i] > 0)
        {
            std::cout << (char) (i + 'a') << table[i];
        }
    }
    std::cout << std::endl;

    std::cout << "------------------" << std::endl;

    // 방법 2. 정렬 후 출력
    // USE WHILE LOOP ARGHHHHHHHHHHH
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }

    int index = 0;
    while (index < size)
    {
        int count = 0;
        char current_char = arr[index];
        while (arr[index] == current_char && index < size)
        {
            index++;
            count++;
        }
        std::cout << current_char << count;
    }
    std::cout << std::endl;


    return 0;
}