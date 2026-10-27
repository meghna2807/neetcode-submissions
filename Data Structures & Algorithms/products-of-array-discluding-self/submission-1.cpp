class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        int leftProd = nums[0];
        left[0] = 1;
        for(int i=1;i<n;i++){
            left[i] = leftProd;
            leftProd *= nums[i];
        }

        vector<int> right(n);
        int rightProd = nums[n-1];
        right[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            right[i] = rightProd;
            rightProd *= nums[i];
        }

        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = (left[i] * right[i]);
        }
        return ans;
    }
};
