// https://atcoder.jp/contests/abc445/tasks/abc445_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<' '<<p.second;return os;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int h,w,n;
    cin >> h >> w >> n;
    multiset<int> hei,wid;
    map<int,multiset<pii>> ver,hor;
    rep(i,n) {
        int x,y;
        cin >> x >> y;
        hei.insert(x);
        wid.insert(y);
        ver[x].insert({y,i});
        hor[y].insert({x,i});
    }
    v<pii> ans(n);
    int x=1,y=1;
    rep(i,n) {
        auto ith=hei.find(h);
        if (ith!=hei.end()) {
            auto itw=ver[h].begin();
            auto[nw,j]=*itw;
            ans[j]={x,y};
            y+=nw;
            ver[h].erase(itw);
            hei.erase(ith);
            hor[nw].erase(hor[nw].find({h,j}));
            wid.erase(wid.find(nw));
            w-=nw;
        } else {
            auto itww=wid.find(w);
            auto ithh=hor[w].begin();
            auto[nh,j]=*ithh;
            ans[j]={x,y};
            x+=nh;
            hor[w].erase(ithh);
            wid.erase(itww);
            ver[nh].erase(ver[nh].find({w,j}));
            hei.erase(hei.find(nh));
            h-=nh;
        }
    }
    rep(i,n) print(ans[i]);

    return 0;
}
