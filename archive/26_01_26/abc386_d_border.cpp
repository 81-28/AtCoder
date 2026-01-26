// https://atcoder.jp/contests/abc386/tasks/abc386_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    map<int,map<int,vi>> mp;
    while (m--) {
        int x,y;
        char c;
        cin >> x >> y >> c;
        mp[x][c=='W'].pb(y);
    }
    int last=n;
    for (auto[r,mpn]:mp) {
        vi b=mpn[0],w=mpn[1];
        sort(all(b)),sort(all(w));
        if (w.size()) {
            int miw=*w.begin();
            if (b.size()) {
                int mxb=*b.rbegin();
                if (mxb>miw-1 || last<mxb) {
                    YesNo(0);
                    return 0;
                }
            }
            chmin(last,miw-1);
        } else {
            if (b.size()) {
                int mxb=*b.rbegin();
                if (last<mxb) {
                    YesNo(0);
                    return 0;
                }
            }
        }
    }
    YesNo(1);

    return 0;
}
