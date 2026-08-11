// https://atcoder.jp/contests/abc187/tasks/abc187_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rall(v) v.rbegin(),v.rend()

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    int sm=0;
    vi b(n);
    for (int&c:b) {
        int a;
        cin >> a >> c;
        c+=a*2;
        sm-=a;
    }
    sort(rall(b));
    rep(i,n) {
        sm+=b[i];
        if (sm>0) {
            print(i+1);
            return 0;
        }
    }

    return 0;
}
