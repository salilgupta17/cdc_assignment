int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int countUnsetBits(int n, int totalBits = 32) {
    return totalBits - countSetBits(n);
}