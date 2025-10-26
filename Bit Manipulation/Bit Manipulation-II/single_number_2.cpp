int singleNumber2(vector<int>& nums) {
    int result = 0; 
    for(int i=0; i<32; i++){
        int sum = 0;
        for(int num : nums){
            sum += (num >> i) & 1;
        }
        sum %= 3;
        if(sum != 0) result |= (sum << i);
    }
    return result;
}
/*
Logic: Count bits in each position; bits modulo 3 belongs to unique number.
*/