// https://atcoder.jp/contests/abc397/tasks/abc397_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
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

    ll n;
    cin >> n;
    vll a(n);
    cin >> a;
    set<ll> s;
    map<ll,ll> m,d;
    rep(i,n){
        m[a[i]]++;
        s.insert(a[i]);
    }
    ll ans=s.size();
    vll sum(n,0);
    rep(i,n) {
        if (i) sum[i]+=sum[i-1];
        if (m[a[i]]==1 && d[a[i]]==1) {
            sum[i]--;
            m[a[i]]--;
        }
        if (m[a[i]]>1) {
            if (d[a[i]]!=1) {
                sum[i]++;
                d[a[i]]=1;
            }
            m[a[i]]--;
        }
    }
    ll mx=*max_element(sum.begin(),sum.end()-1);
    print(ans + mx);

    return 0;
}
