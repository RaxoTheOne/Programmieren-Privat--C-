#include <stdio.h>
#include <stdlib.h>

int arr[10] = {3, 5, 1, 4, 2, 8, 7, 6, 10, 9}; // Array mit 10 Elementen

int main()
{
    // Array ausgeben
    printf("Array-Inhalt: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Array sortieren
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Sortiertes Array ausgeben
    printf("Sortiertes Array: \n");
    for(int i = 0 ; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Array in umgekehrter Reihenfolge ausgeben
    printf("Array in umgekehrter Reihenfolge: \n");
    for(int i = 9; i >= 0; i--){
        printf("%d ", arr[i]);
    }
}