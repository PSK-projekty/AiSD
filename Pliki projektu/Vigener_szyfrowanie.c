#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h> 
# include <string.h>
# include <ctype.h> 

void dane(char* tekst, char* klucz) {
	printf("Podaj tekst do zaszyfrowania: ");

	scanf("%[^\n]", tekst);   //Wczytanie tekstu

	printf("Podaj klucz: ");

	scanf("%s", klucz);   //Wczytanie klucza
}

void szyfrVigenera(char* tekst, char* klucz) {

	char zaszyfrowany_tekst;
	int szyfr;
	int dlugosc_klucza = strlen(klucz);

	//Pêtla interuj¹ca a¿ do koñca tekstu
	for (int i = 0; i < strlen(tekst); i++) {

		//Ma³e litery znajduj¹ siê od numeru 97 do 122 w ASCII
		if (tekst[i] >= 'a' && tekst[i] <= 'z') {
			szyfr = (tekst[i] - 'a' + (klucz[i % dlugosc_klucza]) - 'a') % 26 + 'a';
			zaszyfrowany_tekst = szyfr;
		}

		//Wielkie litery znajduj¹ siê od numeru 65 do 90 w ASCII
		if (tekst[i] >= 'A' && tekst[i] <= 'Z') {
			szyfr = (tekst[i] - 'A' + (klucz[i % dlugosc_klucza]) - 'A') % 26 + 'A';
			zaszyfrowany_tekst = szyfr;
		}

		//Wyœwietl jeœli jest znakiem np liter¹
		if (isalpha(tekst[i])) {
			printf("%c", zaszyfrowany_tekst);
		}

		//Jeœli znak nie jest liter¹
		else
			printf("%c", tekst[i]);
	}
}

int main() {

	char klucz[500]; //Deklaracja klucza
	char tekst[500]; //Deklaracja tekstu do zaszyfrowania


	dane(&tekst, &klucz);  //Wywo³anie funkcji zbierj¹cej dane

	//Wyœwietlanie
	printf("Zaszyfrowany tekst: ");

	szyfrVigenera(tekst, klucz);  //Wywo³anie funkcji szyfruj¹cej

	return 0;
}