#include <bits/stdc++.h>
using namespace std;

// Brute force: count 0s,1s,2s and overwrite array
void sortColorsBF(vector<int>& arr) {
    int c0=0, c1=0, c2=0;
    for(int x : arr) {
        if(x == 0) c0++;
        else if(x == 1) c1++;
        else c2++;
    }
    int i=0;
    while(c0--) arr[i++] = 0;
    while(c1--) arr[i++] = 1;
    while(c2--) arr[i++] = 2;
}

// Optimized: three pointers to partition array in one pass
void sortColorsOpt(vector<int>& arr) {
    int l=0, m=0, h=arr.size()-1;
    while(m <= h) {
        if(arr[m] == 0) swap(arr[l++], arr[m++]);
        else if(arr[m] == 1) m++;
        else swap(arr[m], arr[h--]);
    }
}

int main() {
    vector<int> a = {2,0,2,1,1,0};
    sortColorsOpt(a);
    for (int x: a) cout << x << " ";
    cout << "\n";
    return 0;
}

/*
Logic: BF counts and overwrites, O(n).  
Opt partitions using three pointers, O(n) one pass.  
Space: O(1).
*/