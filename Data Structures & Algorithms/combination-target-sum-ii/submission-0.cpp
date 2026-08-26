#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i,int sum,vector<int>& candidates,vector<int> curr,vector<vector<int>>& res){
       if(sum == 0){
        res.push_back(curr);
        return;
       }
        
      for(int j=i;j<candidates.size();j++){
        if(j > i && candidates[j] == candidates[j-1]){
            continue;
        }

        if(candidates[j] > sum){
            break;
        }

        curr.push_back(candidates[j]);
        solve(j+1,sum-candidates[j],candidates,curr,res);
        curr.pop_back();
      }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> curr;
        vector<vector<int>> res;
        solve(0,target,candidates,curr,res);
        return res;
    }
};
