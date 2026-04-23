#include <iostream>
#include "DaThuc.h"

using namespace std;

int main() {
    cout << "--- CHUONG TRINH XU LY DA THUC ---\n\n";

    // 1. Nhap da thuc A
    cout << "NHAP DA THUC P(x)\n";
    cDaThuc P;
    P.NhapDaThuc();

    // 2. Nhap da thuc B
    cout << "\nNHAP DA THUC Q(x)\n";
    cDaThuc Q;
    Q.NhapDaThuc();

    // 3. Xuat 2 da thuc
    cout << "\n--- THONG TIN DA THUC ---\n";
    cout << "P(x) = "; P.XuatDaThuc(); cout << "\n";
    cout << "Q(x) = "; Q.XuatDaThuc(); cout << "\n";

    // 4. Cong, tru da thuc
    cDaThuc Tong = P.Cong(Q);
    cDaThuc Hieu = P.Tru(Q);

    cout << "\n--- PHEP TOAN ---\n";
    cout << "P(x) + Q(x) = "; Tong.XuatDaThuc(); cout << "\n";
    cout << "P(x) - Q(x) = "; Hieu.XuatDaThuc(); cout << "\n";

    // 5. Tinh gia tri
    cout << "\n--- TINH GIA TRI ---\n";
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;

    cout << "P(" << x << ") = " << P.TinhGiaTri(x) << "\n";
    cout << "Q(" << x << ") = " << Q.TinhGiaTri(x) << "\n";

    return 0;
}
