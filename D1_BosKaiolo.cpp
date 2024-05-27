/*
Autore: Tommaso Ulian
Data: 30/05/2024
ID problema codeforces: 1946C
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

vector<vector<int>> tree;

/*
Si può suppore qualunque vertive come radice dell'albero, senza perdita di generalità.
E' fondamentale notare che se è possibile ottenere una risposta x, allora è possibile
ottenere anche x-1 (allo stesso modo in cui si è ottenuto x). Questo è un chiaro segnale, 
il problema può essere risolto con il binary search.
Per controllare se è possibile ottenere x, utilizziamo un approccio greedy, trovando il massimo 
numero di componenti connesse in cui si può dividere l'albero in modo che ogni componente abbia 
almeno x componenti. 
Inizieremo una ricerca in profondità (DFS) dal vertice 1. Supponiamo di trovarci attualmente al 
vertice v e che il numero di vertici nel suo sottoalbero sia maggiore o uguale a x. 
In questo caso, è vantaggioso rimuovere la connessione dal vertice v al suo genitore. 
Se dopo questo processo ci sono almeno k+1 componenti connesse, allora la condizione 
è soddisfatta per questo x, altrimenti no.
*/

ll c = 0;

int dfs(int i,int x){
    if(tree[i].size()== 0)return 1;
    ll sum = 1;
    for(int j = 0; j < tree[i].size(); j++){
        sum += dfs(tree[i][j],x);
    }
    if(sum >= x){
        c++;
        return 0;
    }
    return sum;
}

bool isGood(int n,int k){
    c = 0;
    dfs(0,n);
    if(c >= k+1)return true;
    return false;
}

void solve(){
    int n,k;cin >> n >> k;
    tree = vector<vector<int>>(n);
    for(int i = 0; i <n-1; i++){
        int a, b; 
        cin >> a >> b;
        if(a > b)swap(a,b);
        a--; b--;
        tree[a].push_back(b);
    }

    int l = 2, r = n;
    int best = 1;
   
    while(l <= r){
        int c = l + (r-l)/2;
        if(isGood(c,k)){
            best = max(best,c);
            l = c+1;
        }
        else{
            r = c-1;
        }
    }
    cout << best <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}