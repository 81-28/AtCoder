// https://atcoder.jp/contests/abc424/tasks/abc424_f

#include<bits/stdc++.h>
using namespace std;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


class SegmentTree_min {
public:
    vector<int> vec,lazy;
    int size=1;
    SegmentTree_min(const int& n) {
        while(size<n)size*=2;
        vec=vector<int>(size*2,0);
        lazy=vector<int>(size*2,0);
    }
    // 遅延評価の伝播
    // pos: 現在地のノード番号, [a,b): 現在の区間
    void push(const int& pos,const int& a,const int& b) {
        if (lazy[pos]!=0) {
            vec[pos]+=lazy[pos];
            if (b-a>1) {
                lazy[pos*2]+=lazy[pos];
                lazy[pos*2+1]+=lazy[pos];
            }
            lazy[pos]=0;
        }
    }
    // 区間更新の内部関数
    // [l,r): 更新対象区間, [a,b): 現在の区間, pos: 現在地のノード番号
    void update(const int& l,const int& r,const int& x,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return;
        if (l<=a&&b<=r) {
            lazy[pos]+=x;
            push(pos,a,b);
            return;
        }
        int m=(a+b)/2;
        update(l,r,x,a,m,pos*2);
        update(l,r,x,m,b,pos*2+1);
        vec[pos]=min(vec[pos*2],vec[pos*2+1]);
    }
    // 区間 [l,r) を +x で一括更新
    void update(const int& l,const int& r,const int& x) {update(l,r,x,0,size,1);}
    // 1点更新
    void update(const int& pos,const int& x) {update(pos,pos+1,x);}
    // 区間 [l,r) の最小値取得
    // [l,r): クエリ区間, [a,b): 現在の区間, pos: 現在地のノード番号
    int query(const int& l,const int& r,const int& a,const int& b,const int& pos) {
        push(pos,a,b);
        if (r<=a||b<=l) return INT_MAX;
        if (l<=a&&b<=r) return vec[pos];
        int m=(a+b)/2;
        int ql=query(l,r,a,m,pos*2);
        int qr=query(l,r,m,b,pos*2+1);
        return min(ql,qr);
    }
    // 区間 [l,r) の最小値取得（外部用）
    int mi(const int& l,const int& r) {return query(l,r,0,size,1);}
    // 要素にアクセスする関数
    int at(const int& pos) {return mi(pos,pos+1);}
};

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    cin >> n >> q;
    SegmentTree_min t(n);
    while (q--) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        // 区間の始まりと終わりが同じ高さで、区間内でその高さを下回らなけらば、交わらない
        int tb=t.at(b);
        if (((a && t.at(a-1)==tb) || (a==0 && tb==0)) && t.mi(a,b)>=tb) {
            YesNo(1);
            t.update(a,b,1);
        } else {
            YesNo(0);
        }
    }


    return 0;
}
