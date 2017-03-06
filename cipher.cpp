#include <string>
#include "CipherInterface.h"
#include "Playfair.h"
#include "Caesar.h"
#include <iostream>
#include <fstream>

using namespace std;

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

	cout <<cipherName <<key <<mode <<inputFile <<outputFile <<endl;

	// open file and read
	ifstream readFile;
	readFile.open(inputFile.c_str());
	string data;
	readFile >> data;
	readFile.close(); 
	cout << data << endl;
		
	CipherInterface* cipher = NULL;

	/* Create an instance of the Playfair cipher */	
	//CipherInterface* cipher = new Playfair();
	//cipher = new Playfair();
	cipher = new Caesar();
	
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key */
	//cipher->setKey("security");
	cipher->setKey("security");
	
	/* Perform encryption */
	string cipherText = cipher->encrypt("hello world");
	cout << cipherText<<endl;
	
	/* Perform decryption */
	string plainText = cipher->decrypt(cipherText);
	cout << plainText<<endl;

	// writing output file
	ofstream writeFile;
	writeFile.open("writingsample.txt");
	string outputdata = "zzzzzzz";
	writeFile << outputdata;
	writeFile.close(); 
	//cout << data << endl;

	
	return 0;
}
