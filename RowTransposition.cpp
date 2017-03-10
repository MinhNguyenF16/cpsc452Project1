#include "RowTransposition.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */

vector<int> vect;

bool RowTransposition::setKey(const string& key)
{ 
	int i;
	stringstream strstream(key);
	// input the key into a vector
	while (strstream >> i)
    {
        vect.push_back(i);
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
string RowTransposition::encrypt(const string& plainText)
{ 
	string encryptedText ="";

	int stringLength = plainText.length();
	int columnAmount = vect.size();
	int columnLength = stringLength / columnAmount;
	int extraLetterColumns = stringLength % columnAmount;
	int index = 0;
	int vectorIndex = 0;

	while (encryptedText.length() < plainText.length() )
	{
		if ( (vect.at(vectorIndex) - 1) < extraLetterColumns)
		{
			for (int x = 0; x < columnLength+1; x++)
			{
				index = x * columnAmount + (vect.at(vectorIndex) - 1 );
				encryptedText = encryptedText + plainText[index];
				//cout<< index <<" ";
			}
			vectorIndex++;
		}
		else
		{
			for (int x = 0; x < columnLength; x++)
			{
				index = x * columnAmount + (vect.at(vectorIndex) - 1 );
				encryptedText = encryptedText + plainText[index];
				//cout<< index <<" ";
			}
			vectorIndex++;
		}
	}
	//cout << stringLength<< " "<< columnAmount <<" " << columnLength<<" "<< extraLetterColumns<< endl;
	return encryptedText; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string RowTransposition::decrypt(const string& cipherText) 
{ 
	string decryptedText ="";

	int stringLength = cipherText.length();
	int columnAmount = vect.size(); // amount of columns
	int columnLength = stringLength / columnAmount;
	int extraLetterColumns = stringLength % columnAmount;

	// create dynamic array to prepare for the letters insertion
	string *arr = new string[columnAmount];
	string tempStr = "";
	int index = 0;

	for (int j = 0; j < columnAmount; j++)
	{
		if (vect.at(j) < extraLetterColumns+1)
		{
			//cout << "vector val: " << vect.at(j)<<endl;
			for (int a = 0; a < columnLength+1; a++)
			{
				//cout << "index : "<< index << endl;
				tempStr = tempStr + cipherText[index];	
				index++;		
			}
			arr[(vect.at(j)-1)] = tempStr;
			tempStr="";
		}
		else
		{
			//cout << "vector val: " << vect.at(j)<<endl;
			for (int a = 0; a < columnLength; a++)
			{
				//cout << "index : "<< index << endl;
				tempStr = tempStr + cipherText[index]; 
				index++;
			}
			arr[(vect.at(j)-1)] = tempStr;
			tempStr="";
		}

	}

	for (int p=0; p<columnAmount; p++)
	{
		tempStr = tempStr + arr[p];
	}
	//cout << "temp: " << tempStr <<endl;

	int strIndex = 0;
	int rowIndex = 0;
	int cycleCount = 0;

	while (decryptedText.length() < tempStr.length() )
	{
		rowIndex = 0;
		strIndex = cycleCount;

		for (int y = 0; y<columnAmount; y++)
		{
			if (decryptedText.length() < tempStr.length())
			{
				decryptedText = decryptedText+ tempStr[strIndex];
				//cout << "strindex: " << strIndex << endl;
			}
			if ( rowIndex < extraLetterColumns ) 
			{
				strIndex = strIndex + columnLength + 1;
			}
			else
			{
				strIndex = strIndex + columnLength;
			}
			rowIndex++;
		}
		cycleCount++;
	}
	delete [] arr;

	return decryptedText; 
}

