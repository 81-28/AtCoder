// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_eb

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q,n,x,l,r;
    cin >> q;
    set<int> s;
    auto it = s.end();
    rep(i,q) {
        cin >> n >> x;
        if(n==1) s.insert(x);
        if(n==2) {
            if (!s.size()) cout<<-1<<'\n';
            else {
                it = s.lower_bound(x);
                l = INT_MAX;
                r = INT_MAX;
                if (it != s.end()) {
                    r = *it-x;
                }
                if (it != s.begin()) {
                    it--;
                    l = x-*it;
                }
                cout<<min(l,r)<<'\n';
            }
        }
    }

    return 0;
}
