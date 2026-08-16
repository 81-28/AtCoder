// https://atcoder.jp/contests/abc471/tasks/abc471_f

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
using pii=pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define pb push_back
#define all(v) v.begin(),v.end()

#define endl '\n' // flushしたい場合は無効化

// 先頭の0を削除
string trim_zero(const string& s){
    int i=0;
    while(i<(int)s.size() && s[i]=='0') ++i;
    return s.substr(i);
}

// 先頭の0を無視して整数として比較
bool num_cmp(string a,string b){
    a=trim_zero(a);
    b=trim_zero(b);

    if(a.size()!=b.size()) return a.size()>b.size();
    return a>b;
}

// 連結した値が大きくなる順に比較
bool concat_cmp(const string& a,const string& b){
    return a+b>b+a;
}

// 先頭に採用する文字列同士を比較
bool head_cmp(const string& a,const string& b){
    string ta=trim_zero(a);
    string tb=trim_zero(b);

    int len=max(ta.size(),tb.size())+lcm(a.size(),b.size());

    for(int i=0;i<len;++i){
        char ca = i<(int)ta.size()
            ? ta[i]
            : a[(i-ta.size())%a.size()];

        char cb = i<(int)tb.size()
            ? tb[i]
            : b[(i-tb.size())%b.size()];

        if(ca!=cb) return ca>cb;
    }

    return false;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    // cnt[i]:長さiの文字列の個数
    vi cnt(11,0);
    v<string> s(n);
    for (string& t:s) {
        cin >> t;
        ++cnt[t.size()];
    }
    // {答えの長さ,先頭文字列のidx}
    v<pii> p;
    rep(i,n) {
        string t=trim_zero(s[i]);
        if (t.empty()) continue;

        int l=s[i].size();
        // s[i]を先頭に使うので、一旦残りの候補から除く
        --cnt[l];
        int sm=t.size();
        int rem=k-1;
        // 残りK-1個は長い文字列から選ぶ
        for(int len=10;len>=1 && rem>0;--len){
            int use=min(rem,cnt[len]);
            sm+=use*len;
            rem-=use;
        }
        p.pb({sm,i});
        ++cnt[s[i].size()];
    }
    if (p.empty()) {
        cout<<0<<endl;
        return 0;
    }

    // 先頭を決める
    sort(all(p),[&](const pii& a,const pii& b){
        if(a.first!=b.first) return a.first>b.first;
        return head_cmp(s[a.second],s[b.second]);
    });

    int head=p[0].second;

    // 先頭以外の文字列
    vi id;
    rep(i,n) {
        if (i!=head) id.pb(i);
    }

    // 残りK-1個を選ぶ
    // まず長さを最大化し、同じ長さなら辞書順で大きいものを優先
    sort(all(id),[&](int a,int b){
        if(s[a].size()!=s[b].size()){
            return s[a].size()>s[b].size();
        }
        return s[a]>s[b];
    });

    v<string> ans;
    rep(i,k-1) ans.pb(s[id[i]]);
    // 選んだ文字列を連結結果が最大になる順に並べる
    sort(all(ans),concat_cmp);
    // 先頭のみ余分な0を削除
    cout<<trim_zero(s[head]);
    for(const string& t:ans) cout<<t;
    cout<<endl;

    return 0;
}
