// https://atcoder.jp/contests/abc310/tasks/abc310_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rall(v) v.rbegin(),v.rend()
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    map<string,bool> m;
    string s,t;
    int ans=0;
    rep(i,n) {
        cin >> s;
        t = string(rall(s));
        if (!m[s]&&!m[t]) {
            m[s]=1;
            ans++;
        }
    }
    print(ans);

    return 0;
}
