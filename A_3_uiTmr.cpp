#include <bits/stdc++.h>
#define PB push_back
#define MP makepair
#ifndef ONLINE_JUDGE
#define DEBUG(x) cout << #x << " = " << (x) << endl
#else
#define DEBUG(x)
#endif
#define FOR(n) for(int i = 0; i < (n); i++)
#define SORTA(v) sort((v).begin(), (v).end())
#define SORTD(v) sort((v).rbegin(), (v).rend())
#define PRINT(v) for(auto x: (v))cout << x << " "; cout << endl;
#define TWO(n) (1 << (n))
#define INPUT(v) for(auto &x : (v))cin >> x;
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
 
typedef long long ll;
using namespace std;

ll modulo = 1000000007;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    set<char> st;
    string t = "Timur";
    for(auto c: t)st.insert(c);
    if(n != 5){cout << "NO\n";return;}
    for(int i = 0; i < n; i++){
        if(st.find(s[i]) == st.end()){
            cout << "NO\n";return;
        }
        else st.erase(st.find(s[i]));
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
