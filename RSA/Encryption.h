#pragma once
#include "Key.h"
#include "Message.h"
#include "Utility.h"

class Encryption
{
	PublicKey key;

public:
	Encryption(PublicKey key) {
		this->key = key;
	}

	BigInt Encrypt(Message m) {
		BigInt c = power(m, key.e, key.n);
		return c;
	}

};

