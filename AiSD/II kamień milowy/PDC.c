#define _CRT_SECURE_NO_WARNINGS      
#include<stdio.h>

void PDC_data(char* text[], int* shift) {
    char temp;
    printf("\tPodaj tekst do odszyfrowania: ");
    scanf("%c", &temp);
    scanf("%[^\n]", text);        

    printf("\tPodaj przesuniêcie: ");

    scanf("%d", shift);
}

void PDC_decrypt(char text[], int shift) {

    for (int i = 0; text[i] != 0; ++i) {       

        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] -= shift;

            if (text[i] < 'A')
                text[i] += 'Z' - 'A' + 1;
        }

        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= shift;

            if (text[i] < 'a')
                text[i] += 'z' - 'a' + 1;
        }
    }
    printf("\t%s", text);
}
