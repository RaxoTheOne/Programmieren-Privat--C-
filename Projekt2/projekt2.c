#include <stdio.h>
#include <string.h>

int main() {
    const char PIN[] = "1234";
    char eingabe[10];
    int versuche = 0;
    const int MAX_VERSUCHE = 3;

    while (versuche < MAX_VERSUCHE) {
        printf("Bitte geben Sie Ihre 4-stellige PIN ein: ");
        scanf("%s", eingabe); // ohne & bei char-Arrays!

        if (strcmp(eingabe, PIN) == 0) {
            printf("Zugang erfolgreich.\n");
            break;
        } else {
            printf("Falsche PIN!\n");
            versuche++;
        }
    }

    if (versuche == MAX_VERSUCHE) {
        printf("Zugriff verweigert. Programm wird beendet.\n");
        return 1;
    }

    int auswahl;
    double kontostand = 0.0;
    double betrag;

    do{
        printf("1. Einzahlung\n");
        printf("2. Auszahlung\n");
        printf("3. Kontostand anzeigen\n");
        printf("4. Beenden\n");
        printf("Bitte wählen Sie eine Option: ");
        scanf("%d", &auswahl);

        switch (auswahl)
        {
            case 1:
            printf("Option 1 gewählt.\n");
            printf("Bitte geben Sie den Betrag für die Einzahlung ein: ");
            scanf("%lf", &betrag);
            if (betrag > 0) {
                kontostand += betrag;
                printf("Einzahlung erfolgreich. Neuer Kontostand: %.2f EUR\n", kontostand);
            } else {
                printf("Ungültiger Betrag! Bitte einen positiven Wert eingeben.\n");
            }
            break;
        case 2:
            printf("Option 2 gewählt.\n");
            printf("Bitte geben Sie den Betrag für die Auszahlung ein: ");
            scanf("%lf", &betrag);
            if (betrag > 0 && betrag <= kontostand) {
                kontostand -= betrag;
                printf("Auszahlung erfolgreich. Neuer Kontostand: %.2f EUR\n", kontostand);
            } else if (betrag <= 0) {
                printf("Ungültiger Betrag! Bitte einen positiven Wert eingeben.\n");
            } else {
                printf("Nicht genug Guthaben! Auszahlung abgelehnt.\n");
            }
            break;
        case 3:
            printf("Option 3 gewählt.\n");
            printf("Ihr Kontostand beträgt: %.2f EUR\n", kontostand);
            break;
        case 4:
            printf("Option 4 gewählt.\n");
            break;
        default:
            printf("Ungültige Auswahl!\n");
        }
    } while ((auswahl != 4));
    
    return 0;
}