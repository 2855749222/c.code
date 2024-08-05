#include <stdio.h>
#include <string.h>

void fun(int *array)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 9 - i; j++)
        {
            if (array[j] < array[j + 1])
            {
                int tamp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tamp;
            }
        }
    }
}

int main()
{
    int array[] = {5, 1, 7, 81, 8, 16, 5, 9, 148, 1};
    fun(array);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
