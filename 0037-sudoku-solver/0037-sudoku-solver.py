class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        # Bitmasks to track used numbers (1-9 mapped to bits 1-9)
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        empty_cells = []

        # Step 1: Pre-populate masks and gather empty cells
        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == '.':
                    empty_cells.append((r, c))
                else:
                    digit = int(val)
                    mask = 1 << digit
                    box_idx = (r // 3) * 3 + (c // 3)
                    
                    rows[r] |= mask
                    cols[c] |= mask
                    boxes[box_idx] |= mask

        def backtrack(cell_idx: int) -> bool:
            # Base case: All empty cells filled successfully
            if cell_idx == len(empty_cells):
                return True
                
            r, c = empty_cells[cell_idx]
            box_idx = (r // 3) * 3 + (c // 3)
            
            # Find digits already taken in row, col, or box
            taken = rows[r] | cols[c] | boxes[box_idx]
            
            # Try available digits (1 to 9)
            for digit in range(1, 10):
                mask = 1 << digit
                if not (taken & mask):  # If the digit is not taken
                    # Set the digit (Apply choice)
                    board[r][c] = str(digit)
                    rows[r] |= mask
                    cols[c] |= mask
                    boxes[box_idx] |= mask
                    
                    if backtrack(cell_idx + 1):
                        return True
                        
                    # Reset the digit (Backtrack)
                    board[r][c] = '.'
                    rows[r] &= ~mask
                    cols[c] &= ~mask
                    boxes[box_idx] &= ~mask
                    
            return False

        backtrack(0)
