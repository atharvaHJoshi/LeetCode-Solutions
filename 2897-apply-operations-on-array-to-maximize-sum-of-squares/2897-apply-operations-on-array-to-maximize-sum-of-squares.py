class Solution:
    def maxSum(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        
        # Step 1: Count the total frequency of 1-bits at each bit position
        bit_counts = [0] * 31
        for num in nums:
            for i in range(31):
                if (num >> i) & 1:
                    bit_counts[i] += 1
        
        # Step 2 & 3: Reconstruct the k largest numbers and sum their squares
        max_sum_squares = 0
        
        for _ in range(k):
            current_num = 0
            for i in range(31):
                if bit_counts[i] > 0:
                    current_num |= (1 << i)
                    bit_counts[i] -= 1  # Consume one 1-bit for this position
            
            max_sum_squares = (max_sum_squares + current_num * current_num) % MOD
            
        return max_sum_squares
