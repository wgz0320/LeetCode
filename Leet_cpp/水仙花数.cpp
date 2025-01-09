#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int num = 100;
    while(num<=999)
    {
        int i = num/100;
        int j = (num-i*100)/10;
        int k = num%10;
        if (pow(i,3) + pow(j,3) + pow(k,3) == num)
        {
            cout << num << endl;
        }
        num++; 
    }
    return 0;
}