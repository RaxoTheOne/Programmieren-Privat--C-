#include <stdio.h>
#include <stdlib.h>

char benutzername[50];

int main(){
    printf("Wie heißt du?\n");
    scanf("%s", benutzername);

    printf("Hallo %s, wie geht's?\n", benutzername);
    scanf("%s", benutzername);

    printf("Soweit alles gut!\n");

}