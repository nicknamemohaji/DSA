#include "sorting.h"

// Function to generate a random integer between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create a randomized array with some duplicated elements
void createRandomArray(int array[], int size, int min, int max) {
    srand((unsigned int)time(NULL)); // Seed for randomization based on current time

    for (int i = 0; i < size; ++i) {
        array[i] = getRandomNumber(min, max);
    }
}

// Function to print an array
void printArray(int array[], int size) {
	if (!DEBUG)
        return ;
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void copyArray(int source[], int destination[], int size)
{
	for (int i=0; i<size; i++)
	{
		destination[i] = source[i];
	}
}

void test(int array[N])
{
    int array_copy[N];
    t_count result;

	printf("\n\n================= O(n^2) ============\n\n");
	copyArray(array, array_copy, N);
    result = bubble_sort(N, array_copy);
	printf("[Bubble] access %d write %d\n", result.access, result.write);
    printArray(array_copy, N);

	copyArray(array, array_copy, N);
    result = insertion_sort(N, array_copy);
	printf("[Insertion] access %d write %d\n", result.access, result.write);
    printArray(array_copy, N);

	copyArray(array, array_copy, N);
    result = selection_sort(N, array_copy);
	printf("[Selection] access %d write %d\n", result.access, result.write);
    printArray(array_copy, N);

	printf("\n\n================= O(n lg n) ============\n\n");
	copyArray(array, array_copy, N);
    result = merge_sort(N, array_copy);
	printf("[Merge] access %d write %d\n", result.access, result.write);
    printArray(array_copy, N);

	copyArray(array, array_copy, N);
    result = quick_sort(N, array_copy);
	printf("[Quick] access %d write %d\n", result.access, result.write);
    printArray(array_copy, N);

	printf("\n\n================= O(n) ============\n\n");
	copyArray(array, array_copy, N);
    result = radix_sort(N, array_copy);
	printf("[Radix(LSD)] access %d write %d\n", result.access, result.write);
    printArray(array_copy, N);
}

int main() {
    int test_array[N];

    printf("**************************************\n");
    printf("Randomized Array of length %d: \n", N);
    createRandomArray(test_array, N, N * -5, N * 5);
    printArray(test_array, N);
    test(test_array);
    printf("\n\n");


    printf("**************************************\n");
    printf("Sorted Array of length %d: \n", N);
    for (int i=0; i<N; i++)
        test_array[i] = i;
    printArray(test_array, N);
    test(test_array);
    printf("\n\n");


    printf("**************************************\n");
    printf("Reverse Sorted Array of length %d: \n", N);
    for (int i=0; i<N; i++)
        test_array[i] = N - i;
    printArray(test_array, N);
    test(test_array);
    printf("\n\n");

    return 0;
}
