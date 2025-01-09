#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        int buy_p = prices[0];
        for (int i=0; i<n; i++){
            if (prices[i] > buy_p){
                res = max(res, prices[i]-buy_p);
            }
            else{
                buy_p = prices[i];
            }
        }
        return res;

        // // 超出时间限制， case4
        // int res = 0;
        // int n = prices.size();
        // int buy_p = prices[0];
        // for (int i=0; i<n-1; i++){
        //     // 如果之后日子买入股票价格高于之前的价格，则跳过
        //     if (prices[i] > buy_p){
        //         continue;
        //     }
        //     else{
        //         buy_p = prices[i];
        //     }

        //     // 找到高卖出股票价格
        //     int sell_p = 0;
        //     for (int j=i+1; j<n; j++){
        //         if (prices[j] >= sell_p){
        //             sell_p = prices[j];
        //         }
        //     }
        //     res = max(res, sell_p - prices[i]);
        // }
        // return res;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
}