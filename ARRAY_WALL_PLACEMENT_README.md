# Array Wall Placement - Dynamic Programming Solution

## Problem Description

Fatma has an array A of N integers and an array B of M integers, where each B[i] marks a position after which a wall is placed in A. These M walls split A into M+1 contiguous segments.

- **Cost of a segment**: Number of distinct integers it contains
- **Total cost**: Sum of all segment costs
- **Goal**: Use magic power at most once to remove one wall and minimize total cost

## Example

```
A = [1,3,1,3,4,5], B = [3,5]
```

- Walls are placed after A[3] and A[5]
- Creates segments: [1,3,1], [3,4], [5]
- Costs: 2 + 2 + 1 = 5
- Optimal: Remove wall at position 3 → segments: [1,3,1,3,4], [5] → costs: 3 + 1 = 4

## Algorithm

### Dynamic Programming Approach

1. **Calculate Initial Cost**: Compute cost with all walls present
2. **Evaluate Wall Removals**: For each wall, calculate benefit of removal
3. **Optimization**: Choose wall removal with maximum cost reduction
4. **Edge Cases**: Handle scenarios where no removal is beneficial

### Time Complexity
- **O(N × M)** where N = array size, M = number of walls
- Each wall removal evaluation requires O(N) time for distinct element counting

### Space Complexity
- **O(N)** for auxiliary data structures (sets for distinct counting)

## Implementation Details

### Core Functions

1. **`countDistinct(arr, left, right)`**
   - Counts distinct elements in array segment [left, right]
   - Uses `unordered_set` for O(1) average insertion and lookup

2. **`minCostAfterWallRemoval(A, B)`**
   - Main DP logic
   - Converts 1-based wall positions to 0-based indexing
   - Calculates initial cost and evaluates all possible wall removals

### Key Optimizations

- **Fast I/O**: Uses competitive programming optimizations
- **Efficient Data Structures**: `unordered_set` for distinct counting
- **Minimal Memory Usage**: Only stores necessary intermediate results
- **Edge Case Handling**: Properly handles no walls, single wall, etc.

## Files

### 1. `array_wall_placement.cpp`
- **Competitive Programming Version**
- Clean input/output for contest environment
- No interactive prompts

### 2. `array_wall_placement_interactive.cpp`
- **Educational Version**
- Detailed step-by-step output
- Shows segment analysis and cost calculations
- Interactive prompts for learning

## Usage

### Competitive Programming Version
```bash
g++ -o array_wall_placement array_wall_placement.cpp -std=c++17
echo "6 2
1 3 1 3 4 5
3 5" | ./array_wall_placement
# Output: 4
```

### Interactive Version
```bash
g++ -o array_wall_placement_interactive array_wall_placement_interactive.cpp -std=c++17
./array_wall_placement_interactive
# Follow prompts for detailed analysis
```

## Test Cases

### Test Case 1: Example from Problem
```
Input: N=6, M=2, A=[1,3,1,3,4,5], B=[3,5]
Output: 4
Explanation: Remove wall at position 3
```

### Test Case 2: No Walls
```
Input: N=5, M=0, A=[1,2,3,2,1]
Output: 3
Explanation: No walls to remove, count distinct in entire array
```

### Test Case 3: Single Wall
```
Input: N=4, M=1, A=[1,1,2,2], B=[2]
Output: 2
Explanation: Remove the wall to merge segments
```

### Test Case 4: No Benefit from Removal
```
Input: N=5, M=2, A=[1,2,3,4,5], B=[2,4]
Output: 5
Explanation: All elements distinct, no benefit from merging
```

## Algorithm Analysis

### Why Dynamic Programming?

The problem exhibits optimal substructure:
- **State**: Which wall to remove (or none)
- **Transition**: Calculate cost difference for each removal option
- **Optimization**: Choose removal with maximum benefit

### Correctness

1. **Exhaustive Search**: Evaluates all possible wall removals
2. **Accurate Costing**: Uses sets to precisely count distinct elements
3. **Edge Case Coverage**: Handles boundary conditions properly

### Efficiency

- **Preprocessing**: O(M log M) for wall sorting
- **Cost Calculation**: O(N) per segment using hash sets
- **Total**: O(N × M) which is optimal for this approach

## Competitive Programming Features

- **Fast I/O**: `ios_base::sync_with_stdio(false)`
- **Standard Template**: Uses `#include <bits/stdc++.h>`
- **Efficient Data Structures**: STL containers optimized for performance
- **Clean Output**: Single line result suitable for online judges

## Educational Value

The interactive version demonstrates:
- How segments are formed by walls
- Cost calculation for each segment
- Benefit analysis for each wall removal
- Step-by-step reasoning for optimal choice

This implementation serves as both a contest-ready solution and an educational tool for understanding dynamic programming approaches to optimization problems.