#!/usr/bin/env python
import sys
def main():
	cipherName = sys.argv[1].upper()
	key = sys.argv[2]
	mode = sys.argv[3].upper()
	inputFile = sys.argv[4]
	outputFile = sys.argv[5]
	print cipherName , key , mode , inputFile , outputFile;
	exit(-1)

main()