#include "Railfence.h"
#include <iostream>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
int RailfenceKey;

bool Railfence::setKey(const string& key)
{ 
	//cout << key <<endl;
	RailfenceKey =  stoi(key);
	cout << "Railfence key: "<< RailfenceKey <<endl;
	return false;  
}


/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Railfence::encrypt(const string& plainText)
{ 
	string encryptedText ="";
	int stringLength = plainText.length();
	int rowLength = stringLength / RailfenceKey;
	int extraLetterRows = stringLength % RailfenceKey;
	int index = 0;
	int rowIndex = 0;

	while (encryptedText.length() < plainText.length() )
	{
		if (rowIndex < extraLetterRows)
		{
			for (int i = 0; i < rowLength+1; i++)
			{
				encryptedText = encryptedText + plainText[index];
				index = index + RailfenceKey;
				cout << index<<endl;
			}
			rowIndex++;
			index = rowIndex;
		}
		else
		{
			for (int i = 0; i < rowLength; i++)
			{
				encryptedText = encryptedText + plainText[index];
				index = index + RailfenceKey;
				cout << index<<endl;
			}
			rowIndex++;
			index = rowIndex;
		}
	}

	return encryptedText; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Railfence::decrypt(const string& cipherText) 
{ 
	string decryptedText ="";

	return decryptedText; 
}

