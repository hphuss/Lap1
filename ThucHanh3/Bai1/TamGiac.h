#ifndef TAMGIAC_H_INCLUDED
#define TAMGIAC_H_INCLUDED
#include "Diem.h"
#include <string>

using namespace std;
class cTamGiac
{
private:
    cDiem A, B, C;
public:
    cTamGiac();
    cTamGiac(cDiem a, cDiem b, cDiem c);

    void NhapTamGiac();
    void XuatTamGiac() const;

    bool KiemTraHopLe() const;
    string KiemTraLoai() const;
    double TinhChuVi() const;
    double TinhDienTich() const;

    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);
};


#endif // TAMGIAC_H_INCLUDED
