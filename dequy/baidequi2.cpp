#include <iostream>
#include <cmath>


using namespace std;

void inUocSoChung(const int &a, const int &b, const int i = 1){
    if (a % i == 0 && b % i == 0){
        cout << i << " ";
    }
    if (i == a || i == b){
        return;
    }
    inUocSoChung(a, b, i + 1);
}
int main(){
    int a, b;
    cout << "Nhap a va b: ";
    cin >> a >> b;
    cout << "\nUoc so chung cua " << a << " va " << b << " la: ";
    inUocSoChung(a, b);
    return 0;
}
