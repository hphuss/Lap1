#include "DaThuc.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

cDaThuc::cDaThuc(int bac) {
    n = (bac >= 0) ? bac : 0;
    mangDonThuc = new cDonThuc[n + 1];
    for (int i = 0; i <= n; i++) {
        mangDonThuc[i].SetSoMu(i); // Gan san so mu cho tung phan tu
        mangDonThuc[i].SetHeSo(0); // Mac dinh he so = 0
    }
}

cDaThuc::~cDaThuc() {
    if (mangDonThuc != nullptr) {
        delete[] mangDonThuc;
    }
}

cDaThuc::cDaThuc(const cDaThuc& khac) {
    n = khac.n;
    mangDonThuc = new cDonThuc[n + 1];
    for (int i = 0; i <= n; i++) {
        mangDonThuc[i] = khac.mangDonThuc[i];
    }
}

cDaThuc& cDaThuc::operator=(const cDaThuc& khac) {
    if (this == &khac) return *this;

    if (mangDonThuc != nullptr) delete[] mangDonThuc;

    n = khac.n;
    mangDonThuc = new cDonThuc[n + 1];
    for (int i = 0; i <= n; i++) {
        mangDonThuc[i] = khac.mangDonThuc[i];
    }
    return *this;
}

void cDaThuc::NhapDaThuc()
{
    int soLuong;
    cout << "Nhap so luong don thuc (so hang) ban muon nhap: ";
    while (!(cin >> soLuong) || soLuong <= 0) {
        cout << "So luong phai la so nguyen duong. Vui long nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Tao mang tam de hung du lieu nguoi dung nhap vao lon xon
    double* tempHeSo = new double[soLuong];
    int* tempSoMu = new int[soLuong];
    int maxSoMu = 0;

    for (int i = 0; i < soLuong; i++) {
        cout << "Nhap don thuc thu " << i + 1 << ":\n";
        cout << "  He so: ";
        cin >> tempHeSo[i];

        cout << "  So mu: ";
        cin >> tempSoMu[i];

        // Bat loi de dam bao so mu khong duoc am
        while (tempSoMu[i] < 0) {
            cout << " So mu khong duoc am. Nhap lai so mu: ";
            cin >> tempSoMu[i];
        }

        // Tim so mu lon nhat de xac dinh bac cua da thuc
        if (tempSoMu[i] > maxSoMu) {
            maxSoMu = tempSoMu[i];
        }
    }

    // Cap nhat bac cua da thuc
    n = maxSoMu;

    // Don dep mang cu (neu co) va cap phat mang moi theo maxSoMu
    if (mangDonThuc != nullptr) delete[] mangDonThuc;
    mangDonThuc = new cDonThuc[n + 1];

    // Khoi tao toan bo he so bang 0 ban dau
    for (int i = 0; i <= n; i++) {
        mangDonThuc[i].SetSoMu(i);
        mangDonThuc[i].SetHeSo(0);
    }

    // Dua cac don thuc tam thoi vao dung vi tri chi so.
    // Neu co 2 don thuc cung so mu, tu dong cong don he so cua chung lai.
    for (int i = 0; i < soLuong; i++) {
        int mu = tempSoMu[i];
        double heSoHienTai = mangDonThuc[mu].GetHeSo();
        mangDonThuc[mu].SetHeSo(heSoHienTai + tempHeSo[i]);
    }

    // Giai phong bo nho tam
    delete[] tempHeSo;
    delete[] tempSoMu;
}

void cDaThuc::XuatDaThuc() const
{
    bool laDaThucKhong = true;

    for (int i = n; i >= 0; i--) {
        double heSo = mangDonThuc[i].GetHeSo();
        if (heSo == 0) continue; // Bo qua cac don thuc co he so 0

        // In dau (Cong hoac Tru)
        if (laDaThucKhong) {
            if (heSo < 0) cout << "-"; // Term dau tien neu am thi in dau -
            laDaThucKhong = false;
        } else {
            if (heSo > 0) cout << " + ";
            else cout << " - ";
        }

        double heSoTuyetDoi = abs(heSo);

        // In he so va an x
        if (i == 0) {
            // Bac 0 thi in mat chu so
            cout << heSoTuyetDoi;
        } else {
            // Khong in so 1 neu no di kem voi x (vd: in x thay vi 1x)
            if (heSoTuyetDoi != 1) cout << heSoTuyetDoi;
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
    }

    if (laDaThucKhong) cout << "0"; // Neu toan he so 0 thi in ra so 0
}

double cDaThuc::TinhGiaTri(double x) const {
    double tong = 0;
    for (int i = 0; i <= n; i++) {
        tong += mangDonThuc[i].TinhGiaTri(x);
    }
    return tong;
}
// === PHEP TOAN ===
cDaThuc cDaThuc::Cong(const cDaThuc& khac) const {
    int maxBac = max(n, khac.n);
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSoA = (i <= n) ? mangDonThuc[i].GetHeSo() : 0;
        double heSoB = (i <= khac.n) ? khac.mangDonThuc[i].GetHeSo() : 0;
        ketQua.mangDonThuc[i].SetHeSo(heSoA + heSoB);
    }
    return ketQua;
}

cDaThuc cDaThuc::Tru(const cDaThuc& khac) const {
    int maxBac = max(n, khac.n);
    cDaThuc ketQua(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double heSoA = (i <= n) ? mangDonThuc[i].GetHeSo() : 0;
        double heSoB = (i <= khac.n) ? khac.mangDonThuc[i].GetHeSo() : 0;
        ketQua.mangDonThuc[i].SetHeSo(heSoA - heSoB);
    }
    return ketQua;
}
