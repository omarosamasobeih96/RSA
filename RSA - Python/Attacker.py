import Utility


class Attacker:

    @staticmethod
    # to overcome brute force attck key has to be large enough
    def brute_force_attack(key, intercepted_message):
        message = 0
        while Utility.power(message, key.e, key.n) != intercepted_message:
            message += 1
        d = 1
        while Utility.power(intercepted_message, d, key.n) != message:
            d += 1
        return message, d