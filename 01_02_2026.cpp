#define pii pair<int,int>
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        int size = arr.size();
        
        if(size<k) 
            return res;
        
        priority_queue<pii> pq;
        
        for(int i=0;i<k;i++) {
            pq.push({arr[i],i});
        }
        res.push_back(pq.top().first);
        for(int i=k;i<size;i++){
            while(!pq.empty()) {
                auto [val,loc] = pq.top();
                if(loc<=i and loc>(i-k)) {
                    break;
                }
                pq.pop();
            }
            pq.push({arr[i],i});
            res.push_back(pq.top().first);
        }
        return res;
    }
};
