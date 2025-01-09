#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cctype>

using namespace std;
class Solution {
public:

    string decodeString(string s) {
        int n = s.size();
        string res;
        int num = 0;
        stack<string> s1;
        stack<int> s2;
        for (int i=0; i<n; i++){
            if (isdigit(s[i])){
                num = num * 10 + (s[i] - '0'); //累加数字到num
            }
            else if (s[i] == '['){
                s2.push(num);
                num = 0;
                s1.push(res);
                res = "";

            }
            else if (s[i] == ']'){
                int cur_num = s2.top();
                s2.pop();
                string cur_res = s1.top();
                s1.pop();

                string repeated;
                for (int j=0; j<cur_num; j++){
                    repeated += res;
                }
                // res = cur_res + res * cur_num; //c++字符串不能直接通过*运算符与整数相乘
                res = cur_res + repeated;

            }
            else{
                res += s[i];
            }
        }
        return res;
    }
};