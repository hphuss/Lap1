#ifndef DIEM_H_INCLUDED
#define DIEM_H_INCLUDED
class cDiem
{
private:
    double x,y;
public:
    cDiem(double _x=0, double _y=0);
    void NhapDiem();
    void XuatDiem() const;

    double TinhKhoangCach(const cDiem& khac) const;
    void TinhTien(double dx, double dy);
    void Quay(double goc);
    void PhongToThuNho(double k);
};


#endif // DIEM_H_INCLUDED
