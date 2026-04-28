// https://atcoder.jp/contests/abc249/tasks/abc249_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<int,int> m;
    int mx=0;
    while (n--) {
        int a;
        cin >> a;
        ++m[a];
        chmax(mx,a);
    }
    int ans=0;
    for (auto[nm0,ct0]:m) {
        for (auto[nm1,ct1]:m) {
            if (nm0*nm1>mx) break;
            int ct2=m[nm0*nm1];
            if (!ct2) continue;
            ans+=ct0*ct1*ct2;
        }
    }
    print(ans);

    return 0;
}
