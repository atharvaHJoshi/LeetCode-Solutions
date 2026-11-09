from sortedcontainers import SortedList
import heapq

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        # Track the number of requests handled by each server
        request_counts = [0] * k
        
        # Track available servers (initially all servers 0 to k-1 are available)
        available = SortedList(range(k))
        
        # Min-heap to track busy servers: stores tuples of (end_time, server_id)
        busy = []
        
        for i, (start, duration) in enumerate(zip(arrival, load)):
            # 1. Free up servers whose handling time ends <= current arrival time
            while busy and busy[0][0] <= start:
                _, server_id = heapq.heappop(busy)
                available.add(server_id)
            
            # If no servers are available, the request is dropped
            if not available:
                continue
            
            # 2. Find the ideal server using wrap-around logic (i % k)
            preferred_id = i % k
            
            # Find the first available server >= preferred_id
            idx = available.bisect_left(preferred_id)
            
            # If none found >= preferred_id, wrap around to the first available server
            if idx == len(available):
                idx = 0
                
            assigned_server = available.pop(idx)
            
            # 3. Update status
            request_counts[assigned_server] += 1
            heapq.heappush(busy, (start + duration, assigned_server))
            
        # 4. Find all servers that handled the maximum number of requests
        max_requests = max(request_counts)
        return [server_id for server_id, count in enumerate(request_counts) if count == max_requests]
