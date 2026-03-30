class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int maxi = 0;
        int i=0;

        for(int j=0;j<n;j++){
            mpp[s[j]]++;

            for(auto it: mpp){
                if(it.second > 1){
                    mpp[s[i]]--;
                    if(mpp[s[i]] == 0) mpp.erase(s[i]);
                    i++;
                }
            }

            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};
