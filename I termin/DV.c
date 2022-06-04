#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h> 
# include <string.h>
# include <ctype.h> 

void DV_data(char* text, char* key) {
	char temp;
	printf("\tPodaj tekst do odszyfrowania: ");
	scanf("%c", &temp);
	scanf("%[^\n]", text);

	printf("\tPodaj klucz: ");
	scanf("%s", key);
}

void DV_decrypt(char* text, char* key) {

	char decrypted_text;
	int key_length = strlen(key);
	printf("\n\tOdszyfrowana wiadomosc: ");
	
	for (int i = 0; i < strlen(text); i++) {

		if (islower(text[i])) 
			decrypted_text = (((text[i] - 97) - (tolower(key[i % key_length]) - 97)) + 26) % 26 + 97;
		else 
			decrypted_text = (((text[i] - 65) - (toupper(key[i % key_length]) - 65)) + 26) % 26 + 65;

		if (isalpha(text[i]))
			printf("%c", decrypted_text);

		else
			printf("%c", text[i]);
	}

}

