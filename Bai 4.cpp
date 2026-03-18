#include <iostream>

using namespace std;
struct Ngay {
    int d, m, y;
};
void nhapNgay(Ngay &ng) {
    cout << "Nhap ngay, thang, nam (cach nhau boi khoang trang): ";
    cin >> ng.d >> ng.m >> ng.y;
}

void xuatNgay(Ngay ng) {
    cout << ng.d << "/" << ng.m << "/" << ng.y;
}

bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return laNamNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}

Ngay timNgayKeTiep(Ngay ht) {
    Ngay kt = ht;
    kt.d++;
    if (kt.d > soNgayTrongThang(ht.m, ht.y)) {
        kt.d = 1;
        kt.m++;
        if (kt.m > 12) {
            kt.m = 1;
            kt.y++;
        }
    }
    return kt;
}
int main()
{
    Ngay homNay;
    nhapNgay(homNay);
    Ngay ngayMai = timNgayKeTiep(homNay);
    cout << "Ngay ke tiep la: "; xuatNgay(ngayMai); cout << "\n";
}
