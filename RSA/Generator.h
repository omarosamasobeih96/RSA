#pragma once
#include "Key.h"
#include "BigInt.h"
class Generator
{
	static BigInt generateRandomPrime() {

	}

	static BigInt generateParameter_e(BigInt totient) {
		
	}

public:

	static Key generateKey() {
		BigInt p = generateRandomPrime();
		BigInt q = p;
		while(q == p) q = generateRandomPrime();
		BigInt N = p * q;
		BigInt totient = (p - 1) * (q - 1);
		BigInt e = generateParameter_e(totient);

	}

};

