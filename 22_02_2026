//https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int,int> umap;
        long count = 0, xor_ = 0;
        umap[0] = 1;
        for(int i=0;i<arr.size();i++){
            xor_ ^= arr[i];
            int target = k ^ xor_;
            if(umap.find(target) != umap.end()) {
                count += umap[target];
            }
            umap[xor_] += 1;
        }
        return count;
    }
};
