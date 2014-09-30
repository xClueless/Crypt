#ifndef HASH_H
#define HASH_H

#include "algorithm.h"
#include <hash.h>
#include <experimental/optional>
#include <string>
#include <vector>

namespace DistCrack
{
	class Hash : public Algorithm
	{
	public:
		virtual std::string hash(const std::string& plaintext)=0;
		std::experimental::optional<std::string> bruteforceCharset(const std::string& ciphertext, std::string charset, size_t maxLen);
		std::experimental::optional<std::string> bruteforceVector(const std::string& ciphertext, std::vector<std::string> wordset);
		std::experimental::optional<std::string> bruteforcePermutations(const std::string& ciphertext, std::string set);
	};
}

#endif // HASH_H
