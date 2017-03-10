#include "Playfair.h"
#include <iostream>
#include <algorithm>


/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */

char playfairMatrix[5][5];
string PlayfairKey;
string alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // j is same as i
string keyAndAlpha = "";
string temp = "";
bool duplicate = false;

bool Playfair::setKey(const string& key)
{ 
	int charValue;
	PlayfairKey =  key;

	// ensure all key chars are uppercase and valid letters
	for (int j=0; j<PlayfairKey.length(); j++)
	{
		charValue = int(PlayfairKey[j]);
		if (((charValue < 65) || (charValue > 90)) && ((charValue < 97) || (charValue > 122)))
		{
			return false;
		}

		PlayfairKey[j] = toupper(PlayfairKey[j]);
	}

	cout << "Playfair key: "<< PlayfairKey <<endl;

	return true;  
}

// create Playfair Matrix
void Playfair::CreateMatrix()
{
	int count = 0;
	keyAndAlpha = PlayfairKey + alpha;

	// creating string with unique alphabet letters to prepare for matrix insertion
	for (int k=0; k<keyAndAlpha.length(); k++)
	{
		duplicate = false; 

		for (int l=0; l<temp.length(); l++)
		{
			if ( (keyAndAlpha[k] == 'J') && (temp[l] == 'I') )
			{
				duplicate = true;
			}
			else if (keyAndAlpha[k] == temp[l])
			{
				duplicate = true;
			}
		}

		if (duplicate == false)
		{
			if (keyAndAlpha[k] == 'J')
			{
				temp = temp + 'I';
			}
			else
			{
				temp = temp + keyAndAlpha[k];
			}
		}
	}

	// uncomment this line to check the comebined key before matrix insertion
	//cout << "Filtered Key+alpha (temp): "<< temp <<endl;

	// inserting key into matrix
	for (int a=0; a<5; a++)
	{
		for (int b=0; b<5; b++)
		{
			playfairMatrix[a][b] =  temp[count];
			count++;
		}
	}

	//print matrix
	for (int a=0; a<5; a++)
	{
		for (int b=0; b<5; b++)
		{
			cout << playfairMatrix[a][b] <<" | ";		
		}
		cout << endl;
	}
}

// find the value of row and column index for a letter in the matrix
void Playfair::FindMatrixIndex(char letter, int& row, int& column)
{
	for (int a=0; a<5; a++)
	{
		for (int b=0; b<5; b++)
		{
			if ( letter == playfairMatrix[a][b] )
			{
				cout << playfairMatrix[a][b]<< " ~ row: " << a << " column: " << b << endl;
				row = a;
				column = b;
			}
		}
	}
}

