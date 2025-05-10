#include <stdio.h>

struct Person{
    char name[100];
    int alter;
    float groesse;
};

int main(){
    struct Person personen[3]; // Platz für 3 Personen
    //Eingabe der Daten
    printf("\n----Personenliste----\n");
    printf("Geben Sie die Daten der Personen ein:\n");
    // Schleife für die Eingabe der Daten
    for(int i = 0; i < 3; i++){
        printf("Geben Sie den Namen der Person %d ein: ", i + 1);
        scanf("%s", personen[i].name);
        printf("Geben Sie das Alter der Person %d ein: ", i + 1);
        scanf("%d", &personen[i].alter);
        printf("Geben Sie die Groesse der Person %d ein: ", i + 1);
        scanf("%f", &personen[i].groesse);
    }
    //Ausgabe der Daten
    printf("\n----Personenliste----\n");
    for(int i = 0; i < 3; i++){
        printf("Name: %s | Alter: %d | Groesse: %.2f m\n", personen[i].name, personen[i].alter, personen[i].groesse);
    }

}