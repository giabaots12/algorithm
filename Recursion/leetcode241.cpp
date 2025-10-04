#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ketqua;
        if(count(expression.begin(), expression.end(), '+') == 0 &&
           count(expression.begin(), expression.end(), '-') == 0 &&
           count(expression.begin(), expression.end(), '*') == 0){
            ketqua.push_back(stoi(expression));
            return ketqua;
        }
        for(int i = 0; i < expression.size(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int>left = diffWaysToCompute(expression.substr(0, i));
                vector<int>right = diffWaysToCompute(expression.substr(i + 1));
                for(int a : left){
                    for(int b : right){
                        if(expression[i] == '+') ketqua.push_back(a + b);
                        if(expression[i] == '-') ketqua.push_back(a - b);
                        if(expression[i] == '*') ketqua.push_back(a * b);
                    }
                }
            }
        }
        return ketqua;
    }
};

int main(){
    Solution b;
    string s;
    cin>>s;
    vector<int> a = b.diffWaysToCompute(s);
    for(int v : a){
        cout<<v<<" ";
    }
    return 0;
}