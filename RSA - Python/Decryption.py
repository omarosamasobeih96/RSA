import Utility


class Decryption:

    def __init__(self, key):
        self.key = key

    def decrypt(self, message):
        return Utility.power(message, self.key.d, self.key.n)