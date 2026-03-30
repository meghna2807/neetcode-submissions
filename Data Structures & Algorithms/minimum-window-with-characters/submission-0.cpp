class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128,0);
        vector<int> window(128,0);

        for(char c:t){
            need[c]++;
        }

        int required = 0;
        for(int i=0;i<128;i++){
            if(need[i] > 0) required++;
        }

        int i=0;
        int minLen = INT_MAX;
        int formed = 0;
        int start = 0;

        for(int j=0;j<s.size();j++){
            window[s[j]]++;

            if(window[s[j]]==need[s[j]]){
                formed++;
            }

            while(formed==required){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    start = i;
                }

                window[s[i]]--;

                if(window[s[i]]<need[s[i]]){
                    formed--;
                }
                i++;
            }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(start,minLen);
    }
};
