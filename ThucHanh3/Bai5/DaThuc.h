#ifndef DATHUC_H_INCLUDED
#define DATHUC_H_INCLUDED
#include "DonThuc.h"
class cDaThuc
{
private:
    int n;
    cDonThuc* mangDonThuc;
public:
    cDaThuc(int bac = 0);
    ~cDaThuc();
    cDaThuc(const cDaThuc& khac);
    cDaThuc& operator=(const cDaThuc& khac);

    void NhapDaThuc();
    void XuatDaThuc() const;
    double TinhGiaTri(double x) const;

    cDaThuc Cong(const cDaThuc& khac) const;
    cDaThuc Tru(const cDaThuc& khac) const;
};


#endif // DATHUC_H_INCLUDED
