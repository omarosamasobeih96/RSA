from Key import Key, PrivateKey, PublicKey
import Utility
import random


class Generator:

    @staticmethod
    def generate_random_prime(length):
        start = 10**length
        end = 10 * start
        i = random.randrange(start, end * 17 / 19)
        while 1:
            if Utility.is_prime(i):
                return i
            i += 1

    @staticmethod
    def generate_key(length):
        if length < 7:
            e = 17
        else:
            e = 65537
        p = Generator.generate_random_prime(length / 2)
        q = p
        while q == p or ((p - 1) * (q - 1)) % e == 0:
            q = Generator.generate_random_prime(length / 2)
        n = p * q
        totient = (p - 1) * (q - 1)
        d = Utility.mod_inv(e, totient)
        public_key = PublicKey(n, e)
        private_key = PrivateKey(n, d)
        return public_key, private_key
