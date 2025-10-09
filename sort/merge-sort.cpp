#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> l1(n1);
    vector<int> l2(n2);
    for(int i = 0; i < n1; i++){
        l1[i] = a[l + i];
    }
    for(int i = 0; i < n2; i++){
        l2[i] = a[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n1 && j < n2){
        if(l1[i] < l2[j]){
            a[l + k] = l1[i];
            k++;
            i++;
        }else{
            a[l + k] = l2[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        a[l + k] = l1[i];
        k++;
        i++;
    }
    while(j < n2){
        a[l + k] = l2[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int> &a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
