#include"conio.h"
#include"stdio.h"
#include"HASHTBL.cpp"
#include<bits/stdc++.h>

using namespace std;

int stringToInt(string str) {                 // ham tinh tong ma ASCII cua 1 tu
	int sum = 0;
	for(int i = 0; i < str.length(); i++) {
		sum += str[i];
	}
	return sum;
}
int h(string key, int m)						// ham chia lay du cac tu de xep vao cac ngan trong bang bam
{
	int keyInt = stringToInt(key);
	return keyInt % m;
}

//kiem tra
vector<string> tachVanBan(string s) {				// ham de tach van ban thanh cac tu roi luu vao vector
	vector<string> p;
	long long j;
	for(long long i=0; i < s.length(); i++) {
		if(s[i] != 32) {
			j=i;
			string t="";
			while(s[j] != 32 and j<s.length()) {
				t+=s[j];
				j++;
			}
			p.push_back(t);
			i = j-1;
		}
	}
	return p;
}
int main()
{
	//khai bao file
	string file;
	cout <<"Nhap ten file tu dien:";
	cin >> file;
	ifstream input(file); //nhap file input.txt
	while(input.fail()){
		cout <<"\tKhong ton tai file. Moi ban nhap lai: ";
		input.close(); 
		cin >> file;
		input.open(file);
	}
	
	Hashtable<string, string> ht(97); //table nay co 97 list 
	//nhap tu dien vao bang bam
	string key, elem;
	while(!input.eof()) { // doc den khi het file thi dung
		input>>key;
		input>>elem;
		ht.Add(key, elem, h);
	}
nhapVanBan:	
	cout <<"Nhap doan van ban can kiem tra:\n";
	fstream output;
	output.open(file, ios::app); 
	// them ios::app la de ghi tiep noi dung vao file da co
	string s;
	cin.ignore();
	getline(cin, s);
	cout << "\tCac tu sai chinh ta: \n";
	vector<string> p = tachVanBan(s);
	int kt=0;
	for(int i=0; i<p.size(); i++) {
		if(!ht.Contains(p[i], h)){
			cout << p[i] << "\n";
			kt=1;
		} 
	}
	if(kt==0) cout <<"\t\tKhong co tu sai chinh ta.";
	
	cout <<"Viet cac tu muon them vao tu dien, nhan 'end' de ket thuc:";
	string tu, nghia;
	while(1) {
		cout<<"\n\tNhap tu: ";
		cin >> tu;
		if(tu=="end") break;
		cout<<"\tNhap nghia: ";
		cin >> nghia;
		ht.Add(tu,nghia, h);
		output<<tu << " " << nghia << "\n";	
	}
	cout << "Lua chon:\n 1.Nhap doan van ban can kiem tra tiep\n 2.Dung chuong trinh\nNhap so de chon:";
	int luachon;
	cin >> luachon;
	if(luachon==1) goto nhapVanBan;
//	getch();
	return 0;
}
