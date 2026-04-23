#include <iostream>
#include "TamGiac.h"
#include <limits>
#include <cmath>
#include <string>

using namespace std;
double NhapSoThuc(const string& thongBao)
{
        double giaTri;
        while (true) {
            cout << thongBao;
            if (cin >> giaTri) {
                return giaTri;
            } else {
                cout << "Vui long chi nhap so\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
}
int main()
{
    const double PI = 3.14159265358979323846;

    cout<<"----CHUONG TRINH XU LY TAM GIAC----\n";
    cTamGiac tg;
    tg.NhapTamGiac();
    cout << "\n--- THONG TIN TAM GIAC ---\n";
    tg.XuatTamGiac();

    cout << "Loai tam giac: " << tg.KiemTraLoai() << "\n";
    cout << "Chu vi: " << tg.TinhChuVi() << "\n";
    cout << "Dien tich: " << tg.TinhDienTich() << "\n";


    cout << "\n--- THAO TAC TINH TIEN ---\n";
    cTamGiac tg_tinhtien = tg;
    double dx = NhapSoThuc("Nhap do doi dx: ");
    double dy = NhapSoThuc("Nhap do doi dy: ");
    tg_tinhtien.TinhTien(dx, dy);
    cout << "Tam giac sau khi tinh tien: ";
    tg_tinhtien.XuatTamGiac();


    cout << "\n--- THAO TAC QUAY ---\n";
    cTamGiac tg_quay = tg;
    double goc_do = NhapSoThuc("Nhap goc quay: ");
    double goc_rad = goc_do * PI / 180.0;
    tg_quay.Quay(goc_rad);
    cout << "Tam giac sau khi quay: ";
    tg_quay.XuatTamGiac();


    cout << "\n--- THAO TAC PHONG TO / THU NHO ---\n";
    cTamGiac tg_phong = tg;
    double k;
    while (true){
        k=NhapSoThuc("Nhap he so phong to/thu nho: ");
        if(k>0) break;
        else cout<<"He so phai khac 0. Vui long nhap lai!\n";
    }
    tg_phong.PhongToThuNho(k);
    cout << "Tam giac sau khi bien doi: ";
    tg_phong.XuatTamGiac();
    return 0;
}
