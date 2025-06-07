// https://atcoder.jp/contests/abc409/tasks/abc409_b

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define all(v) v.begin(),v.end()
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    sort(all(a));
    map<ll,bool> m;
    ll ans=0;
    rep1(i,n) {
        auto it=lower_bound(all(a),i);
        ll cnt=it-a.begin();
        if (n-cnt>=i) {
            ans=i;
        }
    }
    print(ans);

    return 0;
}
