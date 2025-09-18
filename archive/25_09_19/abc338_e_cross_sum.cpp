// https://atcoder.jp/contests/abc338/tasks/abc338_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi h(n*2+1,0);
    v<pii> p(n);
    for (auto&[a,b]:p) {
        cin >> a >> b;
        if (a>b) {
            int tmp=a;
            a=b,b=tmp;
        }
        ++h[a],--h[b];
    }
    rep1(i,n*2) h[i+1]+=h[i];
    for (auto[a,b]:p) {
        if (h[a-1]!=h[b]) {
            YesNo(1);
            return 0;
        }
    }
    YesNo(0);

    return 0;
}
