#pragma once
#include "Key.h"
#include "Message.h"
#include "Utility.h"

class Decryption
{
	PrivateKey key;

public:
	Decryption(PrivateKey key) {
		this->key = key;
	}

	Message Decrypt(long long c) {
		long long m = power(c, key.d, key.n);
		return m;
	}
};

