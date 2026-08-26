class Solution {
public:
    void solve(int cnt_1,int cnt_2,int i,int n,string curr,vector<string>& res){
        if(cnt_1 < cnt_2 || cnt_1 > n){
            return;
        }
        if(curr.size() == 2 * n){
            res.push_back(curr);
            return;
        }

        solve(cnt_1+1,cnt_2,i+1,n,curr+'(',res);
        solve(cnt_1,cnt_2+1,i+1,n,curr+')',res);
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> res;
        solve(0,0,0,n,curr,res);
        return res;
    }
};
