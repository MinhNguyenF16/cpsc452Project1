#include "Hill.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */

vector<int> hillVect;
//vector<int> hillVect2;
int hillMatrix[2][2];

bool Hill::setKey(const string& key)
{ 
	int i;

	stringstream strstream(key);
	// input the key into a vector
	while (strstream >> i)
    {
        hillVect.push_back(i);
        if (strstream.peek() == ',')
            strstream.ignore();


    }
	return true;
}



/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Hill::encrypt(const string& plainText)
{ 
	string encryptedText ="";
	string newPlainText = "";
	int temp;
	int letter1;
	int letter2;
	int index1=0;
	int index2=1;
	int newLetter1;
	int newLetter2;

	// insert key into matrix
	for (int x=0; x<2; x++)
	{
		for (int y=0; y<2; y++)
		{
			temp = x*2 + y;
			hillMatrix[x][y] = hillVect.at(temp);
		}
	}

	// ensure the plainText string has pairs of 2 letters, if there's an odd letter, add Z to it
	if (plainText.length() % 2 == 1)
		newPlainText = plainText + "Z";
	else
		newPlainText = plainText;

	while (encryptedText.length() < newPlainText.length() )
	{
		letter1 = int(newPlainText[index1]) - 65;
		letter2 = int(newPlainText[index2]) - 65;

		newLetter1 = (letter1 * hillMatrix[0][0] + letter2 * hillMatrix[0][1]) % 26 + 65;
		newLetter2 = (letter1 * hillMatrix[1][0] + letter2 * hillMatrix[1][1]) % 26 + 65;

		encryptedText = encryptedText + char(newLetter1) + char(newLetter2);

		index1 = index1 + 2;
		index2 = index2 + 2;

	}

	return encryptedText; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Hill::decrypt(const string& cipherText) 
{ 
	string decryptedText ="";


	int determinant;
	int k;
	int factor;
	int inverseMatrix[2][2];

	int letter1;
	int letter2;
	int index1=0;
	int index2=1;
	int newLetter1;
	int newLetter2;

	// calculate determinant
	determinant =  hillVect.at(0)*hillVect.at(3) - hillVect.at(1)*hillVect.at(2);
	factor = 27 / determinant;

	// calculate matrix inverse
	inverseMatrix[0][0]= hillVect.at(3) ;
	inverseMatrix[0][1]= -1*hillVect.at(1);
	inverseMatrix[1][0]= -1*hillVect.at(2);
	inverseMatrix[1][1]= hillVect.at(0);

	// calculate and insert inverse matrix into vector
	for (int z=0; z<2; z++)
	{	
		for (int w=0; w<2; w++)
		{
			inverseMatrix[z][w]=(factor*(inverseMatrix[z][w]%26)) %26 ;
			if (inverseMatrix[z][w] < 0)
				inverseMatrix[z][w]= inverseMatrix[z][w] + 26;
		}
	}

	while (decryptedText.length() < cipherText.length() )
	{
		letter1 = int(cipherText[index1]) - 65;
		letter2 = int(cipherText[index2]) - 65;

		newLetter1 = (letter1 * inverseMatrix[0][0] + letter2 * inverseMatrix[0][1]) % 26 + 65;
		newLetter2 = (letter1 * inverseMatrix[1][0] + letter2 * inverseMatrix[1][1]) % 26 + 65;

		decryptedText = decryptedText + char(newLetter1) + char(newLetter2);

		index1 = index1 + 2;
		index2 = index2 + 2;

	}



	return decryptedText; 
}

