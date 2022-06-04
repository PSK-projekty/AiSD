#pragma once

/**
 * \file PSC.h
 * \brief
 * Szyfrowanie metoda Cezara, szyfrowanie alfabetu lacinskiego.
*********************************************************************/

/// Pobranie danych od uzytkownika.
void PSC_data(char* text[], int* shift);

/// <summary>
/// Funkcja ta realizuje deszyfrowanie klasycznego szyfru Cezara
/// 
/// Funkcja sprawdza czy dana litera w tekscie jest wielka czy mala, nastepnie odejmuje dolna granice zakresu, dodaje przesuniecie i dzieli modulo 26. Na koniec dodaje dolna granice przedzialu.
/// </summary>
/// <param name="text">Tekst pobrany do szyfrowania</param>
/// <param name="shift">Przesuniecie</param>

void PSC_encrypt(char text[], int shift);