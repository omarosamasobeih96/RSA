from Generator import Generator
from CommunicatingParty import CommunicatingParty
from PropertyOwner import PropertyOwner
from Attacker import Attacker
import time
import random
import matplotlib.pyplot as plt


def main():
    key_lengths = []
    attack_time = []
    encryption_time = []
    key_length = 4
    ns = []

    while key_length < 10:
        key_lengths.append(key_length)

        keys = Generator.generate_key(key_length)
        ns.append(keys[0].n)
        communicating_party = CommunicatingParty(keys[0])
        property_owner = PropertyOwner(keys[1])

        message = random.randrange(1, keys[0].n)

        millis = time.time() * 1000000

        encrypted_message = communicating_party.encrypt(message)

        millis2 = time.time() * 1000000
        encryption_time.append(millis2 - millis)

        decrypted_message = property_owner.decrypt(encrypted_message)

        assert message == decrypted_message

        attacker_message = Attacker.chosen_cipher_attack(keys[0], encrypted_message, property_owner)
        assert attacker_message == message

        millis = time.time() * 1000

        key = Attacker.brute_force_attack(keys[0])
        assert key == keys[1].d

        millis2 = time.time() * 1000
        attack_time.append(millis2 - millis)

        key_length += 1

    plt.plot(ns, attack_time)
    plt.xlabel("N")
    plt.ylabel("brute force time in micro seconds")
    plt.show()

    while key_length < 300:

        key_lengths.append(key_length)
        keys = Generator.generate_key(key_length)
        communicating_party = CommunicatingParty(keys[0])
        property_owner = PropertyOwner(keys[1])
        print(key_length)

        message = random.randrange(1, keys[0].n)

        millis = time.time() * 1000000

        encrypted_message = communicating_party.encrypt(message)

        millis2 = time.time() * 1000000
        encryption_time.append(millis2 - millis)

        decrypted_message = property_owner.decrypt(encrypted_message)

        assert message == decrypted_message

        key_length += 1

    plt.plot(key_lengths, encryption_time)
    plt.xlabel("key length in decimal radix")
    plt.ylabel("encryption time in micro seconds")
    plt.show()


if __name__ == '__main__':
    main()