class Solution:
    def sum_digits(self, n):
        s = 0
        while n>0:
            s += n%10
            n //= 10
        return s
    
    def getCount(self, n, d):
        if n<=9:
            return 0;
        
        left, right = 1, n
        start = -1
        
        while left <= right:
            mid = (left + right) // 2
            
            if mid - self.sum_digits(mid) >= d:
                start = mid
                right = mid - 1
            else:
                left = mid + 1
        
        if start == -1:
            return 0
        
        return n - start + 1
