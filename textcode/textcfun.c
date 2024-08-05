#include "text.h"
int read(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int ret = read(n-1);
    return ret + n;
}