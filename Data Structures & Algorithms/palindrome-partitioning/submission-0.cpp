class Solution {
public:
    bool isPalindrome(string &s,int low,int high){
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void solve(int index,string &s,vector<string>& curr,vector<vector<string>> &res){
        if(index == s.size()){
            res.push_back(curr);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                solve(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        solve(0,s,curr,res);
        return res;
    }
};
