#include <iostream>
#include <limits>

using namespace std;
struct PhanSo
{
    int tu;
    int mau;
};
int nhapSoNguyen() {
    int n;
    while (true) {
        cin >> n;
        if (cin.fail()) { // Nếu nhập chữ hoặc ký tự đặc biệt
            cin.clear(); // Xóa trạng thái lỗi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ nhớ đệm
            cout << "Loi! Vui long chi nhap so nguyen: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa ký tự thừa còn lại
            return n;
        }
    }
}
int timUCLN(int a, int b)
{
    if(b==0) return a;
    return timUCLN(b, a%b);
}
void nhapPS(PhanSo &ps)
{
    cout << "Tu so: "; ps.tu=nhapSoNguyen();
    do {
        cout << "Mau so: "; ps.mau=nhapSoNguyen();
        if (ps.mau == 0) cout << "Mau so phai khac 0.Hay nhap lai!\n";
    } while (ps.mau == 0);
}
void xuatPS(PhanSo ps)
{
    if (ps.mau == 1) cout << ps.tu;
    else if (ps.mau == -1) cout << -ps.tu;
    else if (ps.mau < 0) cout << -ps.tu << "/" << -ps.mau;
    else cout << ps.tu << "/" << ps.mau;
}
void rutGonPS(PhanSo &ps)
{
    int ucln = timUCLN(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
}
PhanSo timMaxPS(PhanSo &ps1, PhanSo &ps2)
{
    float gt1 = (float) ps1.tu/ps1.mau;
    float gt2 = (float) ps2.tu/ps2.mau;
    return (gt1>gt2)?ps1:ps2;
}


int main()
{
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu 1:\n"; nhapPS(ps1);
    cout << "Nhap phan so thu 2:\n"; nhapPS(ps2);

    PhanSo maxPS = timMaxPS(ps1, ps2);
    rutGonPS(maxPS);
    cout << "Phan so lon nhat la: "; xuatPS(maxPS); cout << "\n";
    return 0;
}