/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Playfair::encrypt(const string& plainText)
{ 
	CreateMatrix();

	string encryptedText ="";
	string filteredText ="";
	string newPlainText ="";

	int letterIndex1 = 0;
	int letterIndex2 = 1;

	int row1;
	int column1;
	int row2;
	int column2;

	int plainTextIndex = 0;
	int newPosition;

	int counter = 0;
	int xCounter = 0;

	// make sure all 'J' become 'I'	in plaintext
	for (int q=0; q<plainText.length(); q++)
	{
		if ( plainText[q] == 'J')
			filteredText = filteredText + 'I';
		else
			filteredText = filteredText + plainText[q];
	}

	// make sure plaintext doesnt have 2 letters in a row, if it does, add X to first letter
	for (int n=0; n<filteredText.length(); n++)
	{
		if ((counter%2==0) && (filteredText[counter-xCounter] == filteredText[counter-xCounter+1]))
		{
			newPlainText = newPlainText + filteredText[counter-xCounter];
			newPlainText = newPlainText + "X";
			counter = counter +2;
			xCounter++;
		}
		else
		{
			newPlainText = newPlainText + filteredText[counter-xCounter];
			counter++;
		}
	}
	
	// make sure plainttext has even amount of letters, if not add x at the end of string
	if ( (newPlainText.length() % 2) == 1)
	{
		newPlainText = newPlainText + "X";
	}
	else
	{
		newPlainText = newPlainText;
	}
	
	cout << "new plainText: "<< newPlainText <<endl;

	while (plainTextIndex < newPlainText.length())
	{
		// find index of letter
		FindMatrixIndex( newPlainText[letterIndex1], row1, column1);
		FindMatrixIndex( newPlainText[letterIndex2], row2, column2);

		// rule for letters for same column
		if (column1 == column2)
		{
			newPosition = row1+1;

			// if the new position is over the array limit, bring it back to 0
			if (newPosition == 5)
			{
				newPosition = 0;
			}
			encryptedText = encryptedText + playfairMatrix[newPosition][column1];

			newPosition = row2+1;
			if (newPosition == 5)
			{
				newPosition = 0;
			}
			encryptedText = encryptedText + playfairMatrix[newPosition][column2];
		}
		// rule for letters for the same row
		else if (row1 == row2)
		{
			newPosition = column1+1;
			if (newPosition == 5)
			{
				newPosition = 0;
			}
			encryptedText = encryptedText + playfairMatrix[row1][newPosition];

			newPosition = column2+1;
			if (newPosition == 5)
			{
				newPosition = 0;
			}
			encryptedText = encryptedText + playfairMatrix[row2][newPosition];
		}
		// regular playfair rule
		else
		{
			encryptedText = encryptedText + playfairMatrix[row1][column2];
			encryptedText = encryptedText + playfairMatrix[row2][column1];
		}

		plainTextIndex = plainTextIndex +2;
		letterIndex1 = letterIndex1 + 2;
		letterIndex2 = letterIndex2 + 2;
	}
	return encryptedText; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Playfair::decrypt(const string& cipherText) 
{ 
	CreateMatrix();

	string decryptedText ="";
	string newCipherText ="";

	int newPosition;
	int cipherTextIndex = 0;
	int letterIndex1 = 0;
	int letterIndex2 = 1;
	int row1;
	int column1;
	int row2;
	int column2;


	// make sure all 'J' become 'I'	in plaintext
	for (int q=0; q<cipherText.length(); q++)
	{
		if ( cipherText[q] == 'J')
			newCipherText = newCipherText + 'I';
		else
			newCipherText = newCipherText + cipherText[q];
	}

	while (cipherTextIndex < newCipherText.length())
	{
		FindMatrixIndex( newCipherText[letterIndex1], row1, column1);
		FindMatrixIndex( newCipherText[letterIndex2], row2, column2);

		// rule for letters for same column
		if (column1 == column2)
		{
			newPosition = row1-1;

			// if the new position is -1, bring it back to 4
			if (newPosition == -1)
			{
				newPosition = 4;
			}
			decryptedText = decryptedText + playfairMatrix[newPosition][column1];

			newPosition = row2-1;
			if (newPosition == -1)
			{
				newPosition = 4;
			}
			decryptedText = decryptedText + playfairMatrix[newPosition][column2];
		}
		// rule for letters for the same row
		else if (row1 == row2)
		{
			newPosition = column1-1;
			if (newPosition == -1)
			{
				newPosition = 4;
			}
			decryptedText = decryptedText + playfairMatrix[row1][newPosition];

			newPosition = column2-1;
			if (newPosition == -1)
			{
				newPosition = 4;
			}
			decryptedText = decryptedText + playfairMatrix[row2][newPosition];
		}
		// rule for regular letters
		else
		{
			decryptedText = decryptedText + playfairMatrix[row1][column2];
			decryptedText = decryptedText + playfairMatrix[row2][column1];
		}

		cipherTextIndex = cipherTextIndex +2;
		letterIndex1 = letterIndex1 + 2;
		letterIndex2 = letterIndex2 + 2;
	}

	return decryptedText; 
	
}

