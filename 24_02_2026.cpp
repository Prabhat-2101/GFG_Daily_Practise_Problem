class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int max_ = 0, size = a1.size();
        vector<int> diff(size,0);
        unordered_map<int,int> umap;
        for(int i=0;i<size;i++) diff[i] = a1[i] - a2[i];
        int prefix = 0;
        for(int i=0;i<size;i++){
            prefix += diff[i];
            if(prefix == 0) {
                max_ = i + 1;
            }
            if(umap.find(prefix) != umap.end()){
                max_ = max(max_, i - umap[prefix]);
            }else{
                umap[prefix] = i;
            }
        }
        return max_ ;
    }
};
