#include <stdio.h>

int main()
{

    int n = 100;
    printf("%d ", 1);
    for (int i = 2; i <= n; i++)
    {
        int m = 1;
        for (int j = 2; j < i; j++)
        {

            if (i % j == 0)
            {
                m = 0;
                break;
            }
        }
        if (m)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
