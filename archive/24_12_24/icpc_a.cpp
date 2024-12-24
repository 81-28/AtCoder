// https://codeforces.com/gym/105633/problem/A

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T min(const vector<T>& v){return *min_element(v.begin(),v.end());}

int f(const int& n, const vi& d) {
    if (n==1) return 1;

    int mi = min(d);
    v<bool> done(n,0);
    bool ok = 1;
    rep(i,n) {
        if (d[i] == mi) done[i]=1;
        else ok = 0;
    }
    if (ok) return 1;

    int res = 1;
    int l = 0,r = 0;
    for (int i=1; i<n; i++) {
        if (done[i-1] && !done[i]) {
            l = i;
        }
        if (!done[i-1] && done[i]) {
            r = i;
            res += f(r-l,vi(d.begin()+l,d.begin()+r));
        }
    }
    if (!done[n-1]) {
        r = n;
        res += f(r-l,vi(d.begin()+l,d.begin()+r));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi d(n);
    cin >> d;
    print(f(n,d));

    return 0;
}
