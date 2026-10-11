#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    int y_idx;
    
    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n <= 400) {
        // Use O(n^3) solution for small n
        vector<Point> points(n);
        
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        
        sort(points.begin(), points.end());
        
        long long answer = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[j].y > points[i].y) {
                    bool is_empty = true;
                    
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        
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
    
    // For larger n, use O(n^2) approach
    vector<Point> points(n);
    vector<int> y_coords;
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        y_coords.push_back(points[i].y);
    }
    
    // Coordinate compression for y-coordinates
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    
    for (int i = 0; i < n; i++) {
        points[i].y_idx = lower_bound(y_coords.begin(), y_coords.end(), points[i].y) - y_coords.begin();
    }
    
    // Sort points by x-coordinate
    sort(points.begin(), points.end());
    
    long long answer = 0;
    
    // O(n^2) approach: for each pair (i,j), check if rectangle is empty
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[j].y > points[i].y) {
                bool is_empty = true;
                
                // Check points between i and j in x-order
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
    
    cout << answer << endl;
    
    return 0;
}