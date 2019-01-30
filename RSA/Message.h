#pragma once
#include "BigInt.h"

class Message
{
	BigInt message;
public:
	Message();
	Message(BigInt message) {
		this->message = message;
	}
	~Message();
};

