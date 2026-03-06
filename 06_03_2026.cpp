//https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
class Solution {
  public:
    int c1[26] = {0}, c2[26] = {0};
    bool match(){
        for(int i=0;i<26;i++) {
            if(c2[i]<c1[i]) 
                return false;
        }
        return true;
    }
    string minWindow(string &s, string &p) {
        for(char ch: p) 
            c1[ch-'a'] += 1;
        int prev = 0, next = 0, min_len = INT_MAX, start = 0;
        while(next < s.length()){
            c2[s[next]-'a'] += 1;
            while(match()) {
                c2[s[prev]-'a'] -= 1;
                int curr_len = next - prev + 1;
                if(curr_len < min_len){
                    min_len = curr_len;
                    start = prev;
                }
                prev += 1;
            }
            next += 1;
        }
        return min_len==INT_MAX?"":s.substr(start,min_len);
    }
};
