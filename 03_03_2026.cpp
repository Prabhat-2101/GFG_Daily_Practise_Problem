//https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        unordered_map<int,int> umap;
        int size = arr.size();
        int st = 0, mx = 0;
        for(int i=0;i<size;i++){
            umap[arr[i]] += 1;
            if(umap.size()<=2){
                mx = max(mx,i - st + 1);
            }else{
                while(st<=i and umap.size()>2) {
                    umap[arr[st]] -= 1;
                    if(umap[arr[st]] == 0)
                        umap.erase(arr[st]);
                    st += 1;
                }
            }
        }
        return mx;
    }
};
