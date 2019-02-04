	#pragma once
using namespace std;

long long power(long long base, long long exp, long long mod) {
	long long ans = 1;
	base %= mod;

	while (exp != 0) {
		if (exp & 1) ans = (ans * base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}

	return ans;
}

long long modularInverse(long long u, long long v)
{
	long long u1 = 1, u3 = u, v1 = 0, v3 = v, t1, t3, q;
	bool iter = 1;
	while (v3 != 0) {
		q = u3 / v3;
		t3 = u3 - q * v3;
		t1 = u1 + q * v1;
		u1 = v1; v1 = t1; u3 = v3; v3 = t3;
		iter = !iter;
	}
	if (iter) return u1;
	return v - u1;
}