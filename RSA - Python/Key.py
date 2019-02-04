class Key:

    def __init__(self, n):
        self.n = n


class PublicKey(Key):

    def __init__(self, n, e):
        Key.__init__(self, n)
        self.e = e


class PrivateKey(Key):

    def __init__(self, n, d):
        Key.__init__(self, n)
        self.d = d