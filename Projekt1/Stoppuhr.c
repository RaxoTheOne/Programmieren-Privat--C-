#include <stdio.h>
#include <time.h>
#include <unistd.h>  // Für sleep()

int main()
{
    int auswahl;
    time_t startzeit, endzeit;
    double dauer;
    int laeuft = 0;
    int zurückgesetzt = 0;

    do {
        printf("\n===== Stoppuhr Menü =====\n");
        printf("1. Start\n");
        printf("2. Stopp\n");
        printf("3. Zurücksetzen\n");
        printf("4. Beenden\n");
        printf("Bitte wähle eine Option: ");
        scanf("%d", &auswahl);
        getchar(); // Eingabepuffer leeren

        switch(auswahl) {
            case 1:
                if (!laeuft) {
                    startzeit = time(NULL);  // Startzeit in Sekunden
                    printf("Stoppuhr gestartet...\n");
                    laeuft = 1;
                    zurückgesetzt = 0;  // Zurücksetzen-Status zurücksetzen

                    // Laufende Zeit anzeigen
                    while (laeuft) {
                        time_t aktuellezeit = time(NULL);
                        dauer = difftime(aktuellezeit, startzeit);

                        printf("\rVergangene Zeit: %.0f Sekunden", dauer);
                        fflush(stdout); // Aktualisiert die Anzeige
                        sleep(1); // 1 Sekunde warten

                        // Überprüfen, ob eine Eingabe erfolgt ist, um das Menü anzuzeigen
                        if (kbhit()) {
                            break;  // Schleife abbrechen und Menü erneut anzeigen
                        }
                    }
                } else {
                    printf("Stoppuhr läuft bereits!\n");
                }
                break;

            case 2:
                if (laeuft) {
                    endzeit = time(NULL);  // Endzeit
                    dauer = difftime(endzeit, startzeit);  // Dauer berechnen
                    printf("\nStoppuhr gestoppt. Dauer: %.0f Sekunden\n", dauer);
                    laeuft = 0;
                } else {
                    printf("Stoppuhr wurde noch nicht gestartet!\n");
                }
                break;

            case 3:
                if (laeuft || zurückgesetzt) {
                    printf("\nStoppuhr wird zurückgesetzt...\n");
                    laeuft = 0;  // Stoppuhr stoppen
                }
                startzeit = time(NULL);  // Zurücksetzen der Startzeit
                printf("Stoppuhr zurückgesetzt. Drücke '1' um erneut zu starten.\n");
                zurückgesetzt = 1;  // Zurücksetzen-Status setzen
                break;

            case 4:
                printf("Programm wird beendet.\n");
                break;

            default:
                printf("Ungültige Auswahl. Bitte erneut versuchen.\n");
        }

    } while(auswahl != 4);

    return 0;
}
