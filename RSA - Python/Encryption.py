import Utility


class Encryption:

    def __init__(self, key):
        self.key = key

    def encrypt(self, message):
        return Utility.power(message, self.key.e, self.key.n)