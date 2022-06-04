#pragma once

/**
 * \file RSC.h
 * \brief
 * Szyfrowanie metoda Cezara, szyfrowanie wszystkich znakow.
*********************************************************************/

/// Pobranie danych od uzytkownika.
void RSC_data(char* text[], int* shift);

/// <summary>
/// Funkcja ta realizuje szyfr Cezara, ktory moze dzialac na wszystkich znakach ASCII z przedzialu od ! do ~
/// 
/// Dzialanie tej funkcji jest niemal identyczne do klasycznej metody.
/// Funkcja sprawdza na danej pozycji w tekscie wystepuje znak, nastepnie odejmuje dolna granice zakresu, dodaje przesuniecie i dzieli modulo 94. Na koniec dodaje dolna granice przedzialu.
/// </summary>
/// <param name="text">Tekst pobrany do szyfrowania</param>
/// <param name="shift">Przesuniecie</param>
void RSC_encrypt(char text[], int shift);