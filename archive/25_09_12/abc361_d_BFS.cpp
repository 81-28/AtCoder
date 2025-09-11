// https://atcoder.jp/contests/abc361/tasks/abc361_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


template<typename K,typename V>
class d_map:public map<K,V>{
public:
    V d_val;
    d_map(const V& default_value):d_val(default_value){}
    V& operator[](const K& key) {
        auto it=this->find(key);
        if (it==this->end()) {
            it=this->emplace(key,d_val).first;
        }
        return it->second;
    }
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s,t;
    cin >> n >> s >> t;
    int sb=0,tb=0;
    rep(i,n) {
        if (s[i]=='B') ++sb;
        if (t[i]=='B') ++tb;
    }
    if (sb!=tb) {
        print(-1);
        return 0;
    }
    int inf=INT_MAX;
    d_map<string,int> m(inf);
    queue<string> q;
    s+="..",t+="..";
    m[s]=0;
    q.push(s);
    while (!q.empty()) {
        string str=q.front();
        q.pop();
        int j=0;
        rep(i,n+2) {
            if (str[i]=='.') {
                j=i;
                break;
            }
        }
        rep(i,n+1) {
            string st=str;
            if (st[i]=='.'||st[i+1]=='.') continue;
            st[j]=str[i],st[j+1]=str[i+1];
            st[i]='.',st[i+1]='.';
            if (chmin(m[st],m[str]+1)) q.push(st);
        }
        if (m[t]!=inf) {
            print(m[t]);
            return 0;
        }
    }
    print(-1);

    return 0;
}
