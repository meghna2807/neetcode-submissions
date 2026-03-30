class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n);
        vector<int>rightMax(n);

        leftMax[0] = arr[0];
        for(int i=1;i<n;i++){
            leftMax[i] = max(arr[i],leftMax[i-1]);
        }

        rightMax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(arr[i],rightMax[i+1]);
        }

        int total = 0;
        for(int i=0;i<n;i++){
            int boundary = min(leftMax[i],rightMax[i]);
            total += boundary - arr[i];
        }
        return total;
    }
};
