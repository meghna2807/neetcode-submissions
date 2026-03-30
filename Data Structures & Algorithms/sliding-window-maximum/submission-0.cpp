class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> ans;
        deque<int> dq;

        for(int j=0;j<n;j++){
            while(!dq.empty() && arr[dq.back()] < arr[j]) {
                dq.pop_back();
            }

            dq.push_back(j);

            if(dq.front() <= j-k){
                dq.pop_front();
            }

            if(j>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};
