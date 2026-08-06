// https://atcoder.jp/contests/abc260/tasks/abc260_c

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,y;
    cin >> n >> x >> y;
    int r=1,b=0;
    for (int i=n; i>1; --i) {
        b+=x*r,r+=b,b*=y;
    }
    print(b);

    return 0;
}
