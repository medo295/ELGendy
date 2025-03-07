#include <bits/stdc++.h>
using namespace std;
#define M ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ll long long
int main() {
    M
    #ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ll n, q, sum = 0;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end(), greater<int>());
    vector<int> ans(n + 2, 0);
    while (q--) {
        int l, r;
        cin >> l >> r;
        ans[l]++;
        if (r + 1 <= n) {
            ans[r + 1]--;
        }
    }
    vector<int> v1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        v1[i] = v1[i - 1] + ans[i];
    }
    sort(v1.begin() + 1, v1.end(), greater<int>());
    for (int i = 1; i <= n; i++) {
        sum += 1ll * v1[i] * v[i];
    }
    cout << sum << endl;
}
