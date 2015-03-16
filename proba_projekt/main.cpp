#include <iostream>

using namespace std;

 class Tomb {
    double *items;
    int std_size;
public:
    Tomb() {std_size = 40; items = new double[std_size];/* We like to be undefined */}

    Tomb (int _size) {
        items = new double[_size];

        for (int i = 0; i < _size; ++i)
            items [i] = (double)i;
    }

    void atmeretez (int _new_size) {
        double *temporary = new double[_new_size];
        int i = -1;

        while (++i < _new_size){
            if ( i < sizeof (items) )
              temporary [i]= items[i];
            else
              temporary [i] = temporary [i-1] + 1;
        }

        delete[] items;
        items = temporary;
    }

    double& operator[](const int index) {
    // ide egy ellenorzes dukalna azert (throw -val)
        double& item_ref=items[index];
      return item_ref;
    }
 };

int main() {
    Tomb t(30);
    std::cout << t[20] << "\n"; //index op.
    t[22] = 10.2; // referenciával tér vissza az index [] oerátor
    t.atmeretez(50); // dinamikus átméretezés
    std::cout << t[30] << "\n"; //index op.
    Tomb masolat(t), harmadik; //copy constructor
//    harmadik = t; // operator=
}
