// https://codeforces.com/gym/105633/problem/E

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int n,m;
v<string> t;

v<pii> search(const pii& pos) {
    v<pii> res;
    queue<pii> q;
    q.push(pos);
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        if (0<=p.s-1 && t[p.f][p.s-1] != '.') {
            if (t[p.f][p.s-1] == '#') q.push({p.f,p.s-1});
            else res.pb({p.f,p.s-1});
        }
        if (p.s+1<m && t[p.f][p.s+1] != '.') {
            if (t[p.f][p.s+1] == '#') q.push({p.f,p.s+1});
            else res.pb({p.f,p.s+1});
        }
        if (0<=p.f-1 && t[p.f-1][p.s] != '.') {
            if (t[p.f-1][p.s] == '#') q.push({p.f-1,p.s});
            else res.pb({p.f-1,p.s});
        }
        if (p.f+1<n && t[p.f+1][p.s] != '.') {
            if (t[p.f+1][p.s] == '#') q.push({p.f+1,p.s});
            else res.pb({p.f+1,p.s});
        }
        t[p.f][p.s] = '.';
    }
    return res;
}

ll func(const pii& p) {
    char c = t[p.f][p.s];

    int num = c-'0';
    if (0 <= num && num < 10) return num;

    v<pii> se = search(p);
    // rep(i,n)print(t[i]);

    if (c == 'P') return func(se[0]);
    if (c == '+') {
        return func(se[0])+func(se[1]);
    }
    if (c == '-') {
        return abs(func(se[0])-func(se[1]));
    }
    if (c == '*') {
        return func(se[0])*func(se[1]);
    }
    if (c == '/') {
        ll f0 = func(se[0]),f1 = func(se[1]);
        return f0>f1 ? f0/f1 : f1/f0;
    }
    return INT_MIN;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    t = v<string>(n);
    cin >> t;
    int x,y;
    rep(i,n) rep(j,m) if (t[i][j]=='P') x=i,y=j;
    print(func({x,y}));

    return 0;
}
