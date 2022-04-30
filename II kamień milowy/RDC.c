#define _CRT_SECURE_NO_WARNINGS      
#include<stdio.h>

void RDC_data(char* text[], int* shift) {
    char temp;
    printf("\tPodaj tekst do odszyfrowania: ");
    scanf("%c", &temp);
    scanf("%[^\n]", text);

    printf("\tPodaj przesuniêcie: ");
    scanf("%d", shift);
}

void RDC_decrypt(char text[], int shift) {

    for (int i = 0; text[i] != 0; ++i) {

        if (text[i] >= '!' && text[i] <= '~') {
            text[i] -= shift;
            if (text[i] < '!')
                text[i] += '~' - '!' + 1;
        }
    }
    printf("\t%s", text);
}
