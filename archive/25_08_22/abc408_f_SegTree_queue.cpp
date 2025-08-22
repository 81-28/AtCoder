// https://atcoder.jp/contests/abc408/tasks/abc408_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
template<typename T>inline bool chmax(T& a,const T& b){if(a<b){a=b;return 1;}return 0;}

#define f first
#define s second

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


class SegmentTree_max {
public:
    vector<int> vec;
    int size=1;
    SegmentTree_max(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,-1);
    }
    void update(int pos,const int& x) {
        pos+=size;
        vec[pos]=x;
        while(pos>1) {
            pos/=2;
            vec[pos]=max(vec[pos*2],vec[pos*2+1]);
        }
    }
    // [l,r): 求める対象の区間, [a,b): 現在の区間, pos: 現在地の番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        if (r<=a||b<=l) return INT_MIN; // 一切重ならない場合
        if (l<=a&&b<=r) return vec[pos]; // 完全に含まれる場合
        // 現在の区間内に境目(l||r)が存在する場合、子の最大値を求める
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return max(ql,qr);
    }
    // [l,r): 求める対象の区間
    int mx(const int& l,const int& r) {return query(l,r,0,size,1);}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d,r;
    cin >> n >> d >> r;
    v<pii> p(n);
    rep(i,n) {
        cin >> p[i].f;
        p[i].s=i;
    }
    sort(all(p));
    // 移動回数
    SegmentTree_max t(n);
    // {高さ,idx,回数}
    queue<tuple<int,int,int>> q;
    // 高さは1~nの順列なので、queueを使わなくても、毎回dだけ低い足場を追加すればよい
    int ans=0;
    for (auto[h,i]:p) {
        while (!q.empty()&&get<0>(q.front())<=h-d) {
            auto[qh,qi,qc]=q.front();
            q.pop();
            t.update(qi,qc);
        }
        int c=t.mx(max(0,i-r),min(n,i+1+r))+1;
        chmax(ans,c);
        q.push({h,i,c});
    }
    print(ans);
    // rep(i,n) {
    //     cout<<t.vec[i+t.size]<<' ';
    // }
    // cout<<endl;

    return 0;
}
