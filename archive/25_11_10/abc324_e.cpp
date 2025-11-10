// https://atcoder.jp/contests/abc324/tasks/abc324_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string t;
    cin >> n >> t;
    v<string> s(n);
    cin >> s;
    int m=t.size();
    // s[i]に部分列として含まれる、tの接頭辞の最大長,接尾辞の最大長
    vi he(n),ta(n);
    rep(i,n) {
        int l=s[i].size();
        int cnt=0;
        rep(j,l) {
            if (cnt==m) break;
            if (s[i][j]==t[cnt]) ++cnt;
        }
        he[i]=cnt;
        cnt=0;
        for (int j=l-1; j>=0; --j) {
            if (cnt==m) break;
            if (s[i][j]==t[m-1-cnt]) ++cnt;
        }
        ta[i]=cnt;
    }
    // sort(rall(he));
    sort(all(ta));
    int ans=0;
    // int j=0;
    rep(i,n) {
        // while (j<n && m-he[i]>ta[j]) ++j;
        // ans+=n-j;
        auto it=lower_bound(all(ta),m-he[i]);
        ans+=ta.end()-it;
    }
    print(ans);

    return 0;
}
