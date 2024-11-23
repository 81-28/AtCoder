// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_eb

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q,n,x,ans;
    cin >> q;
    set<int> s;
    auto it = s.end();
    rep(i,q) {
        cin >> n >> x;
        if(n==1) s.insert(x);
        if(n==2) {
            ans = INT_MAX;
            it = s.lower_bound(x);
            if (it != s.end()) {
                ans = min(ans,*it-x);
            }
            if (it != s.begin()) {
                it--;
                ans = min(ans,x-*it);
            }
            cout<<(ans==INT_MAX?-1:ans)<<'\n';
        }
    }

    return 0;
}
