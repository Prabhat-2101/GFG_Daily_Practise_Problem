// https://www.geeksforgeeks.org/problems/happiest-triplet2921/1
class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        int s1 = a.size(), s2 = b.size(), s3 = c.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i=0,j=0,k=0;
        vector<int> res;
        int diff = INT_MAX;
        while(i<s1 and j<s2 and k<s3){
            int min_ = a[i], min_from = 0;
            int max_ = max(a[i],max(b[j],c[k]));
            if(b[j]<min_) {
                min_ = b[j];
                min_from = 1;
            }
            if(c[k]<min_) {
                min_ = c[k];
                min_from = 2;
            }
            int cdiff = max_ - min_;
            if(cdiff < diff) {
                res = {a[i],b[j],c[k]};
                diff = cdiff;
            }else if(cdiff == diff) {
                int sum = accumulate(res.begin(),res.end(),0);
                if(sum>(a[i]+b[j]+c[k])) {
                    res = {a[i],b[j],c[k]};
                }
            }
            if(min_from==0) i += 1;
            else if(min_from==1) j+=1;
            else k += 1;
        }
        sort(res.begin(),res.end(),greater<int>());
        return res;
    }
};
