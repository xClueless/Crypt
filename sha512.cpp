#include "sha512.h"
#include <openssl/sha.h>
#include <string.h>

using namespace std;
using namespace experimental;

namespace DistCrack
{
	SHA512::SHA512()
	{
	}
	SHA512::~SHA512()
	{

	}
	string SHA512::name()
	{
		return "SHA";
	}
	string SHA512::hash(const string& plaintext)
	{
		unsigned char hash[SHA512_DIGEST_LENGTH];
		unsigned char plaintextCStr[plaintext.length()+1];
		memcpy(plaintextCStr, plaintext.c_str(), plaintext.length()+1);

		::SHA512(plaintextCStr, plaintext.length(), hash);
		return string((char*) hash, SHA512_DIGEST_LENGTH);
	}
}
