//https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        vector<int> mp1(26,-1), mp2(26,-1);
        int length = s1.length();
        for(int i=0;i<length;i++){
            int ch1 = s1[i] - 'a', ch2 = s2[i] - 'a';
            if(mp1[ch1] == ch2) 
                continue;
            if(mp1[ch1] != -1 || mp2[ch2] != -1)
                return false;
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};
