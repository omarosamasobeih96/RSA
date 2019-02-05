from Generator import Generator
from CommunicatingParty import CommunicatingParty
from PropertyOwner import PropertyOwner
from Attacker import Attacker


def main():
    keys = Generator.generate_key(300)
    print("n = " + str(keys[0].n))

    print("enter message to send")
    message = int(input())

    encrypter = CommunicatingParty(keys[0])
    encrypted_message = encrypter.encrypt(message)

    decrypter = PropertyOwner(keys[1])
    decrypted_message = decrypter.decrypt(encrypted_message)

    if message == decrypted_message:
        print("Encryption and Decryption succeeded")
    else:
        print("Encryption or Decryption failed")

    attacker_message = Attacker.chosen_cipher_attack(keys[0], encrypted_message, decrypter)
    if attacker_message == message:
        print("Chosen cipher attack succeeded")
    else:
        print("Chosen cipher attack failed")

    attacker_message = Attacker.brute_force_attack(keys[0], encrypted_message)
    if attacker_message == message:
        print("Brute force attack succeeded")
    else:
        print("Brute force attack failed")

if __name__ == '__main__':
    main()