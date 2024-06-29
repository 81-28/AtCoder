// https://atcoder.jp/contests/abc351/tasks/abc351_d

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;

int main() {
    int h,w,ans;
    cin >> h;
    cin >> w;
    vector<vector<int>> f;



    string s[h];
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            f[i][j] = 0;
        }
        
    }
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] != '#' && (s[i+1][j] == '#' || s[i-1][j] == '#' || s[i][j+1] == '#' || s[i][j-1] == '#'))
            {
                s[i][j] = '-';
                f[i][j] = 1;
            }
            
        }
        
    }

    void method(int H,int W){
        if (s[H][W] == '#')
        {
            f[H][W] = -1;
        }
    }
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            method(i,j);
        }
        
    }
    




    string strN;
    // 数字を入力
    cin >> strN;
    string newStr = strN;
    rep(i, strN.length()){
        // 文字を数字として扱う
        int num = (strN[i] - '0');
        cout << num << endl;
        // 前後を反転
        newStr[i] = strN[strN.length()-1-i];
    }
    cout << newStr << endl;


    return 0;
}
