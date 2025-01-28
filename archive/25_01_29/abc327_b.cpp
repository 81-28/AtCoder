// https://atcoder.jp/contests/abc327/tasks/abc327_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
using ll=long long;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


ll f(const int& n) {
    ll r=n;
    for(int i=1;i<n;i++)r*=n;
    return r;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll b;
    cin >> b;
    rep1(i,16) {
        if(b==f(i)) {
            print(i);
            return 0;
        }
    }
    print(-1);

    return 0;
}
