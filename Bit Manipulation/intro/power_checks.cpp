bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n-1)) == 0;
}

bool isPowerOfFour(int n) {
    return isPowerOfTwo(n) && (n & 0x55555555) != 0;
}