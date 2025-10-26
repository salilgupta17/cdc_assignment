// Extended Euclidean Algorithm
int gcdExtended(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

// Modular inverse
int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, x, y);
    if (g != 1) return -1; // inverse doesn't exist
    return (x % m + m) % m;
}

// CRT solver for system of congruences
int crt(const vector<int>& num, const vector<int>& rem) {
    int prod = 1;
    for (int n : num) prod *= n;
    int result = 0;
    for (size_t i = 0; i < num.size(); i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}

/*
Logic: CRT solves simultaneous congruences using modular inverses.
*/