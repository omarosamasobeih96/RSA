#pragma once
#include <algorithm>

#include "Key.h"
#include "BigInt.h"

using namespace std;

class Generator
{
	static BigInt eGCD(BigInt r0, BigInt r1, BigInt &x0, BigInt &y0) {
		BigInt x1 = y0 = 0, y1 = x0 = 1;
		while (r1 != 0) {
			BigInt r = r0 / r1;
			BigInt t = r0 - r * r1;
			r0 = r1;
			r1 = t;
			t = x0 - r * x1;
			x0 = x1;
			x1 = t;
			t = y0 - r * y1;
			y0 = y1;
			y1 = t;
		}
		return r0;
	}

	static BigInt generateRandomPrime() {

	}

	static BigInt generateRandomPrime(BigInt lowerBound) {

	}

	static BigInt generateParameter_e(BigInt totient) {
		// return generateRandomPrime(totient);
		BigInt e[] = { 3,5,17,257,65537 };
		return e[rand() % 5];
	}

	static BigInt generateParameter_d(BigInt e, BigInt totient) {
		BigInt k, d;
		eGCD(e, totient, k, d);
		return d;
	}


public:

	static pair<PublicKey, PrivateKey> generateKey() {
		BigInt p = generateRandomPrime();
		BigInt q = p;
		while(q == p) q = generateRandomPrime();
		BigInt n = p * q;
		BigInt totient = (p - 1) * (q - 1);
		BigInt e = generateParameter_e(totient);
		BigInt d = generateParameter_d(e, totient);
		PublicKey publicKey;
		PrivateKey privateKey;
		publicKey.n = privateKey.n = n;
		publicKey.e = e;
		privateKey.d = d;
		return{ publicKey, privateKey };
	}

};

