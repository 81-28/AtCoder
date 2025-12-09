// https://atcoder.jp/contests/abc326/tasks/abc326_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,x,y;
    cin >> n >> x >> y;
    vi xx,yy;
    rep(i,n) {
        int a;
        cin >> a;
        if (i&1) xx.pb(a);
        else yy.pb(a);
    }
    int xs=xx.size(),ys=yy.size();
    int xf=xs/2,xb=xs-xf;
    int yf=ys/2,yb=ys-yf;
    unordered_map<int,int> mpf;
    mpf[0]=0;
    rep(i,xf) {
        unordered_map<int,int> mpp;
        for (auto[num,b]:mpf) {
            // +
            mpp[num+xx[i]]=b;
            // -
            mpp[num-xx[i]]=b|(1<<i);
        }
        mpf=mpp;
    }
    unordered_map<int,int> mpb;
    mpb[0]=0;
    rep(i,xb) {
        unordered_map<int,int> mpp;
        for (auto[num,b]:mpb) {
            // +
            mpp[num+xx[xf+i]]=b;
            // -
            mpp[num-xx[xf+i]]=b|(1<<i);
        }
        mpb=mpp;
    }
    bool ok=0;
    v<bool> vx;
    for (auto[numf,vf]:mpf) {
        if (mpb.find(x-numf)!=mpb.end()) {
            ok=1;
            rep(i,xf) vx.pb(vf>>i&1);
            rep(i,xb) vx.pb(mpb[x-numf]>>i&1);
            break;
        }
        if (ok) break;
    }
    if (!ok) {
        YesNo(0);
        return 0;
    }

    mpf.clear();
    mpf[0]=0;
    rep(i,yf) {
        unordered_map<int,int> mpp;
        for (auto[num,b]:mpf) {
            // +
            mpp[num+yy[i]]=b;
            // -
            mpp[num-yy[i]]=b|(1<<i);
        }
        mpf=mpp;
    }
    mpb.clear();
    mpb[0]=0;
    rep(i,yb) {
        unordered_map<int,int> mpp;
        for (auto[num,b]:mpb) {
            // +
            mpp[num+yy[yf+i]]=b;
            // -
            mpp[num-yy[yf+i]]=b|(1<<i);
        }
        mpb=mpp;
    }
    ok=0;
    v<bool> vy;
    for (auto[numf,vf]:mpf) {
        if (mpb.find(y-numf)!=mpb.end()) {
            ok=1;
            rep(i,yf) vy.pb(vf>>i&1);
            rep(i,yb) vy.pb(mpb[y-numf]>>i&1);
            break;
        }
        if (ok) break;
    }
    if (!ok) {
        YesNo(0);
        return 0;
    }

    bool last=0;
    string ans="";
    rep(i,xs) {
        ans.pb(last==vy[i]?'L':'R');
        last=vy[i];
        ans.pb(last!=vx[i]?'L':'R');
        last=vx[i];
    }
    if (ys>xs) {
        ans.pb(last==vy[ys-1]?'L':'R');
    }
    YesNo(1);
    print(ans);

    return 0;
}
