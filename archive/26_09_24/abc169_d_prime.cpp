// https://atcoder.jp/contests/abc169/tasks/abc169_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


map<int,int> primeFactors(int n) {
    map<int,int> res;
    if (n<=1) return res;
    while ((n&1) == 0) { ++res[2]; n /= 2; }
    while (n%3 == 0) { ++res[3]; n /= 3; }
    for (int i=5; i*i <= n; i+=6) {
        while (n%i == 0) { ++res[i]; n /= i; }
        int j = i+2;
        while (n%j == 0) { ++res[j]; n /= j; }
    }
    if (n>1) ++res[n];
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> p=primeFactors(n);
    int ans=0;
    for (auto[num,cnt]:p) {
        for (int i=1; ; ++i) {
            if (i>cnt) break;
            cnt-=i;
            ++ans;
        }
    }
    print(ans);

    return 0;
}
