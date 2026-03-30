class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp;

        for(auto it:arr){
            mpp[it]++;
        }

        for(int i=0;i<n;i++){
            if(mpp[arr[i]] > 1) return arr[i];
        }
        return -1;
    }
};
