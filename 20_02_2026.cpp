class Solution {
  public:
    static bool compare(int &i, int &j){
        return to_string(i)+to_string(j) > to_string(j)+to_string(i);
    }
    string findLargest(vector<int> &arr) {
        sort(arr.begin(),arr.end(),compare);
        string res = "";
        for(int it: arr){
            res += to_string(it);
        }
        return res[0]=='0'?"0":res;
    }
};
