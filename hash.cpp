#include "hash.h"
#include <algorithm>
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace std::experimental;

namespace DistCrack
{

	optional<string> Hash::bruteforceCharset(const string& ciphertext, string charset, size_t maxLen)
	{
		cout << "Performing charset attack using the " << name() << " algorithm" << endl;

		optional<string> plaintext;

		for(size_t i=1;i<maxLen-1;++i)
		{
			string s = charset.substr(0, i);
			bruteforcePermutations(ciphertext, s);
			sleep(1);
		}
		return plaintext;
	}

	optional<string> Hash::bruteforceVector(const string& ciphertext, vector<string> wordset)
	{
		cout << "Performing vector attack using the " << name() << " algorithm" << endl;
		optional<string> plaintext;
		for(const string& word : wordset)
		{
			cout << "Word: " << word << endl;

			string wordHash = hash(word);
			if(wordHash == ciphertext)
			{
				//The character set we're using produces the ciphertext so it is in fact the plaintext.
				plaintext = word;
				break;
			}
		}
		return plaintext;
	}

	optional<string> Hash::bruteforcePermutations(const string& ciphertext, string set)
	{
		optional<string> plaintext;
		bool hasNextPermutation = true;
		while(hasNextPermutation)
		{
			cout << "[BrutePermu] Set: " << set << endl;
			string permutationHash = hash(set);
			if(permutationHash == ciphertext)
			{
				//The character set we're using produces the ciphertext so it is in fact the plaintext.
				plaintext = set;
				break;
			}
			hasNextPermutation = next_permutation(set.begin(), set.end());
		}
		return plaintext;
	}
}
