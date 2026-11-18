class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen(nums.begin(),nums.end());
        int maxi = 0;

        for(int i=0;i<n;i++){
            int cnt = 1;
            int num = nums[i];

            if(seen.find(num-1) != seen.end()){
                continue;
            }

            while(seen.find(num+1) != seen.end()){
                cnt++;
                num = num+1;
            }

            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};
