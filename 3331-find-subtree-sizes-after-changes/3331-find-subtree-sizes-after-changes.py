# class Solution:
#     def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        

class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        adj = [[] for _ in range(n)]
        for i in range(1, n):
            adj[parent[i]].append(i)
            
        new_parent = list(parent)
        last_seen = [-1] * 26
        
        # Iterative DFS: (node, is_entering, previous_ancestor)
        stack = [(0, True, -1)]
        while stack:
            u, entering, prev = stack.pop()
            c = ord(s[u]) - ord('a')
            
            if entering:
                old_ancestor = last_seen[c]
                if old_ancestor != -1:
                    new_parent[u] = old_ancestor
                
                stack.append((u, False, old_ancestor))
                last_seen[c] = u
                
                for v in adj[u]:
                    stack.append((v, True, -1))
            else:
                last_seen[c] = prev
                
        new_adj = [[] for _ in range(n)]
        for i in range(1, n):
            new_adj[new_parent[i]].append(i)
            
        ans = [1] * n
        order = []
        stack = [0]
        while stack:
            u = stack.pop()
            order.append(u)
            for v in new_adj[u]:
                stack.append(v)
                
        for u in reversed(order):
            if new_parent[u] != -1:
                ans[new_parent[u]] += ans[u]
                
        return ans
