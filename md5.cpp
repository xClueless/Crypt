#include "md5.hpp"
#include <string.h>
#include <openssl/md5.h>

using namespace std;

namespace DistCrack
{
	MD5::MD5()
	{
	}
	MD5::~MD5()
	{

	}
	string MD5::name()
	{
		return "MD5";
	}
	std::string MD5::hash(const std::string& plaintext)
	{
		unsigned char hash[MD5_DIGEST_LENGTH];
		unsigned char plaintextCStr[plaintext.length()+1];
		memcpy(plaintextCStr, plaintext.c_str(), plaintext.length()+1);

		::MD5(plaintextCStr, plaintext.length(), hash);
		return string((char*) hash, MD5_DIGEST_LENGTH);
	}
}
