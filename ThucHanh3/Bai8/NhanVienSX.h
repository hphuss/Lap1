#ifndef NHANVIENSX_H_INCLUDED
#define NHANVIENSX_H_INCLUDED
#include "Ngay.h"
#include <string>

class cNhanVienSX {
private:
    std::string maNV;
    std::string hoTen;
    cNgay ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX();

    // Cac thao tac chinh
    void Nhap();
    void Xuat() const;
    double TinhLuong() const;

    // Ham ho tro lay thong tin ngay sinh de so sanh
    cNgay GetNgaySinh() const;
};

#endif // NHANVIENSX_H_INCLUDED
