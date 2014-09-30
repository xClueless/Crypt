#ifndef SHA512_H
#define SHA512_H

#include "hash.h"

namespace DistCrack
{
	class SHA512 : public Hash
	{
	public:
		SHA512();
		virtual ~SHA512();

	public:
		//Algorithm interface
		std::string name();

		// Hash interface
	public:
		std::string hash(const std::string& plaintext);
	};
}

#endif // SHA512_H
