#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cctype>

using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i=0; i<n+1; i++){
            int temp = 0;
            int num = i;
             while(num){
                if (num & 1){
                    temp ++;
                }
                num = num>>1;
             }
             res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    vector<int> res = s.countBits(n);
    for (int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
}