// https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_time = INT_MIN;
        int lboundary = 0, rboundary = n;
        for(int pos: left) {
            int temp = pos - lboundary;
            max_time = max(max_time,temp);
        }
        for(int pos: right) {
            int temp = rboundary - pos;
            max_time = max(max_time,temp);
        }
        return max_time;
    }
};
