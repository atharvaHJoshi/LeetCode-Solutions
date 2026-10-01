class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        close_to_open = {')': '(', ']': '[', '}': '{'}
        
        for c in s:
            if c in close_to_open:
                if not stack or stack.pop() != close_to_open[c]:
                    return False
            else:
                stack.append(c)
                
        return not stack
