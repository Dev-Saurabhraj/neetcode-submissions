class TimeMap {
public:
    TimeMap() {
        
    }

    unordered_map<string, vector<pair<string, int>>> store;


    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()) return "";

        auto &v = store[key];

        int start = 0;

        int end = v.size() -1;
        string ans = "";

        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(v[mid].second <= timestamp ){
                ans = v[mid].first;
                start = mid +1;
            }else{
                end = mid -1;
            }

        }
        return ans;

    }
};
