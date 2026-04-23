#include <iostream>
#include "Diem.h"
#include <cmath>
#include <limits>

using namespace std;

cDiem::cDiem(double _x, double _y):x(_x), y(_y){}

void cDiem::NhapDiem()
{
    while (true){
        cout<<"Nhap x: ";
        if(cin>>x) break;
        else{
            cout<<"Vui long chi nhap so. Hay nhap lai\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    while (true){
        cout<<"Nhap y: ";
        if(cin>>y) break;
        else{
            cout<<"Vui long chi nhap so. Hay nhap lai\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
void cDiem::XuatDiem() const
{
    cout<<"("<<x<<", "<<y<<")";
}
double cDiem::TinhKhoangCach(const cDiem& khac) const
{
    return sqrt(pow((x-khac.x),2)+pow((y-khac.y),2));
}
void cDiem::TinhTien(double dx, double dy)
{
    x += dx;
    y += dy;
}
void cDiem::Quay(double goc)
{
    double x_moi=x*cos(goc)-y*sin(goc);
    double y_moi=x*sin(goc)+y*cos(goc);
    x = x_moi;
    y = y_moi;
}
void cDiem::PhongToThuNho(double k)
{
    x *=k;
    y *=k;
}
