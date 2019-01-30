#pragma once
#include "Key.h"
#include "Message.h"
#include "Utility.h"

class Attack
{
public:

	static Message bruteforceAttack(PublicKey key, BigInt c) {
		BigInt m = 0;
		while (power(m, key.e, key.n) != c) {
			m = m + 1;
		}
		return m;
	}
	
};

