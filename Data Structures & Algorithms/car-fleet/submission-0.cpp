class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> time;
        for(int i = 0; i<n; i++){
            double t = (double)(target - position[i])/speed[i];
            time.push_back({position[i], t});
        }
        sort(time.rbegin(), time.rend());
        double maxi = 0;
        int fleet = 0;
        for(int i = 0; i<n; i++){
            auto p = time[i];
            if(maxi < p.second){
                fleet++;
                maxi = p.second;
            }
        }

        return fleet;
    }
};