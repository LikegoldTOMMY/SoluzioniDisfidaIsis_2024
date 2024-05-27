/*
Autore: Tommaso Ulian
Data: 30/05/2024
ID problema codeforces: 1845D
*/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

ll modulo = 1000000007;

/*
Inserire un valore di k permette di prendere un sottoarray che ha somma negativa, e di
ignorarlo nel conteggio finale del rating, è quindi sufficiente trovare il minimum subarray,
ciò può essere fatto in O(n) con l'algoritmo di Kadane.
*/

void solve(){
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i=0; i < n; i++){
        cin >> v[i];
    }
    ll s,f,cs = 0; ll m = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum < m){
            f = i;
            s = cs;
            m = sum;
        }
        if(sum > 0){
            sum = 0;
            cs = i+1;
        }
    }
    ll ans = 0;
    for(int i = 0; i < min(s,n); i++){
        ans += v[i];
    }
    if(m == 0)ans = *max_element(v.begin(),v.end())+17;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}