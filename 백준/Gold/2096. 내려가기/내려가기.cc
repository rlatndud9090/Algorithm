#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int prev_max[3] = {0}, prev_min[3] = {0};
    int curr_max[3], curr_min[3];

    for (int i = 0; i < N; ++i) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        if (i == 0) {
            prev_max[0] = prev_min[0] = a[0];
            prev_max[1] = prev_min[1] = a[1];
            prev_max[2] = prev_min[2] = a[2];
        } else {
            curr_max[0] = a[0] + max(prev_max[0], prev_max[1]);
            curr_max[1] = a[1] + max({prev_max[0], prev_max[1], prev_max[2]});
            curr_max[2] = a[2] + max(prev_max[1], prev_max[2]);

            curr_min[0] = a[0] + min(prev_min[0], prev_min[1]);
            curr_min[1] = a[1] + min({prev_min[0], prev_min[1], prev_min[2]});
            curr_min[2] = a[2] + min(prev_min[1], prev_min[2]);

            for (int j = 0; j < 3; ++j) {
                prev_max[j] = curr_max[j];
                prev_min[j] = curr_min[j];
            }
        }
    }

    int max_score = max({prev_max[0], prev_max[1], prev_max[2]});
    int min_score = min({prev_min[0], prev_min[1], prev_min[2]});

    cout << max_score << " " << min_score << endl;
    return 0;
}