//https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1
class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int size = heights.size();
        int min_ = *min_element(heights.begin(),heights.end());
        int max_ = *max_element(heights.begin(),heights.end());
        unsigned int res = INT_MAX;
        auto calculate_cost = [&](int h){
            int curr_cost = 0;
            for(int i=0;i<size;i++) {
                curr_cost += abs(h-heights[i])*cost[i];
            }  
            return curr_cost;
        };
        while(min_<=max_){
            int mid = min_ + (max_ - min_)/2;
            unsigned int curr_cost = calculate_cost(mid);
            unsigned int prev_cost = calculate_cost(mid-1);
            unsigned int next_cost = calculate_cost(mid+1);
            res = min(res,curr_cost);
            if(prev_cost<curr_cost) {
                max_ = mid - 1;
            }else if(next_cost<curr_cost){
                min_ = mid + 1;
            }else{
                break;
            }
        }
        return res;
    }
};
