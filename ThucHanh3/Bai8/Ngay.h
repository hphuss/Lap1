#ifndef NGAY_H_INCLUDED
#define NGAY_H_INCLUDED

class cNgay
{
private:
    int ngay, thang, nam;

    bool LaNamNhuan(int n) const;
    int TimNgayTrongThang(int t, int n) const;
    int NhapSoNguyen();

public:
    cNgay(int n = 1, int t = 1, int nm = 2000);

    void Nhap();
    void Xuat() const;
    bool LonTuoiHon(const cNgay& khac) const;
};
#endif // NGAY_H_INCLUDED
