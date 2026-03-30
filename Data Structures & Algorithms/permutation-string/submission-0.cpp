class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freq(26,0);
        int i=0;

        for(int k=0;k<s1.size();k++){
            freq[s1[k]-'a']++;
        }

        int size = s1.size();
        int count = size;

        for(int j=0;j<s2.size();j++){
            freq[s2[j]-'a']--;

            if(freq[s2[j]-'a']>=0){
                count--;
            }

            if(j-i+1 > size){
                freq[s2[i]-'a']++;
                if(freq[s2[i]-'a']>0){
                    count++;
                }
                i++;
            }

            if(count == 0) return true;
        }
        return false;
    }
};
