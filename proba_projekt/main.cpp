#include <iostream>

using namespace std;

 class Tomb {
    double *items;
public:
    Tomb() {items = new double[40];/* We like to be undefined */}

    Tomb (int _size) {
        items = new double[_size];

        for (int i = 0; i < _size; ++i)
            items [i] = (double)i;
    }

    void atmeretez (unsigned int _new_size) {
        double *temporary = new double[_new_size];
        unsigned int i = 0;

        while (i++ < _new_size){
            if ( i < sizeof (items) )
              temporary [i]= items[i];
            else
              temporary [i] = temporary [i-1] + 1;
        }

        delete[] items;
        items = temporary;

      return;
    }

    double& operator[](const int index) {
    // ide egy ellenorzes dukalna azert (throw -val)
        double& item_ref=items[index];
      return item_ref;
    }
/*
    Tomb& operator= (const Tomb& src)   {
        this->atmeretez(sizeof(src.items));

        for (unsigned int i = 0; i < sizeof (src.items); ++i)
            this->items[i] = src.items[i];

        return *this;
    }
*/
    /* Amugy mukszik az alapertelmezett copy constructor is */
    Tomb (const Tomb& t): items (t.items) {}

    ~Tomb() {delete[] items;}

 };

int main() {
    Tomb t(30);
    std::cout << t[20] << "\n"; //index op.

    t[22] = 10.2; // referenciával tér vissza az index [] oerátor

    t.atmeretez(50); // dinamikus átméretezés

    std::cout << t[30] << "\n";

    Tomb masolat(t), harmadik; //copy constructor

    std::cout << masolat[30] << "\n";

//    harmadik = t; // operator=
//    std::cout << harmadik[70] << "\n";
}
