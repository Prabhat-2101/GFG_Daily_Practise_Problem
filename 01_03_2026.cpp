//https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int prev = 0, curr = 0;
        int size = arr.size();;
        while(curr<size) {
            if(arr[curr] != 0) {
                swap(arr[curr],arr[prev]);
                prev += 1;
            }
            curr += 1;
        }
        while(prev<size){
            arr[prev] = 0;
            prev += 1;
        }
    }
};
