class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<double> time(n);

        for(int i=0;i<n;i++){
            time[i] = (double)(target-position[i])/speed[i];
        }

        vector<pair<int,double>> comb(n);

        for(int i=0;i<n;i++){
            comb[i] = {position[i],time[i]};
        }

        sort(comb.begin(),comb.end(),greater<pair<int,double>>());

        int fleet = 0;
        stack<double> st;

        for(int i=0;i<n;i++){
            if(st.empty() || comb[i].second > st.top()){
                fleet++;
                st.push(comb[i].second);
            }
        }
        return fleet;
    }
};
