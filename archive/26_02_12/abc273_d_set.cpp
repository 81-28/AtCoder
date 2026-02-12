// https://atcoder.jp/contests/abc273/tasks/abc273_d

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,r,c,n;
    cin >> h >> w >> r >> c >> n;
    map<int,set<int>> sr,sc;
    while (n--) {
        int x,y;
        cin >> x >> y;
        sr[x].insert(y);
        sc[y].insert(x);
    }
    int q;
    cin >> q;
    while (q--) {
        char d;
        int l;
        cin >> d >> l;
        if (d=='L') {
            auto it=sr[r].lower_bound(c);
            if (it!=sr[r].begin()) c=max(c-l,*--it+1);
            else c=max(c-l,1);
        }
        if (d=='R') {
            auto it=sr[r].lower_bound(c);
            if (it!=sr[r].end()) c=min(c+l,*it-1);
            else c=min(c+l,w);
        }
        if (d=='U') {
            auto it=sc[c].lower_bound(r);
            if (it!=sc[c].begin()) r=max(r-l,*--it+1);
            else r=max(r-l,1);
        }
        if (d=='D') {
            auto it=sc[c].lower_bound(r);
            if (it!=sc[c].end()) r=min(r+l,*it-1);
            else r=min(r+l,h);
        }
        print(r,c);
    }

    return 0;
}
