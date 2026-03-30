class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++) {
            st.insert(arr[i]);
        }
        int maxi = 0;
        
        for(int num:arr) {
            if(st.count(num-1) == 0){
                int curr = num;
                int len = 1;

            while(st.count(curr + 1)) {
                len++;
                curr++;
            }
            maxi = max(maxi,len);
            }
        }
        return maxi;
    }
};
