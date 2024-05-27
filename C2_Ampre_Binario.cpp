#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)

typedef long long ll;
using namespace std;

string moves;
vector<pair<int,int>> btree;

int dfs(int node, int count){
    if(btree[node].first == -1 && btree[node].second == -1)return count;

    int a = INFINITY, b = INFINITY;
    
    if(btree[node].first != -1){
        if(moves[node] == 'L')a = dfs(btree[node].first,count);
        else a = dfs(btree[node].first,count+1);
    }
    if(btree[node].second != -1){
        if(moves[node] == 'R')b = dfs(btree[node].second,count);
        else b = dfs(btree[node].second,count+1);
    }
    return min(a,b);
}

void solve(){
    int n; cin >> n;
    moves.clear();
    cin >> moves;
    btree.clear();
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        btree.push_back({l-1,r-1});
    }
    cout << dfs(0,0) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}