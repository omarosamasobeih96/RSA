#pragma once
class Key {
public:
	Key() {}
	long long n;
};

class PrivateKey : public Key{
public:
	PrivateKey() {}
	long long d;
};

class PublicKey : public Key {
public:
	PublicKey() {}
	long long e;
};