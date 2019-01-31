#include <iostream>

#include "Generator.h"
#include "Encryption.h"
#include "Decryption.h"
#include "Attack.h"

using namespace std;

int main() {
	pair<PublicKey, PrivateKey> keys = Generator::generateKey();

	cout << "Public key e = " << keys.first.e << endl;

	cout << "Private key d = " << keys.second.d << endl;

	cout << "Key N = " << keys.first.n << endl;


	cout << "Enter integer message to send to the other party" << endl;

	long long m;
	cin >> m;

	Encryption enc(keys.first);
	long long cEncryptedMessage = enc.Encrypt(m);

	Decryption dec(keys.second);
	Message mDecryptedMessage = dec.Decrypt(cEncryptedMessage);

	cout << "Sender message = " << m << endl;

	cout << "Encrypted message = " << cEncryptedMessage << endl;

	cout << "Decrypted message = " << mDecryptedMessage.message << endl;

	cout << (mDecryptedMessage.message == m ? "Encryption and Decryption succeeded" : "Failed to restore message") << endl;

	Message attacker_m = Attack::bruteforceAttack(keys.first, cEncryptedMessage);

	cout << "Attacker message = " << attacker_m.message << endl;

	cout << (attacker_m.message == m ? "Attacker succeeded to decrypt message" : "Attacker failed to decrypt message") << endl;
}