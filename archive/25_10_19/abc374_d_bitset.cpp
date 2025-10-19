// https://atcoder.jp/contests/abc347/tasks/abc347_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int a,b,c;
    cin >> a >> b >> c;
    bitset<60> x,y,z(c);
    int cnt=z.count();
    int rem=60-cnt;
    int dif=abs(a-b);
    int can=cnt-dif;
    if (can<0 || (can&1)) {
        print(-1);
        return 0;
    }
    int st=can>>1;
    int sta=st,stb=st;
    if (a>b) sta+=dif;
    else stb+=dif;
    int r=a-sta;
    if (r<0 || rem<r) {
        print(-1);
        return 0;
    }
    int j=0,k=0;
    rep(i,60) {
        if (z[i]) {
            if (j++<stb) y[i]=1;
            else x[i]=1;
        } else {
            if (k++<r) x[i]=y[i]=1;
        }
    }
    print(x.to_ullong(),y.to_ullong());

    return 0;
}
