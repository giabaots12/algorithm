#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int> &a, int l, int r){
    int pi = a[r];
    int k = l - 1;
    for(int i = l; i < r; i++){
        if(a[i] < pi){
            k++;
            swap(a[k], a[i]);
        }
    }
    swap(a[k + 1], a[r]);
    return k + 1;
}

void quickSort(vector<int> &a, int l, int r){
    if(l < r){
        int pi = partition(a, l, r);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, r);
    }
}


int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
