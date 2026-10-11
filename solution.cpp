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
    
    // Use O(n^3) solution for correctness - this will work for n <= 400 (subtask 1)
    // This is the most straightforward and correct approach
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Only consider if point j is above point i (for bottom-left to top-right)
            if (points[j].y > points[i].y) {
                bool is_empty = true;
                
                // Check if there are any points inside the rectangle
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    
                    // Check if point k is inside the rectangle (including boundary)
                    if (points[k].x >= points[i].x && points[k].x <= points[j].x &&
                        points[k].y >= points[i].y && points[k].y <= points[j].y) {
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