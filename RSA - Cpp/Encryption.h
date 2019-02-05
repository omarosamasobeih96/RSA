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

	long long Encrypt(Message m) {
		long long c = power(m.message, key.e, key.n);
		return c;
	}

};

