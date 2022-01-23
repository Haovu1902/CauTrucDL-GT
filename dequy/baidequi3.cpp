#include <iostream>
#include <cmath>


using namespace std;


void nhapDay(double *a, int &n){
    cout << "Nhap n = ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void inDay(const double *a, const int &n){
    for (int i = 0; i < n; i++){
        cout << a[i] << "  ";
    }
}
double mincuaday(const double *a, const int &n){
    if (n == 2){
        return min(a[1], a[0]);
    }
    else if (n == 1){
        return a[0];
    }
    return min(a[n - 1], mincuaday(a, n - 1));
}
int main()
{
    int n;
    double a[100];
    nhapDay(a, n);
    inDay(a, n);
    cout << endl;
    cout << "Gia tri nho nhat cua day so la: " << mincuaday(a, n);
    return 0;
}
