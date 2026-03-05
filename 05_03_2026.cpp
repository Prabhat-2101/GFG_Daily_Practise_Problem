//https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution {
  public:
    int longestKSubstr(string &arr, int k) {
        int max_ = -1, start = 0;
        int size = arr.size();
        unordered_map<int,int> umap;
        set<int> st;
        for(int end=0;end<size;end++){
            umap[arr[end]] += 1;
            if(umap.size()==k){
                max_ = max(max_, end - start + 1);
            }else if(umap.size()>k){
                while(start<=end){
                    if(umap.size()<=k) break;
                    umap[arr[start]] -= 1;
                    if(umap[arr[start]]==0){
                        umap.erase(arr[start]);
                    }
                    start += 1;
                }
            }
        }
        return max_;
    }
};
