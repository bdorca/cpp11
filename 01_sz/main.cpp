#include <iostream>

using namespace std;

class Tort {
private:
    int _szaml, _nev;
public:
    Tort() {
    }

    Tort(int n, int d) { //ea
        int a = n, b = d, t;
        while (b != 0)
            t = a % b, a = b, b = t;
        _szaml = n / a;
        _nev = d / a;
    }

    int szaml() {
        return _szaml;
    }

    int nev() {
        return _nev;
    }

    Tort& operator+=(Tort const& rhs);

    Tort& operator-=(Tort const& rhs);

    Tort& operator*=(Tort const& rhs);

    Tort& operator/=(Tort const& rhs);

    operator double() {
        return (double) _szaml / (double) _nev;
    }

};

Tort operator-(Tort t) {
    return Tort(-t.szaml(), t.nev());
}

Tort operator+(Tort t) {                 //reciprok kepzesre
    return Tort(t.nev(), t.szaml());
}

Tort& Tort::operator+=(Tort const& rhs) {
    *this = Tort(this->_szaml * rhs._nev + rhs._szaml * this->_nev,
            this->_nev * rhs._nev);
    return *this;
}

Tort& Tort::operator-=(Tort const& rhs) {
    *this += (-rhs);
    return *this;
}

Tort& Tort::operator*=(Tort const& rhs) {
    *this = Tort(this->_szaml * rhs._szaml, this->_nev * rhs._nev);
    return *this;
}

Tort& Tort::operator/=(Tort const& rhs) {
    *this *= (+rhs);
    return *this;
}

Tort operator+(Tort t1, Tort const& t2) {
    t1 += t2;
    return t1;
}

Tort operator-(Tort t1, Tort const& t2) {
    t1 -= t2;
    return t1;
}

Tort operator*(Tort t1, Tort const& t2) {
    t1 *= t2;
    return t1;
}

Tort operator/(Tort t1, Tort const& t2) {
    t1 /= t2;
    return t1;
}

std::istream& operator>>(std::istream& stream, Tort& d) {
    int a, b;
    stream >> a >> b;
    d = Tort(a, b);
    return stream;
}

std::ostream& operator<<(std::ostream& os, Tort r) {
    os << r.szaml() << '/' << r.nev();
    return os;
}

int main() {
    Tort t1 = Tort(3, 2);
    Tort t2 = Tort(3, 4);
    Tort t3 = t1 - t2;
    Tort t5 = Tort(1 , 1);
    t5 += t3 / t2;
    cout << t1 << " " << t2 << " " << t3 << endl;
    cout << (double) t3 << endl;
    cout<<"t5 "<<t5<<endl;

    return 0;
}