// https://atcoder.jp/contests/abc395/tasks/abc395_d

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n,q;
    cin >> n >> q;
    vll p(n+1);
    rep1(i,n) p[i]=i;
    vll mp(n+1);
    rep1(i,n) mp[i]=i;
    vll pm(n+1); 
    rep1(i,n) pm[i]=i;

    ll m,a,b,t,c,d;
    rep1(i,q) {
        cin >> m >> a;
        if (m==1) {
            cin >> b;
            p[a]=pm[b];
        }
        if (m==2) {
            cin >> b;
            c=pm[a],d=pm[b];
            t=mp[c];
            mp[c]=mp[d];
            pm[mp[d]]=c;
            mp[d]=t;
            pm[t]=d;
        }
        if (m==3) {
            print(mp[p[a]]);
        }
    }

    return 0;
}
