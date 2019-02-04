from Key import Key, PrivateKey, PublicKey
import Utility
import random


class Generator:

    @staticmethod
    def generate_random_prime(length):
        pr = [19, 31]
        return pr[random.randrange(0, 2)]

    @staticmethod
    def generate_key(length):
        p = Generator.generate_random_prime(length / 2)
        q = p
        while q == p:
            q = Generator.generate_random_prime(length / 2)
        n = p * q
        totient = (p - 1) * (q - 1)
        e = 17
        d = Utility.modular_inverse(e, totient)
        public_key = PublicKey(n, e)
        private_key = PrivateKey(n, d)
        return public_key, private_key
