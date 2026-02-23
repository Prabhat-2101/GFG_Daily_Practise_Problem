//https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> st;
        for(int it: a) st.insert(it);
        for(int it: b) st.insert(it);
        vector<int> res;
        for(int it: st) 
            res.push_back(it);
        sort(res.begin(),res.end());
        return res;
    }
};
