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
	PlayfairKey =  key;

	// ensure all key are uppercase
	for (int j=0; j<PlayfairKey.length(); j++)
	{
		PlayfairKey[j] = toupper(PlayfairKey[j]);
	}

	/*
	// reduce the key to have only unique letters
	for (int k=0; k<PlayfairKey.length(); k++)
	{
		duplicate = false; 

		for (int l=0; l<temp.length(); l++)
		{
			if (PlayfairKey[k] == temp[l])
			{
				duplicate = true;
			}
			//temp = temp + PlayfairKey[k];
		}

		if (duplicate == false)
		{
			temp = temp + PlayfairKey[k];
		}
	}
	*/
	cout << "Playfair key: "<< PlayfairKey <<endl;

	return false;  
}

// creating string with unique alphabet letters to prepare for matrix insertion
// void creatingmatrix?
void Playfair::CreateMatrix()
{
	int count = 0;
	keyAndAlpha = PlayfairKey + alpha;

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
			//temp = temp + PlayfairKey[k];
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

	cout << "Filtered Key+alpha (temp): "<< temp <<endl;

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

void Playfair::FindMatrixIndex(char letter, int& row, int& column)
{
	for (int a=0; a<5; a++)
	{
		for (int b=0; b<5; b++)
		{
			if ( letter == playfairMatrix[a][b] )
			{
				cout << playfairMatrix[a][b]<< " ~ row: " << a << " column: " << b << endl;
				//plainTextIndex++;
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
	string newPlainText ="";

	int letterIndex1 = 0;
	int letterIndex2 = 1;

	int row1;
	int column1;
	int row2;
	int column2;

	int plainTextIndex = 0;
	int newPosition;

	// make sure plaintext doesnt have 2 letters in a row
	//int index = 0;
	int counter = 0;

	for (int n=0; n<plainText.length(); n++)
	{
		if (n%2==0) && (plainText[n] == plainText[n+1])
		{
			newPlainText = newPlainText + plainText[n];
			newPlainText = newPlainText + "X";
			counter = counter +2;
		}
		newPlainText = newPlainText + plainText[n];
	}

	/*
	// make sure plainttext has even amount of letters, if not add x at the end
	if ( (plainText.length() % 2) == 1)
	{
		newPlainText = plainText + "X";
	}
	else
	{
		newPlainText = plainText;
	}
	*/


	//while (encryptedText.length() < plainText.length())
	while (plainTextIndex < newPlainText.length())
	{
		// find index of letter
		/*
		for (int a=0; a<5; a++)
		{
			for (int b=0; b<5; b++)
			{
				if ( plainText[plainTextIndex] == playfairMatrix[a][b] )
				{
					cout << playfairMatrix[a][b]<< " ~ row: " << a << " column: " << b << endl;
					plainTextIndex++;
				}
			}
		}
		*/
		FindMatrixIndex( newPlainText[letterIndex1], row1, column1);
		//cout << " * " << plainText[letterIndex1];
		FindMatrixIndex( newPlainText[letterIndex2], row2, column2);
		//cout << " * " << plainText[letterIndex2];

		// letters for same column
		if (column1 == column2)
		{
			// check exception over [5]
			// last letter by itself??
			// make sure i/j works
			// double LL = lx lx
			newPosition = row1+1;
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
	string decryptedText ="";

	return decryptedText; 
	
}

