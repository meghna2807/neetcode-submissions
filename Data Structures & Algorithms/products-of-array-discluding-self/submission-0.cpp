class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> PreProd(n);
        vector<int> SuffProd(n);

        int num1 = 1;
        PreProd[0] = num1;
        for(int i=1;i<n;i++) {
            PreProd[i] = arr[i-1] * num1;
            num1 = PreProd[i];
        }

        int num2 = 1;
        SuffProd[n-1] = num2;
        for(int j=n-2;j>=0;j--) {
            SuffProd[j] = arr[j+1] * num2;
            num2 = SuffProd[j];
        }

        vector<int> ans(n);

        for(int k=0;k<n;k++) {
            ans[k] = PreProd[k] * SuffProd[k];
        }
        return ans;
    }
};
