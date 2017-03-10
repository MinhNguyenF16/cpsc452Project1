#include "Vigenere.h"
#include <iostream>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
string VigenereKey;

bool Vigenere::setKey(const string& key)
{ 
	int charValue;
	VigenereKey =  key;

	// ensure all key are uppercase and valid letters
	for (int j=0; j<VigenereKey.length(); j++)
	{
		charValue = int(VigenereKey[j]);
		if (((charValue < 65) || (charValue > 90)) && ((charValue < 97) || (charValue > 122)))
		{
			return false;
		}

		VigenereKey[j] = toupper(VigenereKey[j]);
	}

	return true;  
}

/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Vigenere::encrypt(const string& plainText)
{ 
	string encryptedText ="";
	int keySize = VigenereKey.length();
	int index = 0;
	int temp;
	char newChar;

	while (encryptedText.length() < plainText.length() )
	{
		for (int i = 0; i<keySize; i++)
		{
			temp = (int(VigenereKey[i]) - 65 ) + (int(plainText[index]) );
			
			// put the value into A-Z ASCII range, 65-90
			if (temp > 90)
			{
				temp = temp - 90 + 64;
			}
			if (temp > 64 && temp < 91)
			{
				newChar = char(temp);
				encryptedText = encryptedText + newChar;
			}
					
			index++;
		}	
	}
	return encryptedText; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Vigenere::decrypt(const string& cipherText) 
{ 
	string decryptedText ="";
	int keySize = VigenereKey.length();
	int index = 0;
	int temp;
	char newChar;

	while (decryptedText.length() < cipherText.length() )
	{
		for (int i = 0; i<keySize; i++)
		{
			temp = ( int(cipherText[index]) - (int(VigenereKey[i]) - 65 )  );
			
			// put the value into A-Z ASCII range, 65-90
			if (temp < 65)
			{
				temp = 91 - (65 - temp);
			}

			if (temp > 64 && temp < 91)
			{
				newChar = char(temp);
				decryptedText = decryptedText + newChar;
			}

			index++;
		}
	}
	
	return decryptedText; 
}