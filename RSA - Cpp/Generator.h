#pragma once
#include <algorithm>

#include "Utility.h"
#include "Key.h"
using namespace std;

class Generator
{

	static long long generateRandomPrime() {
		//long long pr[] = { 1213 , 3253 , 4093, 5413, 8779 };
		long long pr[] = { 19, 31};
		return pr[rand() % 2];
	}

	static long long generateRandomPrime(long long lowerBound) {
		//return generateRandomPrime();
	}


public:

	static pair<PublicKey, PrivateKey> generateKey() {
		long long p = generateRandomPrime();
		long long q = p;
		while(q == p) q = generateRandomPrime();
		cout << "p = " << p << endl;
		cout << "q = " << q << endl;
		long long n = p * q;
		long long totient = (p - 1) * (q - 1);
		cout << "totient = " << totient << endl;
		long long e = 17;
		long long d = modularInverse(e, totient);
		PublicKey publicKey;
		PrivateKey privateKey;
		publicKey.n = privateKey.n = n;
		publicKey.e = e;
		privateKey.d = d;
		return{ publicKey, privateKey };
	}

};

