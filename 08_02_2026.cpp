//https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        int left = INT_MIN, right = INT_MIN;
        int size = arr.size();
        int prod = 1;
        for(int i=0;i<size;i++){
            prod *= arr[i];
            left = max(left,prod);
            if(prod == 0) 
                prod = 1;
        }
        prod = 1;
        for(int i=size-1;i>=0;i--){
            prod *= arr[i];
            right = max(right,prod);
            if(prod == 0)
                prod = 1;
        }
        return max(left,right);
    }
};
