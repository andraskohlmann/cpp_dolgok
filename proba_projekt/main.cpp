#include <iostream>

using namespace std;


 //double& operator[](int)


int main() {
    Tomb t(30);
    std::cout << t[20]; //index op.
    t[22] = 10.2; // referenci�val t�r vissza az index [] oer�tor
    t.atmeretez(50); // dinamikus �tm�retez�s
    Tomb masolat(t), harmadik; //copy constructor
    harmadik = t; // operator=
}

