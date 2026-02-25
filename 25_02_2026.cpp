//https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1
class Solution {
public:
    int longestSubarray(vector<int> &arr, int k) {
        int size = arr.size();
        int prefix_sum = 0, max_len = 0;
        unordered_map<int,int> umap;
        umap[0] = -1;
        for(int i=0;i<size;i++){
            if(arr[i]>k) {
                prefix_sum += 1;
            }else{
                prefix_sum -= 1;
            }
            
            if(prefix_sum>0) {
                max_len = i + 1;
            }
            
            if(umap.find(prefix_sum - 1) != umap.end()) {
                max_len = max(max_len,i - umap[prefix_sum-1]);
            }
             
            if(umap.find(prefix_sum) == umap.end()) {
                umap[prefix_sum] = i;
            }
        }
        return max_len;
    }
};
