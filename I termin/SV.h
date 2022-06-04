#pragma once

/**
 * \file SV.h
 * \brief
 * Szyfrowanie metoda Vigener'a.
*********************************************************************/

/// Pobranie danych od uzytkownika.
void SV_data(char* text, char* key);
///<summary>
/// Funkcja szyfrujaca

/// zaszyfrowana_wiadomosc[i] = (tekst[i] + klucz[i mod dlugosc_klucza] ) mod 26.
/// Zapis [i mod dlugosc_klucza] ma na celu obsluge przypadku gdy klucz jest krotszy od szyfrowanej wiadomosci (po przekroczeniu dlugosci klucza wraca do poczatku).
///
/// tekst = ala
/// klucz = kot
/// prawidlowy_wynik = kzt
///
/// Przypisujemy literom alfabetu kolejne numery: a=0 b=1 c=2 ... z=25
/// Postepujemy zgodnie z formula
/// (0+10) mod 26 = 10 -> k
/// (11+14) mod 26 = 25 -> z
/// (0+19) mod 26 = 19 -> t
///
/// Aby moc pracowac na liczbach musimy zaminic typ zmiennej z char na int, uzyskamy to w nastepujacy sposob
/// zaszyfrowana_wiadomosc[i] = ((int)tekst[i] + (int)(key[i mod dlugosc_klucza])) % 26;
///
/// Poniewaz pracujemy na tablicy ASCII trzeba odjac dolna granice przedzialu w jakim znajduja sie male lub wielkie litery.
/// </summary>
/// <param name="text">Tekst pobrany do szyfrowania</param>
/// <param name="key">Pobrany klucz</param>
void SV_encrypt(char* text, char* key);