// https://atcoder.jp/contests/abc279/tasks/abc279_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
using ld=long double;

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


int a,b;
ld t(int k) {
    return b*k+a/sqrt(k+1);
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    cin >> a >> b;
    // T(k) = B*k + A/sqrt(k+1) これの最小値
    // T'(k) = B - A/{2*(k+1)^(3/2)}
    // T'(k)=0 となる k=(A/2B)^(2/3)-1
    int k=pow((ld)a/b/2,(ld)2/3)-1;
    print(min(t(k),t(k+1)));

    return 0;
}
