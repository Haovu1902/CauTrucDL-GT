#include <iostream>
#include <string>
#include "My_Single_List.cpp"
using namespace std;

class SinhVien
{
private:
    int MSV;
    string ho_ten;
    int ngay_sinh, thang_sinh, nam_sinh;
    string gioi_tinh;
    string que_quan;

public:
    SinhVien(const int &_MSV = 0, const string &_ho_ten = "INVALID", const int &_ngay_sinh = 0, const int &_thang_sinh = 0, const int &_nam_sinh = 0, const string &_gioi_tinh = "INVALID", const string &_que_quan = "INVALID")
    {
        MSV = _MSV;
        ho_ten = _ho_ten;
        ngay_sinh = _ngay_sinh;
        thang_sinh = _thang_sinh;
        nam_sinh = _nam_sinh;
        gioi_tinh = _gioi_tinh;
        que_quan = _que_quan;
    }

    void nhap()
    {
        cout << "\tMa sinh vien: ";
        cin >> MSV;

        cout << "\tHo ten: ";
        cin.ignore(32767, '\n');
        getline(cin, ho_ten);

        cout << "\tSinh nhat (ngay thang nam): ";
        cin >> ngay_sinh >> thang_sinh >> nam_sinh;

        cout << "\tGioi tinh: ";
        cin.ignore(32767, '\n');
        getline(cin, gioi_tinh);

        cout << "\tQue quan: ";
        getline(cin, que_quan);
    }

    void xuat()
    {
        cout << "\tMa sinh vien: " << MSV << endl;

        cout << "\tHo ten: " << ho_ten << endl;

        cout << "\tSinh nhat: " << ngay_sinh << "/" << thang_sinh << "/" << nam_sinh << endl;

        cout << "\tGioi tinh: " << gioi_tinh << endl;

        cout << "\tQue quan: " << que_quan << endl;
    }
};

void push_back(SLIST<SinhVien> &sv, const SinhVien &value)
{
    sv.push_back(value);
}

void push_back(SLIST<SinhVien> &sv)
{
    SinhVien value;
    cout << "\nNhap thong tin sinh vien muon them vao cuoi danh sach:\n";
    value.nhap();
    sv.push_back(value);
}

void push_front(SLIST<SinhVien> &sv, const SinhVien &value)
{
    sv.push_front(value);
}

void push_front(SLIST<SinhVien> &sv)
{
    SinhVien value;
    cout << "\nNhap thong tin sinh vien muon them vao dau danh sach:\n";
    value.nhap();
    sv.push_front(value);
}

void erase(SLIST<SinhVien> &sv, int i)
{
    SLIST<SinhVien>::iterator it = sv.begin();
    while (i--)
    {
        it++;
    }

    sv.erase(it);
}

void replace(SLIST<SinhVien> &sv, int i, const SinhVien &value)
{
    SLIST<SinhVien>::iterator it = sv.begin();
    while (i--)
    {
        it++;
    }

    it.get_current()->set_element(value);
}

void inSV(SLIST<SinhVien> &sv)
{
    int i = 0;
    for (SLIST<SinhVien>::iterator it = sv.begin(); it != sv.end(); it++)
    {
        cout << "\nThong tin sinh vien thu " << i << ":\n";
        it.get_current()->get_element().xuat();
        i++;
    }
}

int main()
{
    SLIST<SinhVien> sv;
    SinhVien value1(1, "Le Xuan Quynh", 23, 9, 2002, "Nam", "Hung Cong");
    SinhVien value2(2, "Nguyen Dinh Loc", 5, 5, 2002, "Nam", "Binh Nghia");
    SinhVien value3(3, "Tran Xuan Dai", 30, 4, 1975, "Gay", "Binh Nghia");
    SinhVien value4(4, "Nguyen The Huong", 30, 9, 2002, "Nam", "Dong Du");

    push_back(sv, value1);
    push_front(sv, value2);
    push_back(sv, value3);
    inSV(sv);

    // xoa bo  sinh vien thu 2 khoi danh sach
    erase(sv, 2);
    cout << "\n---------------------SAU KHI XOA BO SV THU 2---------------------\n";
    inSV(sv);

    // thay the sinh vien thu 1 bang mot sinh vien moi
    replace(sv, 1, value4);
    cout << "\n---------------------SAU KHI THAY THE SV THU 1 BANG MOT SINH VIEN MOI---------------------\n";
    inSV(sv);
    return 0;
}