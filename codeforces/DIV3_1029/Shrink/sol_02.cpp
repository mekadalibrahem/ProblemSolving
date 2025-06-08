#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) numbers[i] = i + 1;
        // sort(numbers.begin(), numbers.end()); // Ascending
        
        int left = 0, right = n - 1; // Edge indices
        int small = 0, large = n - 1; // Number indices
        int step = 0;
        while (left <= right) {
            if (step == 0) {
                // Place small numbers at edges
                p[left++] = numbers[small++]; // e.g., 2
                if (left <= right) p[right--] = numbers[small++]; // e.g., 1
            } else {
                // Place large numbers in middle for peaks
                if (left <= right) p[left++] = numbers[small++]; // Next small
                if (left <= right) p[left++] = numbers[large--]; // Largest
            }
            step++;
        }
        
        for (int x : p) cout << x << " ";
        cout << "\n";
    }
    return 0;
}