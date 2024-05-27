#include <bits/stdc++.h>
 
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v;
    
    int p = n;
    while(p--){
        int a ;
        cin >> a;
        a--;
        v.push_back(a);
    }
    for(int i = 0; i < n; i++){
        vector<bool> usato(n,false);
        bool done = false;
        int current = i;
        while(!done){
            if(usato[current] == true){
                done = true;
                cout << current+1 << " ";
            }
            else{
                usato[current] = true;
                current = v[current];
            }
        }
    }
}

int main(){
    solve();
    return 0;
}