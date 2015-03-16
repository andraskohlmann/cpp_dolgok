#include <iostream>

using namespace std;

 class Tomb {
    double *items;
public:
    Tomb() {items = new double[60];}

    Tomb (int _size) {
        items = new double[_size];

        for (int i = 0; i < _size; ++i)
            items [i] = (double)i;
    }

//    void atmeretez (int) {;}

    double& operator[](const int index) {
    // ide egy ellenorzes dukalna azert (throw -val)
        double& item_ref=items[index];
      return item_ref;
    }
 };

int main() {
    Tomb t(30);
    std::cout << t[20]; //index op.
    t[22] = 10.2; // referenciával tér vissza az index [] oerátor
//    t.atmeretez(50); // dinamikus átméretezés
//    Tomb masolat(t), harmadik; //copy constructor
//    harmadik = t; // operator=
}
