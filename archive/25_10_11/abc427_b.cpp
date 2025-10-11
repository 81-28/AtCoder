// https://atcoder.jp/contests/abc427/tasks/abc427_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

int f(const int& n) {
    int res=0;
    for (int i=n; i; i/=10) res+=i%10;
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    a[0]=1;
    for (int i=1; i<n; ++i) a[i]=a[i-1]+f(a[i-1]);
    print(a[n-1]);

    return 0;
}
