class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size();
        int m = abbr.size();
        int i=0;
        int j=0;

        while(i<n && j<m){
            if(!isdigit(abbr[j])){
                if(abbr[j] == word[i]){
                    i++;
                    j++;
                }
                else{
                    return false;
                }
            }
            else{
                if(abbr[j] == '0'){
                    return false;
                }

                int val = 0;
                while(j<m && isdigit(abbr[j])){
                    val = val*10+(abbr[j] - '0');
                    j++;
                }

                i += val;
                if(i>n) return false;
            }
        }

        return i==n && j==m;
    }
};