class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int last = intervals[0][1];
        int cnt = 0;

        for(int i=1;i<n;i++){
            if(last > intervals[i][0]){
                cnt++;
                last = min(last,intervals[i][1]);
            }
            else{
                last = intervals[i][1];
            }
        }
        return cnt;
    }
};
