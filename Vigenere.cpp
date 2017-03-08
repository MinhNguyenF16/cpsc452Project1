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
	//cout << key <<endl;
	VigenereKey =  key;

	// ensure all key are uppercase
	for (int j=0; j<VigenereKey.length(); j++)
	{
		VigenereKey[j] = toupper(VigenereKey[j]);
	}

	//VigenereKey =  key;
	//cout << "Vigenere key: "<< VigenereKey <<endl;
	return false;  
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
			temp = (int(VigenereKey[i]) - 65 ) + (int(plainText[index]) - 65 );
			temp = temp + 65; // put the value into A-Z ASCII range, 65-90
			newChar = char(temp);
			cout << newChar<< " "<< temp<<endl;
			
			encryptedText = encryptedText + newChar;
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
	
	
	return decryptedText; 
}