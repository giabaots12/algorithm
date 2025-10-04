#include <iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        return winnerbase0(n, k) + 1;
    }

private:

    int winnerbase0(int n, int k){
        if(n == 1) return 0;
        return (winnerbase0(n - 1, k) + k) % n;
    }
};

int main(){
    Solution sol;
    int n, k;
    cin>>n>>k;
    cout<<sol.findTheWinner(n, k);





    return 0;
}