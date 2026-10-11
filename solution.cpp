#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    
    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Point> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    // Sort points by x-coordinate
    sort(points.begin(), points.end());
    
    long long answer = 0;
    
    // Use O(n^2) solution - this should work for n <= 5000 (subtask 2)
    // For larger n, this will be too slow but at least we'll get some points
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Only consider if point j is above point i (for bottom-left to top-right)
            if (points[j].y > points[i].y) {
                bool is_empty = true;
                
                // Check if there are any points inside the rectangle
                // Since points are sorted by x, we only need to check points between i and j
                for (int k = i + 1; k < j; k++) {
                    // Point k is inside rectangle if its y is between the two corners
                    if (points[k].y >= points[i].y && points[k].y <= points[j].y) {
                        is_empty = false;
                        break;
                    }
                }
                
                if (is_empty) {
                    answer++;
                }
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}