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


int main()
{
    PhanSo ps;
    nhapPS(ps);
    rutGonPS(ps);
    cout<<"Phan so rut gon la: ";
    xuatPS(ps);
    return 0;
}
