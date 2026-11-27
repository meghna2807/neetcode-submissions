class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq1(26,0);
        int n = chars.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            freq1[chars[i]-'a']++;
        }

        for(string word:words){
            vector<int> freq2(26,0);
            int cnt = 0;
            int sz = word.size();
            for(int i=0;i<sz;i++){
                freq2[word[i]-'a']++;

                if(freq2[word[i]-'a'] <= freq1[word[i]-'a']){
                    cnt++;
                }
                else{
                    break;
                }
            }

            if(cnt == sz){
                ans += sz;
            }
        }
        return ans;
    }
};