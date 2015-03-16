#include <iostream>

using namespace std;

 class Tomb {
    double *items;
public:
    Tomb() {items = new double[60];}
    Tomb (int _size) {items = new double[_size];}
    void atmeretez (int) {;}
    double& operator[](const int);
 };

int main() {
    Tomb t(30);
//    std::cout << t[20]; //index op.
//    t[22] = 10.2; // referenciával tér vissza az index [] oerátor
//    t.atmeretez(50); // dinamikus átméretezés
//    Tomb masolat(t), harmadik; //copy constructor
//    harmadik = t; // operator=
}
