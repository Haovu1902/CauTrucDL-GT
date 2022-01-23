#include <iostream>
#include <cstring>


using namespace std;

bool ketQuaTimChuCai(const char *ptr_s, const char &c){
    if (*ptr_s == '\0'){
        return false;
    }
    else if (*ptr_s == c){
        return true;
    }
    return ketQuaTimChuCai(ptr_s + 1, c);
}
int main(){
    char s[100];
    cout << "Nhap xau ki tu: ";
    cin.getline(s, 100);
    char c;
    cout << "Nhap chu cai can tim: ";
    cin >> c;
    cout << endl;
    if (ketQuaTimChuCai(s, c) == true){	
        cout << "Co chu " << "\'" << c << "\'" << " trong xau ki tu " << "\"" << s << "\"";        
    }
    else{
        cout << "Khong co chu  " << "\'" << c << "\'" << " trong xau ki tu " << "\"" << s << "\"";
    }
    return 0;
}
