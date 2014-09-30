#include "cryptutils.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void printByteString(const string& byteString)
{
	stringstream ss;
	ss << hex << "0x";
	for(char c : byteString)
	{
		ss << (unsigned int) c;
	}
	cout << ss.str() << endl;
}

//void printCipherText(std::string& cipherText)
//{
//	int lineEnd;

//	iterator<string> currentByte = cipherText.begin();

//}
