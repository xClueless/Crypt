#ifndef MD5_HPP
#define MD5_HPP


#include "hash.h"

namespace DistCrack
{
	class MD5 : public Hash
	{
	private:
	public:
		MD5();
		virtual ~MD5();

	public:
		//Algorithm interface
		std::string name();

		// Hash interface
	public:
		std::string hash(const std::string& plaintext);
	};
}

#endif // MD5_HPP
