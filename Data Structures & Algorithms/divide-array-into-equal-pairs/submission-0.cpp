class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        int pairs = n/2;

        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        int cnt = 0;
        for(auto it:mpp){
            cnt += it.second/2;
        }

        return cnt == pairs;
    }
};