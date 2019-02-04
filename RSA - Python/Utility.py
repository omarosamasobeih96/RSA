def power(base, exp, mod):
    ans = 1
    base %= mod
    while exp != 0:
        if exp & 1:
            ans = (ans * base) % mod
        exp >>= 1
        base = (base * base) % mod
    return ans


def modular_inverse(u, v):
    u1 = 1
    u3 = u
    v1 = 0
    v3 = v
    flag = 1
    while v3 != 0:
        q = u3 / v3
        t3 = u3 - q * v3
        t1 = u1 + q * v1
        u1 = v1
        v1 = t1
        u3 = v3
        v3 = t3
        flag = 1 - flag
    if flag == 1:
        return u1
    return v - u1


def euclidean_gcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = euclidean_gcd(b % a, a)
        return g, x - (b // a) * y, y


def mod_inv(a, m):
    g, x, y = euclidean_gcd(a, m)
    return x % m