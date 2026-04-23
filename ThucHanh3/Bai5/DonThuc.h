#ifndef DONTHUC_H_INCLUDED
#define DONTHUC_H_INCLUDED
class cDonThuc
{
private:
    double heSo;
    int soMu;
public:
    cDonThuc(double h=0.0, int m=0);

    void SetHeSo(double h);
    void SetSoMu(int m);

    double GetHeSo() const;
    int GetSoMu() const;

    double TinhGiaTri(double x) const;
};


#endif // DONTHUC_H_INCLUDED
