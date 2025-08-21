#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void changenos(int &a,int &b){
    int temp = a;
    a= b;
    b = temp;
}
int main() {
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // bubbleSort(arr, n);
    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
int a=2;
int b=4;
changenos(a,b);
cout<<"a="<<a<<"and b="<<b;

    return 0;
}
