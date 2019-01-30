#pragma once
#include "BigInt.h"

BigInt power(BigInt base, BigInt exp, BigInt mod) {
	BigInt ans = 1;
	base = base % mod;

	while (exp != 0) {
		if (exp % 2 == 1) ans = (ans * base) % mod;
		exp = exp / 2;
		base = (base * base) % mod;
	}

	return ans;
}
