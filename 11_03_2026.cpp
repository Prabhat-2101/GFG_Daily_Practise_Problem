//https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1
class Solution {
  public:
    const int MOD = 1e9 + 7;
    int sumSubMins(vector<int> &arr) {
        int size = arr.size();
        long long sum = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<size;i++){
            while(st.top() != -1 and arr[i]<=arr[st.top()]){
                int mid = st.top(); st.pop();
                int next = st.top();
                sum += (1LL*(mid-next)*(i-mid)*arr[mid]);
            }
            st.push(i);
        }
        while(st.top() != -1){
            int mid = st.top(); st.pop();
            int next = st.top();
            sum += (1LL*(mid-next)*(size-mid)*arr[mid]);
        }
        return sum;
    }
};
