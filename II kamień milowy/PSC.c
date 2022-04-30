#define _CRT_SECURE_NO_WARNINGS       
#include<stdio.h>

void PSC_data(char* text[], int* shift) {
    char temp;
    printf("\tPodaj tekst do zaszyfrowania: ");
    scanf("%c", &temp);
    scanf("%[^\n]", text);

    printf("\tPodaj przesuniêcie: ");

    scanf("%d", shift);
}

void PSC_encrypt(char text[], int shift) {

    for (int i = 0; text[i] != 0; ++i) {
        if (text[i] >= 'A' && text[i] <= 'Z') {

            text[i] -= 'A';
            text[i] += shift;
            text[i] = text[i] % 26;
            text[i] += 'A';

        }

        if (text[i] >= 'a' && text[i] <= 'z') {

            text[i] -= 'a';
            text[i] += shift;
            text[i] = text[i] % 26;
            text[i] += 'a';

        }
    }
    printf("\t%s", text);
}