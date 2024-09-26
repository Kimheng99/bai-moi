#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    
    if (N == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (N == 2) {
        cout << a[0] + a[1] << endl;
        return 0;
    } else if (N == 3) {
        cout << a[0] + a[1] + a[2] << endl;
        return 0;
    }

    
    vector<long long> dp(N);

    
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = a[0] + a[1] + a[2];

    
    for (int i = 3; i < N; ++i) {
        dp[i] = max({dp[i-1], dp[i-2] + a[i], dp[i-3] + a[i-1] + a[i]});
    }

    
    cout << dp[N-1] << endl;

    return 0;
}
