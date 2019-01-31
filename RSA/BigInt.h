#pragma once
class long long
{
public:

	long long value;


	long long() {

	}

	long long (long long value) {
		this->value = value;
	}

	bool operator == (long long rhs) {
		return value == rhs.value;
	}

	bool operator != (long long rhs) {
		return !(*this == rhs);
	}

	long long& operator + (long long rhs) {
		long long sum = value + rhs.value;
		return sum;
	}

	long long& operator - (long long rhs) {
		long long dif = value - rhs.value;
		return dif;
	}

	long long& operator * (long long rhs) {
		long long pro = value * rhs.value;
		return pro;
	}

	long long& operator / (long long rhs) {
		long long quo = value / rhs.value;
		return quo;
	}


	long long& operator % (long long rhs) {
		long long mod = value % rhs.value;
		return mod;
	}
};

