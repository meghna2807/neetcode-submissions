class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash(26,0);

        if(s.size() != t.size()) return false;

        for(int i=0;i<s.size();i++) {
            hash[s[i] - 'a']++;
        }

        for(int i=0;i<t.size();i++) {
            hash[t[i] - 'a']--;
        }

        for(int j=0;j<hash.size();j++) {
            if(hash[j] != 0) {
                return false;
            }
        }
        return true;
    }
};
