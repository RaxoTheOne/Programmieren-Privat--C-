#include <stdio.h>
#include <string.h>

char passwortdatei[] = "passwort.txt";
// Funktion zur PasswortVerschlüsselung (jedes Zeichen +1)
void passwortVerschluesseln(char eingabe[], char verschluesselt[])
{
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        verschluesselt[i] = eingabe[i] + 1;
    }
    verschluesselt[strlen(eingabe)] = '\0';
}
// Funktion zur Passwortentschlüsselung (jedes Zeichen -1)
void passwortEntschluesseln(char eingabe[], char entschluesselt[])
{
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        entschluesselt[i] = eingabe[i] - 1;
    }
    entschluesselt[strlen(eingabe)] = '\0';
}

void printBenutzerListe()
{
    FILE *p = fopen(passwortdatei, "r");
    if (!p)
    {
        printf("Fehler du Spast! Datei '%s' kann nicht geöffnet werden!\n", passwortdatei);
        return;
    }

    char zeile[200];
    int nr = 1;
    printf("\n=== Benutzerliste ===\n");
    while (fgets(zeile, sizeof(zeile), p))
    {
        // Zeilenumrbuch entfernen
        zeile[strcspn(zeile, "\n")] = 0;

        // Teile aufsplitten (Trennzeichen ;)
        char *user = strtok(zeile, ";");
        char *verschl = strtok(NULL, ";");
        char *orig = strtok(NULL, ";");

        // Ausgabe
        if (user && verschl && orig)
        {
            printf("%2d) Benutzer: %s | Passwort: %s | Original: %s\n", nr, user, verschl, orig);
            nr++;
        }
    }

    fclose(p);
}
int main()
{
    char benutzername[50];
    char passwort[50];
    char verschluesselt[50];
    char entschluesselt[50];

    printf("Benutzername eingeben: ");
    fgets(benutzername, sizeof(benutzername), stdin);
    benutzername[strcspn(benutzername, "\n")] = '\0';

    printf("Passwort eingeben: ");
    fgets(passwort, sizeof(passwort), stdin);
    passwort[strcspn(passwort, "\n")] = '\0';

    passwortVerschluesseln(passwort, verschluesselt);
    passwortEntschluesseln(verschluesselt, entschluesselt);

    // Datei öffnen und Daten schreiben
    FILE *p = fopen(passwortdatei, "a");
    if (p != NULL)
    {
        fprintf(p, "%s;%s;%s\n", benutzername, verschluesselt, passwort);
        fclose(p);
        printf("Daten wurden gespeichert.\n");
    }
    else
    {
        printf("\nFehler beim Öffnen der Datei '%s'.\n", passwortdatei);
        return 1;
    }

    printBenutzerListe();

    return 0;
}