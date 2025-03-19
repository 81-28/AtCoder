// https://atcoder.jp/contests/abc314/tasks/abc314_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    string s;
    cin >> n >> m >> s;
    vi c(n);
    cin >> c;
    map<int,vi> mp;
    map<int,int> idx;
    map<int,int> count;
    rep(i,n) {
        mp[c[i]].pb(i);
        idx[i]=count[c[i]]++ -1;
    }
    rep(i,n) cout<<s[mp[c[i]][(idx[i]+count[c[i]])%count[c[i]]]];
    cout<<'\n';

    return 0;
}
