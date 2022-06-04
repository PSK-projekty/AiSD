#pragma once

/**
 * \file PDC.h
 * \brief
 * Deszyfrowanie metoda Cezara, deszyfrowanie alfabetu lacinskiego.
 *********************************************************************/

/// Pobranie danych od uzytkownika.
void PDC_data(char* text[], int* shift);

/// <summary>
/// Funkcja ta realizuje deszyfrowanie klasycznego szyfru Cezara.
/// 
/// Funkcja sprawdza czy dana litera w tekscie jest wielka czy mala, nastepnie odejmuje przesuniecie.
/// </summary>
/// <param name="text">Tekst pobrany do deszyfrowania</param>
/// <param name="shift">Przesuniecie</param>

void PDC_decrypt(char text[], int shift);