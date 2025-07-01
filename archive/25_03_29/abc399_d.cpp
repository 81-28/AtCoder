// https://atcoder.jp/contests/abc399/tasks/abc399_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll t;
    cin >> t;
    ll n;
    vll a;
    // b[i][j]:iとjが隣あっている位置(1~)
    map<ll,map<ll,ll>> b;
    ll ans;
    ll x,y;
    rep(i,t) {
        cin >> n;
        a = vll(n*2);
        cin >> a;
        b = map<ll,map<ll,ll>>();
        ans=0;
        rep(j,n*2-1) {
            x = b[a[j]][a[j+1]];
            y = b[a[j+1]][a[j]];
            if (x==0 && y==0) {
                b[a[j]][a[j+1]] = j+1;
            } else {
                if (x!=0 && y!=0) {
                    if ((j+1)-x==2) ans++;
                } else if ((j+1)-max(x,y) != 1 && (j+1)-y!=2) {
                    ans++;
                }
            }
        }
        print(ans);
    }

    return 0;
}
