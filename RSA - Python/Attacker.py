import Utility
import random
import math

class Attacker:

    @staticmethod
    # to overcome brute force attck key has to be large enough
    def brute_force_attack(key):
        p = math.ceil(math.sqrt(key.n))
        while key.n % p != 0:
            p -= 1
        q = key.n / p
        totient = (p - 1) * (q - 1)
        return Utility.mod_inv(key.e, totient)

    @staticmethod
    # to overcome chosen cipher text attack never decrypt message and send it back
    def chosen_cipher_attack(key, intercepted_message, property_owner):
        r = random.randrange(1, key.e)
        r %= key.n
        while Utility.gcd(key.n, r) != 1:
            r = random.randrange(1, key.e)
            r %= key.n
        deceiving_message = (Utility.power(r, key.e, key.n) * intercepted_message) % key.n
        signed_message = property_owner.sign(deceiving_message)
        message = (signed_message * Utility.mod_inv(r, key.n)) % key.n
        return message