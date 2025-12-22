// https://atcoder.jp/contests/abc309/tasks/abc309_f

#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;

constexpr int INF=numeric_limits<int>::max()/4;
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


using S=int;
S op(S a,S b){return min(a,b);}
S e(){return INF;}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<tuple<int,int,int>> t(n);
    vi hh,ww,dd;
    for (auto&[h,w,d]:t) {
        vi a(3);
        cin >> a;
        sort(all(a));
        h=a[0],w=a[1],d=a[2];
        hh.pb(h),ww.pb(w),dd.pb(d);
    }
    // 座標圧縮
    sort(all(hh)),sort(all(ww)),sort(all(dd));
    uniq(hh),uniq(ww),uniq(dd);
    unordered_map<int,int> mh,mw,md;
    rep(i,hh.size()) mh[hh[i]]=i;
    rep(i,ww.size()) mw[ww[i]]=i;
    rep(i,dd.size()) md[dd[i]]=i;
    for (auto&[h,w,d]:t) h=mh[h],w=mw[w],d=md[d];

    sort(all(t),[](const auto& a,const auto& b) {
        const auto&[ah,aw,ad]=a;
        const auto&[bh,bw,bd]=b;
        if (ah==bh)  return aw>bw;
        else return ah<bh;
    });

    // 自身より小さいwで、自身より小さいdが存在するか確かめる
    segtree<S,op,e> s(n);
    for (auto[h,w,d]:t) {
        if (s.prod(0,w)<d) {
            YesNo(1);
            return 0;
        }
        if (s.get(w)>d) s.set(w,d);
    }
    YesNo(0);

    return 0;
}
