#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <sys\stat.h>
using namespace std;

const int OP_ENCRYPT = 0, OP_DECRYPT = 1, BUF_SIZE = 10000;

//--------------------------------------------------------------
size_t getFileSize(char filename[])
{
	struct stat st;
	if (stat(filename, &st) != 0)
	{
		return 0;
	}
	return st.st_size;
}

bool fileExists(char filename[]) {
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}


int Crypt(char src[], char dst[], char key[], int operation)
{
	if (!fileExists(src))
	{
		return 1;
	}
	ifstream srcFile(src, ios::binary);
	char srcBuffer[BUF_SIZE], dstBuffer[BUF_SIZE];
	int srcPos = 0, srcSize = getFileSize(src), keyLen = strlen(key);
	ofstream dstFile(dst, ios::binary);
	while (srcPos < srcSize)
	{
		int bytesToRead = min(srcSize - srcPos, BUF_SIZE);
		srcFile.read(srcBuffer, bytesToRead);
		for (int i = 0; i < bytesToRead; i++)
		{
			if (operation == OP_ENCRYPT)
				dstBuffer[i] = (srcBuffer[i] + key[(srcPos + i)%keyLen]) % 256;
			else//OP_DECRYPT
				dstBuffer[i] = (srcBuffer[i] - key[(srcPos + i) % keyLen] + 256) % 256;
		}
		dstFile.write(dstBuffer, bytesToRead);
		srcPos += bytesToRead;
	}
	srcFile.close();
	dstFile.close();
	return 0;
}

int main(int argc, char *argv[])
{
	//cout << getFileSize("Hydrangeas.jpg") << "\n";
	//Crypt("Hydrangeas.jpg", "Hydrangeas_vigerenere_1.bin", "bhbfxsxrtscsy546574fgrvfg453#@cdc", OP_ENCRYPT);
	//Crypt("Hydrangeas_vigerenere_1.bin", "Hydrangeas_vigenere_1_decrypted.jpg", "bhbfxsxrtscsy546574fgrvfg453#@cdc", OP_DECRYPT);
	//Crypt("rufus-2.11.exe", "rufus-2.11_vigerenere_1.bin", "bhbfxsxrtscsy546574fgrvfg453#@cdc", OP_ENCRYPT);
	//Crypt("rufus-2.11_vigerenere_1.bin", "rufus-2.11_vigenere_1_decrypted.exe", "bhbfxsxrtscsy546574fgrvfg453#@cdc", OP_DECRYPT);
	//system("pause");

	if (argc < 5)
	{
		cout << "Too few arguments!";
		return -1;
	}

	int opCode;
	if (strlen(argv[4]) == 1 && argv[4][0] == '0' || argv[4][0] == '1')
	{
		if (argv[4][0] == '0')
			opCode = OP_ENCRYPT;
		else
			opCode = OP_DECRYPT;
	} else
	{
		cout << "Parsing error!";// << strlen(argv[5]);
		return -1;
	}

	int res = Crypt(argv[1], argv[2], argv[3], opCode);
	if (res != 0)
	{
		if (res == 1)
		{
			cout << "Source file doesn't exist!";
			return -1;
		}
	}
    return 0;
}
