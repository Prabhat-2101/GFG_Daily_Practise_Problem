
class Solution {
  public:
    int merge(vector<int>& arr,int low, int mid, int high){
        int count = 0;
        int st1 = low, st2 = mid + 1;
        vector<int> temp;
        while(st1<=mid && st2<=high){
            if(arr[st1]<=arr[st2]){
                temp.push_back(arr[st1]);
                st1 += 1;
            }else{
                temp.push_back(arr[st2]);
                st2 += 1;
                count += (mid-st1) + 1;
            }
        }
        while(st1<=mid){
            temp.push_back(arr[st1]);
            st1 += 1;
        }
        while(st2<=high){
            temp.push_back(arr[st2]);
            st2 += 1;
        }
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
        return count;
    }
    int mergesort(vector<int>& arr, int low, int high){
        if(low>=high) return 0;
        int mid = low + (high - low)/2;
        int left = mergesort(arr,low,mid);
        int right = mergesort(arr,mid+1,high);
        int m = merge(arr,low,mid,high);
        return left + right + m;
    }
    int inversionCount(vector<int> &arr) {
        int low = 0, high = arr.size()-1;
        return mergesort(arr,low,high);
    }
};
