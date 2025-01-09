#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > quick_sort(vector<vector<int> >& arr){
        int n = arr.size();
        if (n <= 1){
            return arr;
        }
        vector<int> pivot = arr[n/2];
        vector<vector<int> > left, middle, right;
        for (int i=0; i<n; i++){
            if (arr[i][0] == pivot[0]){
                middle.push_back(arr[i]);
            }
            else if(arr[i][0] > pivot[0] || (arr[i][0] == pivot[0] && arr[i][1] < pivot[1]) ){
                left.push_back(arr[i]);
            }
            else{
                right.push_back(arr[i]);
            }
        }
        vector<vector<int> > sorted_left = quick_sort(left);
        vector<vector<int> > sorted_right = quick_sort(right);

        sorted_left.insert(sorted_left.end(), middle.begin(), middle.end());
        sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());
        
        return sorted_left;
    }

    vector<vector<int> > insert_sort(vector<vector<int> >& arr){
        vector<vector<int> > res;
        for (int i=0; i<arr.size(); i++){
            res.insert(res.begin()+arr[i][1], arr[i]);
        }
        return res;
    }

    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        int n = people.size();
        quick_sort(people);
        insert_sort(people);     
        return people;
    }
};

int main(){
    Solution s;
    // vector<vector<int> > people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}; //这个错误表明你的编译器可能不支持 C++11 或更高标准的语法，特别是列表初始化功能
    vector<vector<int> > people;
    people.push_back(vector<int>{7, 0});
    people.push_back(vector<int>{4, 4});
    people.push_back(vector<int>{7, 1});
    people.push_back(vector<int>{5, 0});
    people.push_back(vector<int>{6, 1});
    people.push_back(vector<int>{5, 2});
    vector<vector<int> > res = s.reconstructQueue(people);
    for (int i=0; i<res.size(); i++){
        // cout << res[i] << endl;
        cout << "[" << res[i][0] << ", " << res[i][1] << "]" << endl; // 格式化输出
    }
}