#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Caesar.h"
#include "Railfence.h"
#include "RowTransposition.h"
#include "Vigenere.h"
#include <iostream>
#include <fstream>

using namespace std;

// function to make string all uppercase
void toUppercase(string& str)
{
	for (int i=0; i<str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

int main(int argc, char** argv)
{
	string cipherName = argv[1];
	string key = argv[2];
	string mode = argv[3];
	string inputFile = argv[4];
	string outputFile = argv[5];
	string outputData;

	cout <<cipherName <<key <<mode <<inputFile <<outputFile <<endl;

	// open file and read
	ifstream readFile;
	string inputData;	

	readFile.open(inputFile.c_str());
	readFile >> inputData;
	readFile.close(); 

	toUppercase(inputData); // Converting the data into all uppercase
	cout << "Data received: "<< inputData << endl;
		
	CipherInterface* cipher = NULL;

	/* Create an instance of a cipher */	
	if ( cipherName == "PLF")
		cipher = new Playfair(); // OK
	else if ( cipherName == "RTS")
		cipher = new RowTransposition(); // OK
	else if ( cipherName == "RFC") 
		cipher = new Railfence(); // OK
	else if ( cipherName == "VIG")
		cipher = new Vigenere(); // OK
	else if ( cipherName == "CES")
		cipher = new Caesar(); // OK
	else
	{
		cout << "Incorrect cipher name. Valid names are:" << endl;
		cout << "– PLF: Playfair\n"<<
				"– RTS: Row Transposition\n"<<
				"– RFC: Railfence\n"<<
				"– VIG: Vigenre\n"<<
				"– CES: Caesar\n";
		cout << "Execution: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n";
		exit(-1);
	}

	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key */
	// Shows error message if it returns false (invalid key)
	if (cipher->setKey(key) == false) 
	{
		cout << "Invalid key. Key validations: " << endl;
		cout << "– PLF: String of regular letters. Ex: kingdom...\n"<<
				"– RTS: Separated by (,) integers. Ex: 5,2,1,3,4\n"<<
				"– RFC: An integer. Ex: 4\n"<<
				"– VIG: String of regular letters. Ex: security...\n"<<
				"– CES: An integer 1-25. Ex: 7\n";
		cout << "Execution: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n";
		exit(-1);
	}
	
	/* Perform encryption */
	if (mode == "ENC")
	{
		string cipherText = cipher->encrypt(inputData);
		cout << "Post-Encryption Ciphertext: "<< cipherText<<endl;
		outputData = cipherText;
	}
	
	/* Perform decryption */
	else if (mode == "DEC")
	{
		string plainText = cipher->decrypt(inputData);
		cout << "Post-Decryption Plaintext: "<< plainText<<endl;
		outputData = plainText;
	}
	else
	{
		cout << "Bad mode. Please enter: ENC (encryption) or DEC (decryption)"<< endl;
		cout << "Execution: ./cipher <CIPHER NAME> <KEY> <ENC/DEC> <INPUTFILE> <OUTPUT FILE>\n";
	}

	// writing output file
	ofstream writeFile;
	writeFile.open(outputFile);
	writeFile << outputData;
	writeFile.close(); 

	return 0;
}

