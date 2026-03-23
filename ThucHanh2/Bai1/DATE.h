#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
class Date {
private:
    int iNgay, iThang, iNam;

    bool LaNamNhuan(int n);
    int TimNgayTrongThang(int t, int n);
    int NhapSoNguyen();
public:
    void Nhap();
    void Xuat();
    Date NgayKeTiep();

};


#endif // DATE_H_INCLUDED
