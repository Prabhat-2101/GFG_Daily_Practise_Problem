//https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int size = arr.size();
        unordered_set<int> st;
        for(int &it: arr){
            st.insert(it);
            it = it*it;
        }
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int num = arr[i] + arr[j];
                int root = sqrt(num);
                if(root * root == num){
                    if(st.find(root) != st.end())
                        return true;
                }
            }
        }
        return false;
    }
};
