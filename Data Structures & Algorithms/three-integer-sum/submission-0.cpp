class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++) {
            int num = arr[i];
            int target = -num;
            if(i>0 && arr[i] == arr[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = arr[j]+arr[k];
                if(sum == target) {
                    ans.push_back({arr[i],arr[j],arr[k]});

                    while(j<k && arr[j] == arr[j+1]) j++;
                    while(j<k && arr[k] == arr[k-1]) k--;

                    j++;
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};
