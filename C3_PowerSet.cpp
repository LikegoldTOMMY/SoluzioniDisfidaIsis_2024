/*
Autore: Tommaso Ulian
Data: 30/05/2024
ID problema codeforces: 1913C
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Inianzi tutto teniamo il conto di quali e quante potenze di due abbiamo.
Utilizziamo poi un approccio greedy.
Per ogni numero che si viene fornito iteriamo sulle potenze di due a partire dalla più
grande e ne prendiamo il più possibile, fino a che o otteniamo  il numero desiderato, 
o terminiamo le potenze di 2 a disposizione, e di conseguenza non possiamo ottenere il 
numero.
Questo approccio funziona perchè ogni numero è scrivibile come somma di potenze di 
due e di conseguenza anche ogni potenza di due è scrivibile come somma di potenze di due.
*/

void solve(){
    vector<ll> v(30,0);
    ll m;
    cin >> m;
    while(m--){
        int a;
        ll n;
        cin >> a >> n;
        if( a == 1){
            v[n]++;
        }
        else{
            for(int i = 30; i >= 0; i--){
                ll ct=n/(1<<i);
                ct= min(ct,v[i]);
                n-=ct*(1<<i);
            }
            if(n == 0)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
 
}
 
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    solve();
 
	
    return 0;
}