// https://atcoder.jp/contests/abc255/tasks/abc255_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,a,d,n;
    cin >> x >> a >> d >> n;
    int b=a+d*(n-1);
    if (d<0) {
        int tmp=a;
        a=b;
        b=tmp;
        d*=-1;
    }
    if (x<=a) {
        print(a-x);
        return 0;
    }
    if (b<=x) {
        print(x-b);
        return 0;
    }
    x-=a;
    x%=d;
    print(min(x,d-x));

    return 0;
}
