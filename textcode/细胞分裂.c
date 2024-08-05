#include <stdio.h>
//时间复杂度为 n^2
int exponential(int n)
{
    int count = 0;
    int des = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < des; j++)
        {
            count++;
        }
        des *= 2;
    }
    return des;
}

int main()
{
    int n = 3;
    printf("%d",exponential(n));
    return 0;
}