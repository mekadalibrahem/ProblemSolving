#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        // unordered_map<int, int> last_occurrence;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            // last_occurrence[a[i]] = i;
        }

        int max_segments = 0;
        int current_end = 0;
        int segment_start = 0;

        for (int i = 0; i < n; ++i)
        {
            // current_end = max(current_end, last_occurrence[a[i]]);
             current_end = current_end;
            if (i == current_end)
            {
                max_segments++;
                segment_start = i + 1;
            }
        }

        cout << max_segments << '\n';
    }

    return 0;
}