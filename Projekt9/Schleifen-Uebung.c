#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Zahlen von 0 bis 100:\n");
    for (int i = 0; i <= 100; i++)
    {
        if (i % 3 == 0)
        {
            printf("%d\n", i);
        }
    }

    printf("\n");
    return 0;
}
