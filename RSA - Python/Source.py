from Generator import Generator
from Encryption import Encryption
from Decryption import Decryption
from Attack import Attack


def main():
    keys = Generator.generate_key(300)

    print("enter message to send")
    message = int(input())

    encrypter = Encryption(keys[0])
    encrypted_message = encrypter.encrypt(message)

    decrypter = Decryption(keys[1])
    decrypted_message = decrypter.decrypt(encrypted_message)

    if message == decrypted_message:
        print("Encryption and Decryption succeeded")
    else:
        print("Encryption or Decryption failed")

    attacker_message, attacker_key = Attack.brute_force_attack(keys[0], encrypted_message)
    print("attack using brute force key = " + str(attacker_key))

    if attacker_message == message:
        print("Brute force attack succeeded")
    else:
        print("Brute force attack failed")

if __name__ == '__main__':
    main()