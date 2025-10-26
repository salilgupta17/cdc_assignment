// XOR of all elements gives single number
int singleNumber1(vector<int>& nums) {
    int res = 0;
    for(int num : nums) res ^= num;
    return res;
}
/*
Logic: XOR of pairs cancels out, leaving unique element.
*/