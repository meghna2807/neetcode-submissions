class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26,0);
        int maxi = 0;
        int maxfreq = 0;
        int i=0;
        
        for(int j=0;j<n;j++){
            freq[s[j] - 'A']++;

            maxfreq = max(maxfreq,freq[s[j]-'A']);

            if((j-i+1) - maxfreq > k){
                freq[s[i]-'A']--;
                i++;
            }

            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};
