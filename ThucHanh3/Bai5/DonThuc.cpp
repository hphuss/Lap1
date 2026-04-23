#include <iostream>
#include "DonThuc.h"
#include <cmath>

cDonThuc::cDonThuc(double h, int m) : heSo(h), soMu(m) {}

void cDonThuc::SetHeSo(double h) { heSo = h; }
void cDonThuc::SetSoMu(int m) { soMu = m; }

double cDonThuc::GetHeSo() const { return heSo; }
int cDonThuc::GetSoMu() const { return soMu; }

double cDonThuc::TinhGiaTri(double x) const {
    return heSo * std::pow(x, soMu);
}
