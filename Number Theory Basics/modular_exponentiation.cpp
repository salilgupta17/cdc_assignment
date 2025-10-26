int modExp(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (int)((1LL * result * base) % mod);
        base = (int)((1LL * base * base) % mod);
        exp >>= 1;
    }
    return result;
}

/*
Logic: Compute base^exp mod mod in O(log exp) time by repeated squaring.
*/