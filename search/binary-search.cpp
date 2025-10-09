#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& a, int target) {
    int l = 0;
    int r = a.size() - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(a[m] < target){
            l = m + 1;
        }
        else if(a[m] > target){
            r = m - 1;
        }
        else{
            return m;
        }
    }
    return -1;
}




int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int pos = binarySearch(a, target);
    if (pos != -1) cout << "Found at index " << pos << endl;
    else cout << "Not found\n";
}
