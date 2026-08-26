class Solution {
public:
    void solve(int index,int sum,vector<int>& nums,vector<int>& arr,vector<vector<int>>& res){
        if(sum == 0){
            res.push_back(arr);
            return;
        }
        if(index < 0){
            return;
        }

        if(nums[index] <= sum){
            arr.push_back(nums[index]);
            solve(index,sum-nums[index],nums,arr,res);
            arr.pop_back();
        }

        solve(index-1,sum,nums,arr,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr;
        vector<vector<int>> res;
        solve(n-1,target,nums,arr,res);
        return res;
    }
};
