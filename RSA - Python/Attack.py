import Utility


class Attack:

    @staticmethod
    def bruteforce_attack(key, intercepted_message):
        message = 0
        while Utility.power(message, key.e, key.n) != intercepted_message:
            message += 1
        return message