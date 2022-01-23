#include <iostream>
#include <cmath>


using namespace std;


void nhapDaThuc(double *a, int &n)
{
    cout << "Nhap bac cua da thuc: ";
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << endl; 
}
void inDaThuc(const double *a, const int &n)
{
    cout << "f(x) = ";
    for (int i = 0; i <= n; i++)
    {
        if (i == 0){
            cout << a[i] << " + ";
        }
        else if (i == n){
            cout << a[i] << "x^" << i;
        }
         else{
            cout << a[i] << "x^" << i << " + ";
        }
    }
    cout << endl;
}
double giaTriDaThuc(const double *a, const int &n, const double &x)
{
    if (n == 0){
        return a[0];
    }
    else{
        return a[n] * pow(x, n) + giaTriDaThuc(a, n - 1, x);
    }
}
int main()
{
    int n;
    double a[100];
    nhapDaThuc(a, n);
    inDaThuc(a, n);
    double x;
    cout << "x = ";
    cin >> x;
    cout << "\nf" << "(" << x << ") = " << giaTriDaThuc(a, n, x);
    return 0;
}
