class Solution {

    bool canEat(int k, int h, vector<int>& piles){
        int hours = 0;
        for(int p : piles){
            if(k!=0){
            hours+= p/k;
            }
            if(p%k) hours+=1;
    
            if(hours > h) return false;
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = piles[0];

        for(int i : piles) end = max(end, i);

        int ans = 0;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(canEat(mid, h, piles)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;

    }
};