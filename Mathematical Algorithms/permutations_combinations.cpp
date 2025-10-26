int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n-r));
}

int nPr(int n, int r) {
    return factorial(n) / factorial(n-r);
}

/*
Permutations count ordered arrangements; combinations count unordered selections. 
Computing factorials supports both via formulas.
*/