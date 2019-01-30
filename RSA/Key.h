#pragma once
class Key {
public:
	Key() {}
	BigInt n;
};

class PrivateKey : public Key{
public:
	PrivateKey() {}
	BigInt d;
};

class PublicKey : public Key {
public:
	PublicKey() {}
	BigInt e;
};