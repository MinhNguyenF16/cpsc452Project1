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
	if (RailfenceKey =  stoi(key))
	{
		cout << "Railfence key: "<< RailfenceKey <<endl;
		return true;
	}
	else
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

	// runs through the entire plaintext
	while (encryptedText.length() < plainText.length() )
	{
		// if it's a row w/ extra letter, then do for loop of rowlength+1
		if (rowIndex < extraLetterRows)
		{
			for (int i = 0; i < rowLength+1; i++)
			{
				// apprehend the appropriate char from the plaintext index
				encryptedText = encryptedText + plainText[index];
				// then increment the index by key value 
				index = index + RailfenceKey;
			}

			// increment the row index after a row is finished processing
			rowIndex++;
			index = rowIndex;
		}

		// else it's a regular row, then do for loop of rowlength
		else
		{
			for (int i = 0; i < rowLength; i++)
			{
				// apprehend the appropriate char from the plaintext index
				encryptedText = encryptedText + plainText[index];
				// then increment the index by key value 
				index = index + RailfenceKey;
			}

			// increment the row index after a row is finished processing
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
	
	int stringLength = cipherText.length();
	int rowLength = stringLength / RailfenceKey;
	int extraLetterRows = stringLength % RailfenceKey;
	int index = 0;
	int rowIndex = 0;
	int cycleCount = 0;

	// runs through the entire plaintext
	while (decryptedText.length() < cipherText.length() )
	{
		rowIndex = 0;
		index = cycleCount;

		for (int i = 1; i< RailfenceKey+1; i++)
		{
			if ( decryptedText.length() < cipherText.length() )
			{
				decryptedText = decryptedText + cipherText[index];
			}

			if (rowIndex < extraLetterRows)
			{
				index = index + rowLength + 1  ;
			}
			else
			{
				index = index + rowLength ;
			}
			rowIndex++;
		}

		cycleCount++;
	}

	return decryptedText; 
}

