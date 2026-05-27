// https://atcoder.jp/contests/abc234/tasks/abc234_e

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    if (n<3) {
        print(s);
        return 0;
    }
    vi a;
    for (char c=s[1]; c<='9'; ++c) {
        bool ok=1;
        string st(n,'0');
        st[0]=s[0];
        int d=c-st[0];
        rep1(i,n-1) {
            st[i]=st[i-1]+d;
            if (st[i]<'0' || '9'<st[i]) {
                ok=0;
                break;
            }
        }
        if (ok) a.pb(stoll(st));
    }
    auto it=lower_bound(all(a),stoll(s));
    if (it!=a.end()) {
        print(*it);
        return 0;
    }
    for (char c='0'; c<='9'; ++c) {
        bool ok=1;
        string st(n,'0');
        st[0]=s[0]+1;
        int d=c-st[0];
        rep1(i,n-1) {
            st[i]=st[i-1]+d;
            if (st[i]<'0' || '9'<st[i]) {
                ok=0;
                break;
            }
        }
        if (ok) {
            print(stoll(st));
            return 0;
        }
    }

    return 0;
}
