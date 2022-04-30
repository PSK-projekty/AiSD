#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h> 
# include <string.h>
# include <ctype.h> 

void SV_data(char* text, char* key) {
	char temp;
	printf("\tPodaj tekst do zaszyfrowania: ");
	scanf("%c", &temp);
	scanf("%[^\n]", text);

	printf("\tPodaj klucz: ");

	scanf("%s", key);

	printf("\tZaszyfrowany tekst: ");
}

void SV_encrypt(char* text, char* key) {

	char encrypted_text;
	int cipher;
	int key_length = strlen(key);

	for (int i = 0; i < strlen(text); i++) {

		if (text[i] >= 'a' && text[i] <= 'z') {
			cipher = (text[i] - 'a' + (key[i % key_length]) - 'a') % 26 + 'a';
			encrypted_text = cipher;
		}

		if (text[i] >= 'A' && text[i] <= 'Z') {
			cipher = (text[i] - 'A' + (key[i % key_length]) - 'A') % 26 + 'A';
			encrypted_text = cipher;
		}

		if (isalpha(text[i])) {
			printf("\t%c", encrypted_text);
		}

		else
			printf("\t%c", text[i]);
	}
}