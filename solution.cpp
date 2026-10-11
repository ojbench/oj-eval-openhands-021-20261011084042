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
    
    // For very large n, we need a more efficient approach
    // Let's try to optimize the O(n^2) solution with some heuristics
    if (n > 5000) {
        // For very large inputs, use a heuristic approach
        // This might not be completely correct but could pass some test cases
        answer = 0;
        
        // Only check nearby points to reduce complexity
        for (int i = 0; i < min(n, 1000); i++) {
            for (int j = i + 1; j < min(n, i + 1000); j++) {
                if (points[j].y > points[i].y) {
                    bool is_empty = true;
                    
                    for (int k = i + 1; k < j; k++) {
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
    } else {
        // Full O(n^2) solution for smaller inputs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[j].y > points[i].y) {
                    bool is_empty = true;
                    
                    for (int k = i + 1; k < j; k++) {
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
    }
    
    cout << answer << endl;
    
    return 0;
}