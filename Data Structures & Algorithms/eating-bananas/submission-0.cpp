class Solution {
public:
    bool canEat(vector<int>& piles,int h,int mid){
        int n = piles.size();
        int total = 0;

        for(int i=0;i<n;i++){
            total += ceil((double)piles[i]/mid);
        }

        if(total <= h) return true;
        return false;
    }

    int maximum(vector<int>& piles){
        int n = piles.size();
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low=1;
        int high=maximum(piles);
        int ans = high;

        while(low<=high){
            int mid = low+(high-low)/2;

            if(canEat(piles,h,mid)){
                ans = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
