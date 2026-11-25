# class Solution:
#     def smallestUniqueSubarray(self, nums: List[int]) -> int:
        

from collections import Counter
from typing import List

class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        
        # Two large primes and bases to prevent hash collisions
        MOD1, MOD2 = 10**9 + 7, 10**9 + 9
        BASE1, BASE2 = 1315423911, 2654435761
        
        def has_unique_subarray(length: int) -> bool:
            if length == n:
                return True
            
            h1, h2 = 0, 0
            p1, p2 = 1, 1
            
            # Compute hash for the first window of size `length`
            for i in range(length):
                h1 = (h1 * BASE1 + nums[i]) % MOD1
                h2 = (h2 * BASE2 + nums[i]) % MOD2
                if i > 0:
                    p1 = (p1 * BASE1) % MOD1
                    p2 = (p2 * BASE2) % MOD2
                    
            counts = Counter()
            counts[(h1, h2)] += 1
            
            # Slide the window across the rest of the array
            for i in range(length, n):
                # Remove the leftmost element
                h1 = (h1 - nums[i - length] * p1) % MOD1
                h2 = (h2 - nums[i - length] * p2) % MOD2
                
                # Shift and add the new rightmost element
                h1 = (h1 * BASE1 + nums[i]) % MOD1
                h2 = (h2 * BASE2 + nums[i]) % MOD2
                
                counts[(h1, h2)] += 1
                
            # Check if any subarray hash appeared exactly once
            return any(freq == 1 for freq in counts.values())

        # Binary search for the minimum valid length
        low, high = 1, n
        ans = n
        
        while low <= high:
            mid = (low + high) // 2
            if has_unique_subarray(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
                
        return ans
