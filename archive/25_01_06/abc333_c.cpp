// https://atcoder.jp/contests/abc333/tasks/abc333_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    vll r(12,1);
    for (int i=1; i<12; i++) r[i] += r[i-1]*10;
    set<ll> s;
    rep(i,12)rep(j,12)rep(k,12) s.insert(r[i]+r[j]+r[k]);

    int n;
    cin >> n;
    auto it=s.begin();
    advance(it,n-1);
    print(*it);

    return 0;
}
