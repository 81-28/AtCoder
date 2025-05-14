// pair

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define f first
#define s second
using ll=long long;
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const pii dir[4]={{-1,0},{1,0},{0,-1},{0,1}};

template<typename F,typename S>istream &operator>>(istream &is,pair<F,S> &p){is>>p.f>>p.s;return is;}
template<typename F,typename S> ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.f<<" "<<p.s;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail> void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

// pair同士の足し算
template<typename F,typename S> pair<F,S> operator+(const pair<F,S>& a,const pair<F,S>& b){return{a.f+b.f,a.s+b.s};}
// pairの加算代入 (+=)
template<typename F,typename S> pair<F,S>& operator+=(pair<F,S>& a,const pair<F,S>& b){a.f+=b.f;a.s+=b.s;return a;}
// pairのインクリメント (++)
template<typename F,typename S> pair<F,S>& operator++(pair<F,S>& p){++p.f;++p.s;return p;}
// 後置インクリメント (a++)
// ダミーのintを受け取り、衝突を回避
template<typename F,typename S> pair<F,S> operator++(pair<F,S>& a,int){pair<F,S>b=a;++a;return b;}

// pair同士の引き算
template<typename F,typename S> pair<F,S> operator-(const pair<F,S>& a,const pair<F,S>& b){return{a.f-b.f,a.s-b.s};}
// pairの減算代入 (-=)
template<typename F,typename S> pair<F,S>& operator-=(pair<F,S>& a,const pair<F,S>& b){a.f-=b.f;a.s-=b.s;return a;}
// pairのデクリメント (--)
template<typename F,typename S> pair<F,S>& operator--(pair<F,S>& p){--p.f;--p.s;return p;}
// 後置デクリメント (a--)
template<typename F,typename S> pair<F,S> operator--(pair<F,S>& a,int){pair<F,S>b=a;--a;return b;}

// // pair同士の掛け算
// template<typename F,typename S> pair<F,S> operator*(const pair<F,S>& a,const pair<F,S>& b){return{a.f*b.f,a.s*b.s};}
// // pairの乗算代入 (*=)
// template<typename F,typename S> pair<F,S>& operator*=(pair<F,S>& a,const pair<F,S>& b){a.f*=b.f;a.s*=b.s;return a;}

// pairと定数の掛け算
template<typename F,typename S,typename T> pair<F,S> operator*(const pair<F,S>& p,const T& a){return{p.f*a,p.s*a};}
// 定数とpairの掛け算
template<typename F,typename S,typename T> pair<F,S> operator*(const T& a,const pair<F,S>& p){return{a*p.f,a*p.s};}
// pairの乗算代入 (定数)
template<typename F,typename S,typename T> pair<F,S>& operator*=(pair<F,S>& p,const T& a){p.f*=a;p.s*=a;return p;}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    pii a,b;
    cin >> a >> b;
    print(a);
    print(b);
    print(a+b);
    a+=b;
    print(a);
    print(++a);
    print(a++);
    print(a);

    // pairのテンプレートを活用した例
    pii current = {2, 5};
    print("Current position:", current);
    rep(i,4) {
        pii next = current + dir[i];
        print("Next1 position:", next);
        next = current + 2*dir[i];
        print("Next2 position:", next);
    }

    return 0;
}
