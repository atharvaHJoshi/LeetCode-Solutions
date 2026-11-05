import bisect

class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        distance_value = 0
        
        for val in arr1:
            # Find the position where 'val - d' would fit in arr2
            idx = bisect.bisect_left(arr2, val - d)
            
            # If idx is within bounds and the element is <= val + d, 
            # it means an element exists such that |arr1[i] - arr2[j]| <= d
            if idx < len(arr2) and arr2[idx] <= val + d:
                continue
                
            distance_value += 1
            
        return distance_value
