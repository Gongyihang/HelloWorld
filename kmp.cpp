#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> KMP(string pat)
{
    int M = pat.size();
    // dp[状态][字符] = 下个状态
    vector<vector<int>> dp(M, vector<int>(256));
    // base case
    dp[0][pat[0]] = 1;
    // 影子状态 X 初始为 0
    int X = 0;
    // 构建状态转移图（稍改的更紧凑了）
    for (int j = 1; j < M; j++) {
        for (int c = 0; c < 256; c++) {
            dp[j][c] = dp[X][c];
            dp[j][pat[j]] = j + 1;
            // 更新影子状态
            X = dp[X][pat[j]];
        }
    }
    return dp;
}

int search(string txt, string pat, vector<vector<int>> dp)
{
    int M = pat.size();
    int N = txt.size();
    // pat 的初始态为 0
    int j = 0;
    for (int i = 0; i < N; i++) {
        // 计算 pat 的下一个状态
        j = dp[j][txt[i]];
        // 到达终止态，返回结果
        if (j == M)
            return i - M + 1;
    }
    // 没到达终止态，匹配失败
    return -1;
}

int main()
{
    string pat; //模式串
    string txt; //文本串
    cin >> pat >> txt;
    vector<vector<int>> dp(pat.size(), vector<int>(256));
    dp = KMP(pat); //状态机解KMP
    int index = search(txt, pat, dp); //匹配成功返回文本串下标
    if (index) { //否则返回-1
        string t1 = txt.substr(0, index); //切掉字符串前半部分
        string t2 = txt.substr(index + pat.size()); //切掉字符串后半部分
        string res = t1 + t2; //组合
        cout << res << endl;
    } else {
        cout << "-1" << endl;
    }
    system("pause");
    return 0;
}