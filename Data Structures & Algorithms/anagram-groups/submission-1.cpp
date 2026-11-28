class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(string word:strs){
            vector<int> freq(26,0);
            for(int i=0;i<(int)word.size();i++){
                freq[word[i]-'a']++;
            }
            string key = "";
            for(int j=0;j<26;j++){
                key += freq[j];
            }
            
            mpp[key].push_back(word);
        }

        vector<vector<string>> ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
