#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// Funktion zur Verschlüsselung
void passwortVerschluesseln(char *eingabe, char *ausgabe)
{
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        ausgabe[i] = eingabe[i] + 1; // Einfache Verschlüsselung durch Addition(+1)
    }
}
// Funktion zur Entschlüsselung
void passwortEntschluesseln(char *eingabe, char *ausgabe)
{
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        ausgabe[i] = eingabe[i] - 1; // Einfache Entschlüsselung durch Subtraktion(-1)
    }
}
void benutzerEingabe(char *benutzerName, char *passwort)
{
    printf("Bitte gib deinen Benutzernamen ein: ");
    scanf("%s", benutzerName);

    printf("Bitte Passwort eingeben: ");
    scanf("%s", passwort);
    // Entfernen des Zeilenumbruchs
    benutzerName[strcspn(benutzerName, "\n")] = 0;
    passwort[strcspn(passwort, "\n")] = 0;
}

int main()
{
    // Variablen deklarieren
    char passwort[100];
    char verschluesseltesPasswort[100];
    char entschluesseltesPasswort[100]; // Initialisierung des Arrays
    char benutzerName[100];

    /*// Benutzername eingeben
    printf("Bitte Benutzernamen eingeben: ");
    fgets(benutzerName, sizeof(benutzerName), stdin);
    benutzerName[strcspn(benutzerName, "\n")] = 0; // Entfernen des Zeilenumbruchs*/
    benutzerEingabe(benutzerName, passwort);
    /*// Passwort eingeben
    printf("Bitte Passwort eingeben: ");
    fgets(passwort, sizeof(passwort), stdin);
    passwort[strcspn(passwort, "\n")] = 0; // Entfernen des Zeilenumbruchs*/
    printf("Benutzername: %s\n", benutzerName);
    // Passwort verschlüsseln
    passwortVerschluesseln(passwort, verschluesseltesPasswort);
    printf("Verschlüsseltes Passwort: %s\n", verschluesseltesPasswort);
    // Überprüfen, ob das Passwort korrekt verschlüsselt wurde
    if (strcmp(passwort, verschluesseltesPasswort) != 0)
    {
        printf("Passwort erfolgreich verschlüsselt!\n");
    }
    else
    {
        printf("Fehler beim Verschlüsseln des Passworts.\n");
    }

    // Passwort entschlüsseln
    passwortEntschluesseln(verschluesseltesPasswort, entschluesseltesPasswort);
    printf("Entschlüsseltes Passwort: %s\n", entschluesseltesPasswort);
    // Überprüfen, ob das entschlüsselte Passwort mit dem ursprünglichen Passwort übereinstimmt
    if (strcmp(passwort, entschluesseltesPasswort) == 0)
    {
        printf("Passwort erfolgreich entschlüsselt!\n");
    }
    else
    {
        printf("Fehler beim Entschlüsseln des Passworts.\n");
    }
    return 0;
}
// This code demonstrates a simple password encryption and decryption process.
// The password is encrypted by adding 1 to each character and decrypted by subtracting 1.
// The program also checks if the decrypted password matches the original password.
// The encryption and decryption functions are defined separately.
// The program uses standard input/output functions and string manipulation functions from the C standard library.
// The code is structured to be easy to read and understand, with clear comments explaining each step.
// The program is designed to be compiled and run in a C environment, and it uses the C17 standard.
// The code is intended for educational purposes and demonstrates basic concepts of string manipulation and encryption in C.
// The encryption method used here is very basic and should not be used for real security purposes.
// The program is a simple demonstration of how to handle strings and perform basic encryption/decryption in C.
// The code is written in a straightforward manner, making it easy to follow for beginners.
// The program can be compiled using a C compiler and run in a terminal or command prompt.