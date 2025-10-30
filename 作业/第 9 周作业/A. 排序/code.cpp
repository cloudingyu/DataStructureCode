#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int xorshift(unsigned int x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

int main()
{
    unsigned int n, x0;
    scanf("%u %u", &n, &x0);

    unsigned int *arr = (unsigned int *)malloc(n * sizeof(unsigned int));
    unsigned int *tmp = (unsigned int *)malloc(n * sizeof(unsigned int));

    unsigned int x = x0;
    for (unsigned int i = 0; i < n; ++i)
    {
        x = xorshift(x);
        arr[i] = x;
    }


    for (int byte = 0; byte < 4; ++byte)
    {
        unsigned int count[256] = {0};

        for (unsigned int i = 0; i < n; ++i)
        {
            unsigned int c = (arr[i] >> (byte * 8)) & 0xFF;
            count[c]++;
        }

        for (int i = 1; i < 256; ++i)
            count[i] += count[i - 1];

        for (unsigned int i = n - 1; i < n; --i)
        {
            unsigned int c = (arr[i] >> (byte * 8)) & 0xFF;
            tmp[--count[c]] = arr[i];
        }

        unsigned int *swap = arr;
        arr = tmp;
        tmp = swap;
    }

    unsigned int sum = 0;
    for (unsigned int i = 0; i < n; ++i)
        sum += (i + 1) * arr[i];

    printf("%u\n", sum);

    free(arr);
    free(tmp);
    return 0;
}