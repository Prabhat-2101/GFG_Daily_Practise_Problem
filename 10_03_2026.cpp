//https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1
class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int size = arr.size();
        int count = 0;
        stack<int> st;
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]) {
                st.pop();
            }
            if(st.empty()) 
                count += size - i;
            else
                count += st.top() - i;
            st.push(i);
        }
        return count;
    }
};
