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
//int* RowTranspositionKey;
//RowTranspositionKey; = new int [counts];

vector<int> vect;



bool RowTransposition::setKey(const string& key)
{ 
	int i;
	stringstream strstream(key);
	while (strstream >> i)
    {
        vect.push_back(i);

        if (strstream.peek() == ',')
            strstream.ignore();
    }

    for (i=0; i< vect.size(); i++)
    	cout << vect.at(i)<<endl;
    
	return false;  
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
	//int rowIndex = 0;
	//int columnIndex = 0; 
	int vectorIndex = 0;

	while (encryptedText.length() < plainText.length() )
	{
		//if (columnIndex < extraLetterColumns)
		if ( (vect.at(vectorIndex) - 1) < extraLetterColumns)
		{
			for (int x = 0; x < columnLength+1; x++)
			{
				index = x * columnAmount + (vect.at(vectorIndex) - 1 );
				encryptedText = encryptedText + plainText[index];
				cout<< index <<" ";
				//rowIndex++;
			}
			vectorIndex++;
			//columnIndex++;
			//rowIndex = 0;
		}
		else
		{
			for (int x = 0; x < columnLength; x++)
			{
				index = x * columnAmount + (vect.at(vectorIndex) - 1 );
				encryptedText = encryptedText + plainText[index];
				cout<< index <<" ";
				//rowIndex++;
			}
			vectorIndex++;
			//columnIndex++;
			//rowIndex = 0;
		}
	}

	cout << stringLength<< " "<< columnAmount <<" " << columnLength<<" "<< extraLetterColumns<< endl;
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

	return decryptedText; 
}

