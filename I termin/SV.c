#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h> 
# include <string.h>
# include <ctype.h> 

void SV_data(char* text, char* key) {
	char temp;
	printf("\tNie u¿ywaj spacji, cyfr, znaków specjanych np. AlaMaKota\n\n");
	printf("\tPodaj tekst do zaszyfrowania: ");
	scanf("%c", &temp);
	scanf("%[^\n]", text);

	printf("\tPodaj klucz: ");

	scanf("%s", key);
}

void SV_encrypt(char* text, char* key) {

	char encrypted_text[500];
	int key_length = strlen(key);

	printf("\n\tZaszyfrowana wiadomoœæ: ");

	for (int i = 0; i < strlen(text); i++) {

		if (islower(text[i]))
			encrypted_text[i] = ((int)text[i] - 97 + (int)tolower(key[i % key_length]) - 97) % 26 + 97;
		
		else
			encrypted_text[i] = ((int)text[i] - 65 + (int)toupper(key[i % key_length]) - 65) % 26 + 65;
		
		if (isalpha(text[i]))
			printf("%c", encrypted_text[i]);

		else
			printf("%c", text[i]);
		
	 }
}