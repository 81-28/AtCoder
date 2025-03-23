// https://atcoder.jp/contests/abc398/tasks/abc398_f

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();

    vi pos;
    regex pattern(s.substr(n-1,1));
    auto wbegin = sregex_iterator(all(s),pattern);
    auto wend = sregex_iterator();
    for (sregex_iterator i=wbegin; i!=wend; ++i) {
        smatch match = *i;
        pos.pb(match.position());
    }

    bool ok;
    int l,r;
    for(int val:pos) {
        ok=1;
        l=val,r=n-1;
        while (l<r) {
            if (s[l]!=s[r]) {
                ok=0;
                break;
            }
            l++,r--;
        }
        if (ok) {
            cout<<s;
            rep(i,val) cout<<s[val-1-i];
            cout<<'\n';
            return 0;
        }
    }

    return 0;
}
