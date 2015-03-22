#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


class Complex {
    double re;
    double im;
public:
    Complex(double re = 0, double im = 0) : re(re), im(im) {

    }

    Complex& operator=(const Complex& be) {
        re = be.re;
        im = be.im;
    }

    bool operator>(const Complex& c) const {
        return re > c.re;
    }

    bool operator<(const Complex& c) const {
        return re < c.re;
    }

    operator double() {
        return re;
    }

    friend ostream& operator<<(ostream& os, const Complex& c);

};

ostream& operator<<(ostream& os, const Complex& c) {
    os << "re: " << c.re << " im: " << c.im;
    return os;
}

template<class T>
bool hasonlit(const T& egyik, const T& masik) {
    return egyik > masik;
}

template<class T>
T* Sort(T* c, unsigned s, bool (*has)(const T&, const T&)) {
    T* ret = new T[s];

    for(unsigned i = 0; i < s; i++) {
        ret[i] = c[i];
    }

    for(unsigned i = 0; i<s; i++)
    for(unsigned j = 0; j<s-1; j++) {
        if(has(ret[j],ret[j+1])) {
            T tmp = ret[j+1];
            ret[j+1] = ret[j];
            ret[j]=tmp;
        }
    }

    return ret;
}

template<class T>
class Tomb {
public:
    T *items;
    unsigned s;
    //Tomb() {items = new double[40];/* We like to be undefined */}

    Tomb (int _size = 0) : s(_size) {
        items = new T[_size];

        for (int i = 0; i < _size; ++i)
            items [i] =(double) (rand() % 50);
    }

    void atmeretez (unsigned int _new_size) {
        T *temporary = new T[_new_size];
        unsigned int i = 0;

        while (i < _new_size){
            if ( i < s )
              temporary [i]= items[i];
            else
              temporary [i] = temporary[i-1] + 1;
            i++;
        }
        s = _new_size;
        delete[] items;
        items = temporary;

      return;
    }

    T& operator[](const int index) {
    // ide egy ellenorzes dukalna azert (throw -val)
        T& item_ref=items[index];
      return item_ref;
    }

    Tomb& operator= (const Tomb& src)   {
        this->atmeretez(src.s);

        for (unsigned int i = 0; i < src.s; ++i)
            this->items[i] = src.items[i];

        return *this;
    }

    /* Amugy mukszik az alapertelmezett copy constructor is */
    Tomb(const Tomb& t): s(t.s) {
        items = new T[s];

        for(unsigned i = 0; i < s; i++) {
            this->items[i] = t.items[i];
        }
    }

    ~Tomb() {delete[] items;}

 };

int main() {
    srand(time(NULL));

    Tomb<Complex> t(30);
//    std::cout << t[20] << "\n"; //index op.

    t[22] = 10.2; // referenciával tér vissza az index [] oerátor

    t.atmeretez(50); // dinamikus átméretezés
//
//    for(unsigned i = 0; i < t.s; i++)
//        std::cout << t[i] << "\n";

    Tomb<Complex> masolat(t), harmadik; //copy constructor
//
//    std::cout << std::endl << masolat[30] << "\n\n";
//
//    cout << "Harmadik:\n";

    harmadik = t; // operator=
//
//    for(unsigned i = 0; i < harmadik.s; i++)
//        std::cout << harmadik[i] << "\n";

//    std::cout << harmadik[20] << "\n";

    Complex *c = Sort<Complex>(t.items, t.s, hasonlit<Complex>);

    for(unsigned i = 0; i < t.s; i++)
        cout << c[i] << "\n";

    delete[] c;
}
