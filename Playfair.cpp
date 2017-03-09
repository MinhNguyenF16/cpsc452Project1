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

	int letterIndex1 = 0;
	int letterIndex2 = 1;

	int row1;
	int column1;
	int row2;
	int column2;

	int plainTextIndex = 0;

	//while (encryptedText.length() < plainText.length())
	while (plainTextIndex < plainText.length())
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
		FindMatrixIndex( plainText[letterIndex1], row1, column1);
		FindMatrixIndex( plainText[letterIndex2], row2, column2);

		// letters for same column
		if (column1 == column2)
		{
			encryptedText = encryptedText + playfairMatrix[row1+1][column1];
			encryptedText = encryptedText + playfairMatrix[row1+1][column1];
		}


		//textIndex = FindMatrixIndex(plainText[plainTextIndex]);
		//cout<< "..." << textIndex<< endl;
		plainTextIndex++;

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

