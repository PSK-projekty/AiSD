#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>

#include"PSC.h"
#include"RSC.h"
#include"PDC.h"
#include"RDC.h"
#include"SV.h"
#include"DV.h"

/**
 * \file main.c
 * \brief
 * Glowny plik programu, menu
*********************************************************************/

/// <summary>
/// Kolorowanie tekstu na zielono.
/// </summary>
void green() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}
/// <summary>
/// Kolorowanie tekstu na bialo.
/// </summary>
void white() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
/// <summary>
/// Kolorowanie tekstu na czerwono.
/// </summary>
void red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}
/// <summary>
/// Generowanie odstepow.
/// </summary>
void loop() {
    for (int i = 0; i < 5; i++)
            printf("\n");
}

/// <summary>
/// W funkcji main znajduje sie menu programu, oparte jest na zagniezdzanych instrukcjach switch. Przechodzenie przez kolejne wezly skutkuje dostaniem sie "na sam dol" do funkcji szyfrujacej/deszyfrujacej.Funkcje te przyjmuja dwa parametry.
/// <param name="text">Tekst pobrany do szyfrowania lub deszyfrowania</param>
/// <param name="shift">Jezeli wybrana metoda szyfrowania/deszyfrowania jest metoda Cezara, ta zmienna bedzie zawierac przesuniecie</param>
/// <param name="shift">Jezeli wybrana metoda szyfrowania/deszyfrowania jest metoda Viegenera, ta zmienna bedzie zawierac klucz</param>
/// </summary>

