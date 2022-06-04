#pragma once

/**
 * \file RDC.h
 * \brief
 * Deszyfrowanie metoda Cezara, deszyfrowanie wszystkich znakow.
*********************************************************************/

 /// Pobranie danych od uzytkownika.
void RDC_data(char* text[], int* shift);
/// <summary>
/// Funkcja ta realizuje deszyfrowanie szyfru Cezara, ktory moze dzialac na wszystkich znakach ASCII z przedzialu od ! do ~
/// 
/// Dzialanie tej funkcji jest niemal identyczne do klasycznej metody 
/// Funkcja sprawdza na danej pozycji w tekscie wystepuje znak, nastepnie odejmuje przesuniecie. 
/// </summary>
/// <param name="text">Tekst pobrany do deszyfrowania</param>
/// <param name="shift">Przesuniecie</param>
void RDC_decrypt(char text[], int shift);