#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

/*
 * Array Wall Placement - Interactive Version for Testing and Learning
 * 
 * This version includes interactive prompts and detailed output for educational purposes
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

// DP function to find minimum cost after optimal wall removal
int minCostAfterWallRemoval(const vector<int>& A, vector<int>& B, bool verbose = false) {
    int n = A.size();
    int m = B.size();
    
    if (m == 0) {
        if (verbose) cout << "No walls present. Cost = distinct elements in entire array." << endl;
        return countDistinct(A, 0, n - 1);
    }
    
    // Convert to 0-based indexing
    for (int& wall : B) {
        wall--; // Convert from 1-based to 0-based
    }
    
    // Sort walls
    sort(B.begin(), B.end());
    
    // Calculate initial cost with all walls
    int initialCost = 0;
    
    if (verbose) {
        cout << "\nInitial segments and costs:" << endl;
    }
    
    // Cost of first segment [0, B[0]]
    int cost1 = countDistinct(A, 0, B[0]);
    initialCost += cost1;
    if (verbose) {
        cout << "Segment [0, " << B[0] << "]: ";
        for (int i = 0; i <= B[0]; i++) cout << A[i] << " ";
        cout << "-> cost: " << cost1 << endl;
    }
    
    // Cost of middle segments
    for (int i = 1; i < m; i++) {
        int cost = countDistinct(A, B[i-1] + 1, B[i]);
        initialCost += cost;
        if (verbose) {
            cout << "Segment [" << B[i-1] + 1 << ", " << B[i] << "]: ";
            for (int j = B[i-1] + 1; j <= B[i]; j++) cout << A[j] << " ";
            cout << "-> cost: " << cost << endl;
        }
    }
    
    // Cost of last segment
    int costLast = countDistinct(A, B[m-1] + 1, n - 1);
    initialCost += costLast;
    if (verbose) {
        cout << "Segment [" << B[m-1] + 1 << ", " << n - 1 << "]: ";
        for (int i = B[m-1] + 1; i < n; i++) cout << A[i] << " ";
        cout << "-> cost: " << costLast << endl;
        cout << "Initial total cost: " << initialCost << endl << endl;
    }
    
    // Try removing each wall
    int maxBenefit = 0;
    int bestWallToRemove = -1;
    
    if (verbose) cout << "Analyzing wall removals:" << endl;
    
    for (int i = 0; i < m; i++) {
        int oldCost = 0;
        int newCost = 0;
        
        if (i == 0) {
            oldCost += countDistinct(A, 0, B[0]);
            if (i + 1 < m) {
                oldCost += countDistinct(A, B[0] + 1, B[1]);
                newCost = countDistinct(A, 0, B[1]);
            } else {
                oldCost += countDistinct(A, B[0] + 1, n - 1);
                newCost = countDistinct(A, 0, n - 1);
            }
        } else if (i == m - 1) {
            oldCost += countDistinct(A, B[i-1] + 1, B[i]);
            oldCost += countDistinct(A, B[i] + 1, n - 1);
            newCost = countDistinct(A, B[i-1] + 1, n - 1);
        } else {
            oldCost += countDistinct(A, B[i-1] + 1, B[i]);
            oldCost += countDistinct(A, B[i] + 1, B[i+1]);
            newCost = countDistinct(A, B[i-1] + 1, B[i+1]);
        }
        
        int benefit = oldCost - newCost;
        
        if (verbose) {
            cout << "Remove wall at position " << B[i] + 1 << " (1-based): benefit = " << benefit << endl;
        }
        
        if (benefit > maxBenefit) {
            maxBenefit = benefit;
            bestWallToRemove = i;
        }
    }
    
    if (verbose) {
        if (maxBenefit > 0) {
            cout << "\nBest choice: Remove wall at position " << B[bestWallToRemove] + 1 << " (1-based)" << endl;
            cout << "Cost reduction: " << maxBenefit << endl;
        } else {
            cout << "\nBest choice: Don't remove any wall (no benefit)" << endl;
        }
    }
    
    return initialCost - maxBenefit;
}

int main() {
    fast_io;
    
    cout << "Array Wall Placement - Dynamic Programming Solution" << endl;
    cout << "===================================================" << endl << endl;
    
    // Input reading
    int n, m;
    cout << "Enter array size N: ";
    cin >> n;
    cout << "Enter number of walls M: ";
    cin >> m;
    
    vector<int> A(n);
    cout << "Enter array A (" << n << " elements): ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<int> B(m);
    if (m > 0) {
        cout << "Enter wall positions B (1-based, " << m << " elements): ";
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }
    }
    
    // Solve the problem with verbose output
    int result = minCostAfterWallRemoval(A, B, true);
    
    cout << "\nFinal Answer: " << result << endl;
    
    return 0;
}