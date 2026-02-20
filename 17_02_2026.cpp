//https://www.geeksforgeeks.org/problems/intersecting-intervals/1
class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        int maxv = INT_MIN, minv = INT_MAX;
        for(auto it: arr) {
            int st = it[0], end = it[1];
            maxv = max(maxv,end);
            minv = min(st,minv);
        }
        vector<int> count(maxv-minv+2,0);
        for(auto it: arr){
            int st = it[0], end = it[1];
            count[st-minv] += 1;
            count[end-minv+1] -= 1;
        }
        for(int i=1;i<count.size();i++){
            count[i] += count[i-1];
        }
        return *max_element(count.begin(),count.end());
    }
};
