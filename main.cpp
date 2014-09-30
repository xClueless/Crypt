#include <iostream>

#include "sha512.h"
#include "md5.hpp"
#include "cryptutils.hpp"
#include <experimental/optional>

using namespace std;
using namespace std::experimental;


int main()
{
	cout << "Hello World!" << endl;

	DistCrack::MD5 hashingAlgorithm;
	string cipherText = hashingAlgorithm.hash("sad");
	printByteString(cipherText);

//	optional<string> result = sha.bruteforceCharset(cipherText, "abcdefghijklmnopqrstuvwxyz", 12);

	vector<string> wordset = {"Hello", "world", "This", "is", "a", "wordset", "test", "sad"};

//	optional<string> result = hashingAlgorithm.bruteforceVector(cipherText, wordset);
	optional<string> result = hashingAlgorithm.bruteforcePermutations(cipherText, "abcdefghijklmnopqrstuvwxyz");

	string print = result ? "Hash found: " + *result : "Could not determine plaintext";
	cout << print << endl;

	return 0;
}

