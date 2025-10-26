int modAdd(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int modMul(int a, int b, int m) {
    return ((a % m) * (b % m)) % m;
}