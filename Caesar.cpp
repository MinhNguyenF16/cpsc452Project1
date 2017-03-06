#include "Caesar.h"
#include <iostream>

using namespace std;

/**
 * Sets the key to use
 * @param key - the key to use
 * @return - True if the key is valid and False otherwise
 */
bool Caesar::setKey(const string& key)
{ 
	cout << key <<endl;
	int numericKey =  stoi(key);
	cout << numericKey <<endl;
	return false;  
}




/**	
 * Encrypts a plaintext string
 * @param plaintext - the plaintext string
 * @return - the encrypted ciphertext string
 */
string Caesar::encrypt(const string& plaintext)
{ 
	// ASCII value: A = 65, B = 66 ... Z = 90 
	cout << plaintext<<endl;
	for (int i=0; i<plaintext.length(); i++)
	{
		//if ( int(plaintext[i]) - key ) >= 65 )


	}
	return "testingencyption11"; 
}

/**
 * Decrypts a string of ciphertext
 * @param cipherText - the ciphertext
 * @return - the plaintext
 */
string Caesar::decrypt(const string& cipherText) 
{ 
	cout << cipherText << endl;
	return "testingdecyption22"; 
	
}

