#pragma once
#include "Key.h"
#include "Message.h"
#include "Utility.h"

class Attack
{
public:

	static Message bruteforceAttack(PublicKey key, long long c) {
		long long m = 0;
		while (power(m, key.e, key.n) != c) {
			m = m + 1;
		}
		return m;
	}
	
};

