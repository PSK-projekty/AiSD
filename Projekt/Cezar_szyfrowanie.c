#define _CRT_SECURE_NO_WARNINGS           //Usuwanie b��du C4996 (scanf may by unsafe.  Consider using scanf_s)
#include<stdio.h>

void dane(char* tekst[], int* przesuniecie) {
    printf("Podaj tekst do zaszyfrowania: ");

    scanf("%[^\n]", tekst);           //Wczytywanie wiecej ni� jednego wyrazu

    printf("Podaj przesuniecie: ");

    scanf("%d", przesuniecie);
}

void szyfrowanie(char tekst[], int przesuniecie) {

    for (int i = 0; tekst[i] != 0; ++i) {

        /*----------Szyfrowanie wszystkich znak�w, opr�cz znak�w bia�ych----------

            if (tekst[i] >= '!' && tekst[i] <= '~') {

                tekst[i] -= '!';
                tekst[i] += przesuniecie;
                tekst[i] = tekst[i] % 94;
                tekst[i] += '!';

            }

        ---------- Szyfrowanie wszystkich znak�w, opr�cz znak�w bia�ych -----------*/


        //----------Klasyczny szyfr Cezara, szyfrowanie wielkich i ma�ych liter----------//
        if (tekst[i] >= 'A' && tekst[i] <= 'Z') {

            tekst[i] -= 'A';
            tekst[i] += przesuniecie;
            tekst[i] = tekst[i] % 26;
            tekst[i] += 'A';

        }

        if (tekst[i] >= 'a' && tekst[i] <= 'z') {

            tekst[i] -= 'a';
            tekst[i] += przesuniecie;
            tekst[i] = tekst[i] % 26;
            tekst[i] += 'a';

        }
        //----------Klasyczny szyfr Cezara, szyfrowanie wielkich i ma�ych liter----------//
    }
    printf("%s", tekst);
}

int main() {

    char tekst[500];

    int przesuniecie;

    dane(&tekst, &przesuniecie);
    szyfrowanie(tekst, przesuniecie);

    return 0;
}