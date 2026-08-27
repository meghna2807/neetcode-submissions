class Solution {
public:
    void solve(string &digits,unordered_map<char,vector<char>> &mpp,int i,string& ans,vector<string> &res){
        if(i == digits.size()){
            res.push_back(ans);
            return;
        }

        vector<char> letter = mpp[digits[i]];
        for(int j=0;j<letter.size();j++){
            ans.push_back(letter[j]);
            solve(digits,mpp,i+1,ans,res);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>> mpp;
        mpp['2'] = {'a','b','c'};
        mpp['3'] = {'d','e','f'};
        mpp['4'] = {'g','h','i'};
        mpp['5'] = {'j','k','l'};
        mpp['6'] = {'m','n','o'};
        mpp['7'] = {'p','q','r','s'};
        mpp['8'] = {'t','u','v'};
        mpp['9'] = {'w','x','y','z'};

        string ans = "";
        vector<string> res;

        if(digits.size() == 0){
            return res;
        }
        solve(digits,mpp,0,ans,res);
        return res;
    }
};
