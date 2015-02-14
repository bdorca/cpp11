#include <iostream>

using namespace std;

class Tort {
private:
    int szaml_, nev_;
public:
    Tort() {
    }

    Tort(int n, int d) { //ea
        int a = n, b = d, t;
        while (b != 0)
            t = a % b, a = b, b = t;
        szaml_ = n / a;
        nev_ = d / a;
    }

    int szaml() {
        return szaml_;
    }

    int nev() {
        return nev_;
    }


    operator double() {
        return (double) szaml_ / (double) nev_;
    }

};

Tort operator-(Tort t) {
    return Tort(-t.szaml(), t.nev());
}

Tort operator+(Tort t) {
    return t;
}

Tort& operator+=(Tort& lhs, Tort rhs) {
    lhs = Tort(lhs.szaml() * rhs.nev() + rhs.szaml() * lhs.nev(),
            lhs.nev() * rhs.nev());
    return lhs;
}

Tort& operator-=(Tort& lhs, Tort rhs) {
    lhs += (-rhs);
    return lhs;
}

Tort& operator*=(Tort& lhs, Tort rhs) {
    lhs = Tort(lhs.szaml() * rhs.szaml(), lhs.nev() * rhs.nev());
    return lhs;
}

Tort& operator/=(Tort& lhs, Tort rhs) {
    Tort t = Tort(rhs.nev(), rhs.szaml());
    lhs *= t;
    return lhs;
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
    Tort t5 = t1 / t2;
    cout << t1 << " " << t2 << " " << t3 << endl;
    cout << (double) t3 << endl;
    cout << "t5 " << t5 << endl;

    return 0;
}