#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

ll modulo = 1000000007;

void maxOf(ll &a, ll b){
    a = max(a,b);
}

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> v(n); 
    vector<bool> awake(n);
    for(auto &x: v)cin >> x;
    for(ll i = 0;i < n; i++){
        bool a; cin >> a;
        awake[i] = a;
    }
    vector<ll> prefix(n+1);
    prefix[0] = 0;
    for(ll i = 0; i < n;i++){
        prefix[i+1] = prefix[i] + v[i];
    }


    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[0][0] = 0; dp[0][1] = 0;
    for(ll i = 0; i < n; i++){
        if(awake[i]){
            maxOf(dp[i+1][0], dp[i][0] + v[i]);
            maxOf(dp[i+1][1], dp[i][1] + v[i]);
        }
        else{
            ll end = min(i+k,n);
            maxOf(dp[end][1], dp[i][0] + (prefix[end]-prefix[i]));
            maxOf(dp[i+1][0],dp[i][0]);
            maxOf(dp[i+1][1],dp[i][1]);
            
        }
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}