#pragma once

/**
 * \file DV.h
 * \brief
 * Deszyfrowanie metoda Vigener'a.
*********************************************************************/

/// Pobranie danych od uzytkownika.
void DV_data(char* text, char* key);

/// <summary>
/// Funkcja deszyfrujaca.
/// Funkcja ta dziala niemalze identycznie do funkcji szyfrujacej. Jedynymi roznicami jest odejmowanie klucza od tekstu oraz dodatkowe odejmowanie dolnego kranca przedzialu
/// </summary>
/// <param name="text">Tekst pobrany do deszyfrowania</param>
/// <param name="key">Pobrany klucz</param>
void DV_decrypt(char* text, char* key);