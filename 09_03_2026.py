# https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1
class Solution:
    def largestSwap(self, s):
        s = list(s)
        n = len(s)
    
        max_idx = [0] * n
        max_pos = n - 1
    
        for i in range(n - 1, -1, -1):
            if s[i] > s[max_pos]:
                max_pos = i
            max_idx[i] = max_pos
    
        for i in range(n):
            if s[i] < s[max_idx[i]]:
                j = max_idx[i]
                s[i], s[j] = s[j], s[i]
                break
    
        return "".join(s)
        
