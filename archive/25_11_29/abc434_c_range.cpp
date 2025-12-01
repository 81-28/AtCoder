// https://atcoder.jp/contests/abc434/tasks/abc434_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,h;
        cin >> n >> h;
        // 値の天井,床
        int c=h,f=h;
        int time=0;
        bool ok=1;
        while (n--) {
            int t,l,u;
            cin >> t >> l >> u;
            if (!ok) continue;
            c+=t-time;
            f-=t-time;
            if (f>u || c<l) ok=0;
            chmin(c,u);
            chmax(f,l);
            time=t;
        }
        YesNo(ok);
    }

    return 0;
}
