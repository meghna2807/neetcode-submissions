class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int> arr,vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(arr);
            return;
        }

        arr.push_back(nums[i]);
        solve(i+1,nums,arr,res);
        arr.pop_back();
        solve(i+1,nums,arr,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        solve(0,nums,arr,res);
        return res;
    }
};
