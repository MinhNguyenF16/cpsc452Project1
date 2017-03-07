#include "Caesar.h"
#include <iostream>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
int caesarKey;

bool Caesar::setKey(const string& key)
{ 
	//cout << key <<endl;
	caesarKey =  stoi(key);
	cout << "Caesar key: "<< caesarKey <<endl;
	return false;  
}


/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plainText)
{ 
	string encryptedText ="";
	// ASCII value: A = 65, B = 66 ... Z = 90 
	//cout << plaintext<<endl;
	for (int i=0; i<plainText.length(); i++)
	{
		int letterValue = int(plainText[i]) - caesarKey;

		if (letterValue >= 65)
		{
			encryptedText = encryptedText + char(letterValue);
		}
		else
		{
			letterValue = 91-(65-letterValue);
			encryptedText = encryptedText + char(letterValue);
		}
	}
	return encryptedText; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText) 
{ 
	string decryptedText ="";

	for (int i=0; i<cipherText.length(); i++)
	{
		int letterValue = int(cipherText[i]) + caesarKey;

		if (letterValue <= 90)
		{
			decryptedText = decryptedText + char(letterValue);
		}
		else
		{
			letterValue = (letterValue - 90) + 64;
			decryptedText = decryptedText + char(letterValue);
		}
	}
	return decryptedText; 
}

