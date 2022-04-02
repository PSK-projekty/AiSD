#define _CRT_SECURE_NO_WARNINGS           //Usuwanie b³êdu C4996 (scanf may by unsafe.  Consider using scanf_s)
#include<stdio.h>

void dane(char* tekst[], int* przesuniecie) {
    printf("Podaj tekst do odszyfrowania: ");

    scanf("%[^\n]", tekst);           //Wczytywanie wiecej ni¿ jednego wyrazu

    printf("Podaj przesuniecie: ");

    scanf("%d", przesuniecie);
}

void deszyfrowanie(char tekst[], int przesuniecie) {

    for (int i = 0; tekst[i] != 0; ++i) {        // 0 sprawdzanie czy tablica nie jest pusta 

    /*---------- Deszyfrowanie wszystkich znaków, oprócz znaków bia³ych----------

        if (tekst[i] >= '!' && tekst[i] <= '~'){
            tekst[i] -=  przesuniecie;

            if (tekst[i] < '!')
                tekst[i] += '~' - '!' + 1;
        }

    ---------- Deszyfrowanie wszystkich znaków, oprócz znaków bia³ych -----------*/

    //---------- Klasyczny szyfr Cezara, odszyfrowanie wielkich i ma³ych liter ----------//

        if (tekst[i] >= 'A' && tekst[i] <= 'Z') {
            tekst[i] -= przesuniecie;

            if (tekst[i] < 'A')
                tekst[i] += 'Z' - 'A' + 1;
        }

        if (tekst[i] >= 'a' && tekst[i] <= 'z') {
            tekst[i] -= przesuniecie;

            if (tekst[i] < 'a')
                tekst[i] += 'z' - 'a' + 1;
        }
        //---------- Klasyczny szyfr Cezara, odszyfrowanie wielkich i ma³ych liter ----------//
    }
    printf("%s", tekst);
}

int main() {

    char tekst[500];

    int przesuniecie;

    dane(&tekst, &przesuniecie);
    deszyfrowanie(tekst, przesuniecie);

    return 0;
}