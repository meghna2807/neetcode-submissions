class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int j=0;j<n;j++){


            if(mpp.find(nums[j]) != mpp.end()){
                if(j-mpp[nums[j]] <= k){
                    return true;
                }
            }

            mpp[nums[j]] = j;
        }
        return false;
    }
};