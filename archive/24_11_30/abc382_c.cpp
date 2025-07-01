// https://atcoder.jp/contests/abc382/tasks/abc382_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    cin >> a >> b;
    int j=0;
    vi c;
    unordered_map<int,int> mp;
    c.pb(a[0]);
    mp[a[0]] = 1;
    for (int i=1; i<n; i++) {
        if (a[i] < c[j]) {
            c.pb(a[i]);
            mp[a[i]] = i+1;
            j++;
        }
    }
    sort(all(c));
    rep(i,m) {
        auto it = upper_bound(all(c),b[i]);
        if (it==c.begin()) print(-1);
        else {
            it--;
            print(mp[*it]);
        }
    }

    return 0;
}
