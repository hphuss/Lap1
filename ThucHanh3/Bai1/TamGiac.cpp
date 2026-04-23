#include "TamGiac.h";
#include <iostream>
#include <cmath>

using namespace std;

const double EPSILON = 1e-5;
bool isEqual(double a, double b)
{
    return abs(a-b)<EPSILON;
}

cTamGiac::cTamGiac(){}
cTamGiac::cTamGiac(cDiem a, cDiem b, cDiem c): A(a), B(b), C(c) {}

void cTamGiac::NhapTamGiac()
{
    do{
        cout<<"Nhap dinh A:\n"; A.NhapDiem();
        cout<<"Nhap dinh B:\n"; B.NhapDiem();
        cout<<"Nhap dinh C:\n"; C.NhapDiem();

        if(!KiemTraHopLe()){cout<<"Ba diem hien khong tao thanh tam giac. Vui long nhap lai!\n";}
    }while(!KiemTraHopLe());
}
void cTamGiac::XuatTamGiac() const
{
    cout << "A"; A.XuatDiem();
    cout << ", B"; B.XuatDiem();
    cout << ", C"; C.XuatDiem();
    cout << "\n";
}
bool cTamGiac::KiemTraHopLe() const
{
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);

    return (a + b > c) && (a + c > b) && (b + c > a);
}
string cTamGiac::KiemTraLoai() const
{
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);

    bool vuong = isEqual(a*a + b*b, c*c) || isEqual(a*a + c*c, b*b) || isEqual(b*b + c*c, a*a);
    bool can = isEqual(a, b) || isEqual(a, c) || isEqual(b, c);
    bool deu = isEqual(a, b) && isEqual(b, c);

    if (deu) return "Tam giac deu";
    if (vuong && can) return "Tam giac vuong can";
    if (vuong) return "Tam giac vuong";
    if (can) return "Tam giac can";
    return "Tam giac thuong";
}
double cTamGiac::TinhChuVi() const
{
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);
    return a + b + c;
}
double cTamGiac::TinhDienTich() const
{
    double a = B.TinhKhoangCach(C);
    double b = A.TinhKhoangCach(C);
    double c = A.TinhKhoangCach(B);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
void cTamGiac::TinhTien(double dx, double dy) {
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}
void cTamGiac::Quay(double goc_rad) {
    A.Quay(goc_rad);
    B.Quay(goc_rad);
    C.Quay(goc_rad);
}
void cTamGiac::PhongToThuNho(double k) {
    A.PhongToThuNho(k);
    B.PhongToThuNho(k);
    C.PhongToThuNho(k);
}
