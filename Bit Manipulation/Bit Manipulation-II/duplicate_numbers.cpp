vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int,int> freq;
    vector<int> duplicates;
    for(int num : nums){
        freq[num]++;
        if(freq[num] == 2) duplicates.push_back(num);
    }
    return duplicates;
}
/*
Logic: Frequency counting to find duplicates.
*/