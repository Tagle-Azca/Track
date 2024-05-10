#include <stdio.h>

int retscan;

void print_array(int[], int);
void bubble_sort(int[], int);
void selection_sort(int[], int);
int binary_search(int, int[], int);

int main()
{
    printf(" === Before sorting ===\n");
    int array[] = {5, 4, 2, 21, 7, 22, 1, 14, 46, 3, 12};
    int size = sizeof(array) / sizeof(int);
    int num_to_find;

    print_array(array, size);

    int sel;
    printf("How do you want to sort this array? \n");
    printf("\t1) bubble sort\n\t2) selection sort\n\n\topc: ");
    retscan = scanf("%d", &sel);

    switch (sel)
    {
    case 1:
        bubble_sort(array, size);
        break;

    case 2:
        selection_sort(array, size);
        break;
    }

    printf(" === After sorting (%s) ===\n", sel == 1 ? "bubble" : "selection");
    print_array(array, size);

    printf("\n\n === ========================= ===\n");
    printf("Now that the array has been sorted, let's find a number\n");

    printf("What number are you looking for? I will tell you the index\n");
    printf("num to find: ");
    retscan = scanf("%d", &num_to_find);

    int index = binary_search(num_to_find, array, size);

    printf("Found num %d at position %d\n", num_to_find, index);

    return 0;
}

void print_array(int arr[], int size)
{
    printf("[Size %d]\t", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[step];
        arr[step] = temp;
    }
}

int binary_search(int num, int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
