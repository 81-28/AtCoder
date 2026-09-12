// https://atcoder.jp/contests/abc475/tasks/abc475_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(v.begin(),v.end()),v.end()) // sort後に使用する

int int_pow(int a,int b) {
    int r=1;
    while(b){if(b&1)r*=a;a*=a;b>>=1;}
    return r;
}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


bool isPrime(const int& n) {
    if(n<=1)return 0;
    else if(n<=3)return 1;
    else if(!(n%2&&n%3))return 0;
    for (int i=5;i*i<=n;i+=6)if(!(n%i&&n%(i+2)))return 0;
    return 1;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n=s.size();
    if (n==1) {
        print(2);
        return 0;
    }
    string t=s;
    sort(all(t)),uniq(t);
    map<char,int> m;
    int l=t.size();
    rep(i,l) m[t[i]]=i;

    vi a(10);
    rep(i,10) a[i]=i;
    do {
        int res=0;
        int d=int_pow(10,n-1);
        rep(i,n) {
            int num=a[m[s[i]]];
            if (!i && !num) break;
            res+=num*d;
            d/=10;
        }

        if (isPrime(res)) {
            print(res);
            return 0;
        }
    } while (next_permutation(all(a)));
    print(-1);

    return 0;
}