int main() {
    char text[500];
    char key[500];
    int shift;
    int choice = 0;
    
    system("chcp 1250>NUL");

start:

    system("cls");
    loop();

    green();
        printf("\t+==================================+\n");
        printf("\t|               ");
    white();
        printf("MENU");
    green();
        printf("               |\n");
        printf("\t+----------------------------------+\n");
        printf("\t|                                  |\n");
        printf("\t|          ");
    white();
        printf("1.Szyfr Cezara");
    green();
        printf("          |\n");
        printf("\t|                                  |\n");
        printf("\t|        ");
    white();
        printf("2.Szyfr Vigenere’a");
    green();
        printf("        |\n");
        printf("\t|                                  |\n");
        printf("\t|       ");
    white();
        printf("0.Wyjœcie z programu");
    green();
        printf("       |\n");
        printf("\t|                                  |\n");
        printf("\t+==================================+\n");
    white();
        printf("\n \t             Wybieram: ");
    scanf("%d", &choice);

    system("cls");

    switch (choice) {
    cesar:
        system("cls");
    case 1:
        loop();
        green();
            printf("\t+==================================+\n");
            printf("\t|           ");
        white();
            printf("Szyfr Cezara");
        green();
            printf("           |\n");
            printf("\t+----------------------------------+\n");
            printf("\t|                                  |\n");
            printf("\t|           ");
        white();
            printf("1.Szyfrowanie");
        green();
            printf("          |\n");
            printf("\t|                                  |\n");
            printf("\t|          ");
        white();
            printf("2.Deszyfrowanie");
        green();
            printf("         |\n");
            printf("\t|                                  |\n");
            printf("\t|   ");
        white();
            printf("9.Powrót do poprzedniej karty");
        green();
            printf("  |\n");
            printf("\t|                                  |\n");
            printf("\t|       ");
        white();
            printf("0.Wyjœcie z programu");
        green();
            printf("       |\n");
            printf("\t|                                  |\n");
            printf("\t+==================================+\n");

        white();
            printf("\n \t             Wybieram: ");
        scanf("%d", &choice);

        system("cls");

        switch (choice) {
        case 1:
            loop();
            green();
                printf("\t+==================================+\n");
                printf("\t|           ");
            white();
                printf("Szyfrowanie");
            green();
                printf("            |\n");
                printf("\t+----------------------------------+\n");
                printf("\t|                                  |\n");
                printf("\t|           ");
            white();
                printf("1.Klasyczne*");
            green();
                printf("           |\n");
                printf("\t|                                  |\n");
                printf("\t|          ");
            white();
                printf("2.Rozszerzone**");
            green();
                printf("         |\n");
                printf("\t|                                  |\n");
                printf("\t|   ");
            white();
                printf("9.Powrót do poprzedniej karty");
            green();
                printf("  |\n");
                printf("\t|                                  |\n");
                printf("\t|       ");
            white();
                printf("0.Wyjœcie z programu");
            green();
                printf("       |\n");
                printf("\t|                                  |\n");
                printf("\t+==================================+\n");
            white();
                printf("\n \t *  Szyfrowanie 26 znaków, ma³e i wielkie litery alfabetu ³aciñskiego");
                printf("\n \t ** Szyfrowanie 94 znaków, ma³e i wielkie litery alfabetu ³aciñskiego, cyfry oraz znaki specjalne");

                printf("\n\n \t             Wybieram: ");
                scanf("%d", &choice);

            switch (choice) {
            case 1:
                system("cls");
                loop();
                PSC_data(text, &shift);
                PSC_encrypt(text, shift);

                printf("\n\n\tCzy chcesz odszyfrowaæ?\n");
                green();
                printf("\n\t1.Tak (przejdzesz do funkcji deszyfruj¹cej, a po up³ywie 5s przeniesiony do pocz¹tku");
                red();
                printf("\n\t2.Nie (powrócisz na pocz¹tek programu)");
                white();
                printf("\n\n \tWybieram: ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    PDC_decrypt(text, shift);
                    Sleep(5000);
                    goto start;
                    break;
                case 2:
                    goto start;
                    break;
                }
                break;

            case 2:
                system("cls");
                loop();
                RSC_data(text, &shift);
                RSC_encrypt(text, shift);

                printf("\n\n\tCzy chcesz odszyfrowaæ?\n");
                green();
                printf("\n\t1.Tak (przejdzesz do funkcji deszyfruj¹cej, a po up³ywie 5s przeniesiony do pocz¹tku");
                red();
                printf("\n\t2.Nie (powrócisz na pocz¹tek programu)");
                white();
                printf("\n\n \tWybieram: ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    RDC_decrypt(text, shift);
                    Sleep(5000);
                    goto start;
                    break;
                case 2:
                    goto start;
                    break;
                }
                break;

            case 9:
                goto cesar;
                break;

            case 0:
                return 0;
                break;
            }
            break;

        case 2:
            loop();
            green();
                printf("\t+==================================+\n");
                printf("\t|           ");
            white();
                printf("Deszyfrowanie");
            green();
                printf("          |\n");
                printf("\t+----------------------------------+\n");
                printf("\t|                                  |\n");
                printf("\t|           ");
            white();
                printf("1.Klasyczne*");
            green();
                printf("           |\n");
                printf("\t|                                  |\n");
                printf("\t|          ");
            white();
                printf("2.Rozszerzone**");
            green();
                printf("         |\n");
                printf("\t|                                  |\n");
                printf("\t|   ");
            white();
                printf("9.Powrót do poprzedniej karty");
            green();
                printf("  |\n");
                printf("\t|                                  |\n");
                printf("\t|       ");
            white();
                printf("0.Wyjœcie z programu");
            green();
                printf("       |\n");
                printf("\t|                                  |\n");
                printf("\t+==================================+\n");

            white();
                printf("\n \t *  Deszyfrowanie 26 znaków, ma³e i wielkie litery alfabetu ³aciñskiego");
                printf("\n \t ** Deszyfrowanie 94 znaków, ma³e i wielkie litery alfabetu ³aciñskiego, cyfry oraz znaki specjalne");

                printf("\n\n \t             Wybieram: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                system("cls");
                loop();
                PDC_data(text, &shift);
                PDC_decrypt(text, shift);
                loop();
                break;

            case 2:
                system("cls");
                loop();
                RDC_data(text, &shift);
                RDC_decrypt(text, shift);
                loop();
                break;

            case 9:
                goto cesar;
                break;

            case 0:
                return 0;
                break;
            }
            break;

        case 9:
            goto start;
            break;

        case 0:
            return 0;
            break;
        }

        break;

    case 2:
        loop();
        green();
            printf("\t+==================================+\n");
            printf("\t|          ");
        white();
            printf("Szyfr Vigener'a");
        green();
            printf("         |\n");
            printf("\t+----------------------------------+\n");
            printf("\t|                                  |\n");
            printf("\t|           ");
        white();
            printf("1.Szyfrowanie");
        green();
            printf("          |\n");
            printf("\t|                                  |\n");
            printf("\t|          ");
        white();
            printf("2.Deszyfrowanie");
        green();
            printf("         |\n");
            printf("\t|                                  |\n");
            printf("\t|   ");
        white();
            printf("9.Powrót do poprzedniej karty");
        green();
            printf("  |\n");
            printf("\t|                                  |\n");
            printf("\t|       ");
        white();
            printf("0.Wyjœcie z programu");
        green();
            printf("       |\n");
            printf("\t|                                  |\n");
            printf("\t+==================================+\n");

        white();
            printf("\n \t             Wybieram: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("cls");
            loop();
            SV_data(&text, &key);
            SV_encrypt(text, key);
            
            printf("\n\n\tZa 5 sekund zostaniesz przeniesiony do pocz¹tku\n");
            Sleep(5000);
            goto start; 
            break;

        case 2:
            system("cls");
            loop();
            DV_data(&text, &key);
            DV_decrypt(text, key);
            printf("\n\n\tZa 5 sekund zostaniesz przeniesiony do pocz¹tku\n");
            Sleep(5000);
            goto start;
            break;

        case 9:
            goto start;
            break;

        case 0:
            return 0;
            break;
        }
        break;

        break;

    case 0:
        return 0;
        break;

    }
    return 0;
}