// https://atcoder.jp/contests/abc308/tasks/abc308_d

#include<bits/stdc++.h>
using namespace std;

#define YesNo(x) puts(x?"Yes":"No")
#define f first
#define s second
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;
using pii=pair<int,int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string sn="snuke";
    int h,w;
    cin >> h >> w;
    v<string> st(h);
    cin >> st;
    if (st[0][0]!=sn[0]) {
        YesNo(0);
        return 0;
    }

    vvi d(h,vi(w,-1));
    queue<pii> q;
    d[0][0]=0;
    q.push({0,0});
    pii pos;
    int dist;
    while (!q.empty()) {
        pos=q.front();
        q.pop();
        dist=d[pos.f][pos.s]+1;
        if (pos.f<h-1 && d[pos.f+1][pos.s]==-1 && st[pos.f+1][pos.s]==sn[dist%5]) {
            d[pos.f+1][pos.s]=dist;
            q.push({pos.f+1,pos.s});
        }
        if (pos.s<w-1 && d[pos.f][pos.s+1]==-1 && st[pos.f][pos.s+1]==sn[dist%5]) {
            d[pos.f][pos.s+1]=dist;
            q.push({pos.f,pos.s+1});
        }
        if (pos.f && d[pos.f-1][pos.s]==-1 && st[pos.f-1][pos.s]==sn[dist%5]) {
            d[pos.f-1][pos.s]=dist;
            q.push({pos.f-1,pos.s});
        }
        if (pos.s && d[pos.f][pos.s-1]==-1 && st[pos.f][pos.s-1]==sn[dist%5]) {
            d[pos.f][pos.s-1]=dist;
            q.push({pos.f,pos.s-1});
        }
    }
    YesNo(d[h-1][w-1]!=-1);

    return 0;
}
