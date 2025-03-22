// https://atcoder.jp/contests/abc398/tasks/abc398_f

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using vi=v<int>;


bool isEqual(const string& s, const int& n) {
    rep(i,n) {
        if (s[i]!=s[n-1-i]) return 0;
    }
    return 1;
}

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
    
    // for (int i=n; i>=0; i--) {
    //     if (isEqual(s.substr(n-i,i),i)) {
    //         cout<<s;
    //         rep(j,n-i) cout<<s[n-i-1-j];
    //         cout<<'\n';
    //         return 0;
    //     }
    // }

    for (int i=0; i<(int)pos.size(); i++) {
        if (isEqual(s.substr(pos[i],n-pos[i]),n-pos[i])) {
            cout<<s;
            rep(j,pos[i]) cout<<s[pos[i]-1-j];
            cout<<'\n';
            return 0;
        }
    }

    return 0;
}
