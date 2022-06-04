#define _CRT_SECURE_NO_WARNINGS       
#include<stdio.h>

void RSC_data(char* text[], int* shift) {
    char temp;
    printf("\tPodaj tekst do zaszyfrowania: ");
    scanf("%c", &temp);
    scanf("%[^\n]", text);

    printf("\tPodaj przesuniêcie: ");

    scanf("%d", shift);
}

void RSC_encrypt(char text[], int shift) {

    for (int i = 0; text[i] != 0; ++i) {
        if (text[i] >= '!' && text[i] <= '~') {
            text[i] -= '!';
            text[i] += shift;
            text[i] = text[i] % 94;
            text[i] += '!';
        }
    }
    printf("\t\n\tZaszyfrowana wiadomoœæ: %s", text);
}