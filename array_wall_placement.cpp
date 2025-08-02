#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

/*
 * Array Wall Placement - Dynamic Programming Solution
 * 
 * Problem:
 * - Array A of N integers with M walls at positions B[i]
 * - Walls split array into M+1 segments
 * - Cost of segment = number of distinct integers
 * - Can remove at most one wall to minimize total cost
 * 
 * Algorithm:
 * 1. Calculate initial cost with all walls
 * 2. For each wall removal, calculate cost reduction (DP optimization)
 * 3. Choose removal that gives maximum benefit
 * 
 * Time Complexity: O(N * M) where N = array size, M = number of walls
 * Space Complexity: O(N) for auxiliary data structures
 */

// Helper function to calculate number of distinct elements in array segment [left, right]
int countDistinct(const vector<int>& arr, int left, int right) {
    if (left > right) return 0;
    unordered_set<int> distinct;
    for (int i = left; i <= right; i++) {
        distinct.insert(arr[i]);
    }
    return distinct.size();
}

// Calculate cost of all segments with current wall configuration
int calculateTotalCost(const vector<int>& A, const vector<int>& walls) {
    int n = A.size();
    int totalCost = 0;
    
    // Add virtual walls at start and end for easier processing
    vector<int> allWalls = {0}; // Wall before first element (virtual)
    for (int wall : walls) {
        allWalls.push_back(wall);
    }
    allWalls.push_back(n); // Wall after last element (virtual)
    
    // Calculate cost for each segment
    for (int i = 0; i < allWalls.size() - 1; i++) {
        int segmentStart = allWalls[i];
        int segmentEnd = allWalls[i + 1] - 1;
        
        // Adjust for 1-based wall positions in problem statement
        if (i == 0) {
            segmentStart = 0; // First segment starts at 0
        } else {
            segmentStart = allWalls[i]; // Segment starts after wall
        }
        
        if (segmentStart <= segmentEnd) {
            totalCost += countDistinct(A, segmentStart, segmentEnd);
        }
    }
    
    return totalCost;
}

// DP function to find minimum cost after optimal wall removal
int minCostAfterWallRemoval(const vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();
    
    if (m == 0) {
        // No walls to remove, return cost of entire array
        return countDistinct(A, 0, n - 1);
    }
    
    // Convert to 0-based indexing for easier processing
    for (int& wall : B) {
        wall--; // Convert from 1-based to 0-based
    }
    
    // Sort walls to ensure proper order
    sort(B.begin(), B.end());
    
    // Calculate initial cost with all walls
    int initialCost = 0;
    
    // Cost of first segment [0, B[0]]
    initialCost += countDistinct(A, 0, B[0]);
    
    // Cost of middle segments [B[i-1]+1, B[i]]
    for (int i = 1; i < m; i++) {
        initialCost += countDistinct(A, B[i-1] + 1, B[i]);
    }
    
    // Cost of last segment [B[m-1]+1, n-1]
    initialCost += countDistinct(A, B[m-1] + 1, n - 1);
    
    // Try removing each wall and calculate the cost reduction
    int maxBenefit = 0; // Maximum cost reduction possible
    
    for (int i = 0; i < m; i++) {
        // Calculate benefit of removing wall at position B[i]
        int oldCost = 0;
        int newCost = 0;
        
        if (i == 0) {
            // Removing first wall merges [0, B[0]] and [B[0]+1, B[1]]
            oldCost += countDistinct(A, 0, B[0]);
            if (i + 1 < m) {
                oldCost += countDistinct(A, B[0] + 1, B[1]);
                newCost = countDistinct(A, 0, B[1]);
            } else {
                oldCost += countDistinct(A, B[0] + 1, n - 1);
                newCost = countDistinct(A, 0, n - 1);
            }
        } else if (i == m - 1) {
            // Removing last wall merges [B[i-1]+1, B[i]] and [B[i]+1, n-1]
            oldCost += countDistinct(A, B[i-1] + 1, B[i]);
            oldCost += countDistinct(A, B[i] + 1, n - 1);
            newCost = countDistinct(A, B[i-1] + 1, n - 1);
        } else {
            // Removing middle wall merges [B[i-1]+1, B[i]] and [B[i]+1, B[i+1]]
            oldCost += countDistinct(A, B[i-1] + 1, B[i]);
            oldCost += countDistinct(A, B[i] + 1, B[i+1]);
            newCost = countDistinct(A, B[i-1] + 1, B[i+1]);
        }
        
        int benefit = oldCost - newCost;
        maxBenefit = max(maxBenefit, benefit);
    }
    
    // Return minimum possible cost
    return initialCost - maxBenefit;
}

int main() {
    fast_io;
    
    // Input reading - competitive programming style (no prompts)
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    
    // Solve the problem
    int result = minCostAfterWallRemoval(A, B);
    
    cout << result << endl;
    
    return 0;
}

/*
 * Example Test Case:
 * Input:
 * N = 6, M = 2
 * A = [1, 3, 1, 3, 4, 5]
 * B = [3, 5]
 * 
 * Initial segments: [1,3,1], [3,4], [5]
 * Initial costs: 2 + 2 + 1 = 5
 * 
 * Removing wall at position 3: [1,3,1,3,4], [5] -> costs: 3 + 1 = 4
 * Removing wall at position 5: [1,3,1], [3,4,5] -> costs: 2 + 3 = 5
 * 
 * Minimum cost = 4
 */