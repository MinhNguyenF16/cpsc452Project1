#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Caesar.h"
#include "Railfence.h"
#include <iostream>
#include <fstream>

using namespace std;

void toUppercase(string& str)
{
	for (int i=0; i<str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

int main(int argc, char** argv)
{
	/* REPLACE THIS PART WITH YOUR CODE 
	 * THE CODE BELOW IS A SAMPLE TO 
	 * ILLUSTRATE INSTANTIATION OF CLASSES
	 * THAT USE THE SAME INTERFACE.
	 */	
	string cipherName = argv[1];
	string key = argv[2];
	string mode = argv[3];
	string inputFile = argv[4];
	string outputFile = argv[5];
	string outputData;

	cout <<cipherName <<key <<mode <<inputFile <<outputFile <<endl;

	// open file and read
	ifstream readFile;
	readFile.open(inputFile.c_str());
	string inputData;	
	readFile >> inputData;
	readFile.close(); 
	toUppercase(inputData); // Converting the data into all uppercase
	cout << "Data received: "<< inputData << endl;
	//cout << char(int('A')) << "  " << int('B')<< "  " << int('c')<<endl;

		
	CipherInterface* cipher = NULL;

	/* Create an instance of the Playfair cipher */	
	//CipherInterface* cipher = new Playfair();
	//cipher = new Playfair();
	//cipher = new Caesar();
	cipher = new Railfence();
	
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key */
	//cipher->setKey("security");
	cipher->setKey(key);
	
	/* Perform encryption */
	if (mode == "ENC")
	{
		string cipherText = cipher->encrypt(inputData);
		cout << "Cipher text: "<< cipherText<<endl;
		outputData = cipherText;
	}
	
	/* Perform decryption */
	else if (mode == "DEC")
	{
		//string plainText = cipher->decrypt(cipherText);
		string plainText = cipher->decrypt(inputData);
		cout << "Plain text: "<< plainText<<endl;
		outputData = plainText;
	}
	else
	{
		cout << "Bad mode enter: ENC or DEC"<< endl;
	}

	// writing output file
	ofstream writeFile;
	//writeFile.open("writingsample.txt");
	//string outputdata = "zzzzzzz";
	//writeFile << outputdata;
	writeFile.open(outputFile);
	writeFile << outputData;
	writeFile.close(); 
	//cout << data << endl;

	
	return 0;
}

