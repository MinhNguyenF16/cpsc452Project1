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
	stringstream ss(key);
	while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
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

