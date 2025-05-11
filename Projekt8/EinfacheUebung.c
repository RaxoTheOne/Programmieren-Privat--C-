#include <stdio.h>
#include <stdlib.h>

int main()
{
    int alter;
    char name[100];
    int noten[5];
    float summe = 0.0;  // Summe der Noten
    float durchschnitt; // Durchschnitt der Noten
    // Eingabe des Namens und Alters
    printf("Willkommen zu meiner C - Übung!\n");

    printf("Wie heißt du?\n");
    scanf("%s", name);

    printf("Wie alt bist du?\n");
    scanf("%d", &alter);

    printf("Hallo %s, du bist %d Jahre alt.\n", name, alter);
    printf("Wie alt bist du in 1 Jahr?\n");
    int alterInEinemJahr = alter + 1;
    printf("In einem Jahr bist du %d Jahre alt!\n", alterInEinemJahr);

    printf("Wie sind deine Noten?\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Note %d: ", i + 1);
        scanf("%d", &noten[i]);
        summe += noten[i];
    }

    durchschnitt = summe / 5.0; // Durchschnitt berechnen
    printf("Dein Notendurchschnitt ist: %.1f", durchschnitt);

    return 0;
}
