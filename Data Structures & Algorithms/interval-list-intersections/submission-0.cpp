class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;
        int i=0;
        int j=0;

        while(i<n && j<m){
            if(firstList[i][0] <= secondList[j][1]){
                if(firstList[i][1] >= secondList[j][0]){
                    ans.push_back({max(firstList[i][0],secondList[j][0]),min(firstList[i][1],secondList[j][1])});
                }
            }

            if(firstList[i][1] < secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};