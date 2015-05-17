//Nézd meg az 5. előadás anyagában, a mértékegységes feladatnál a Joule/Newton*méter
//kiírással kapcsolatos részeket! Ezek után...
//
//a) Írj bináris szám kiíró I/O manipulátort! A használata legyen az alábbi:
//
//std::cout << bin << 240 << std::endl;        /* 11110000 */
//
//Vajon mi lehet itt a bin típusa?
//
//b) Írj akárhányas számrendszerben kiíró I/O manipulátort!
//
//std::cout << base(2) << 240;    /* 11110000 */
//std::cout << base(16) << 240;   /* F0 */
//
//Melyik az első részkifejezés, amit ki kell értékelnie a fordítónak? Indulj ki ebből!



#include <iostream>
#include <string>

class NumberSystem
{
		int toNS;
		std::ostream *os;
	public:

		NumberSystem( int tns): toNS(tns) {}

		std::ostream & operator<<(int s)const {
			std::string result="";
			while(s>0) {
				char c = (s%toNS)+'0';
				if(c>'9') {
					c+=7;
				}
				result = c + result;
				s = s/toNS;
			}
			(*os)<<result;
			return *os;
		}

		friend NumberSystem operator<< (std::ostream &os, NumberSystem const &b );
};

NumberSystem operator<< (std::ostream &os, NumberSystem const &b )
{
	NumberSystem nb(b);
	nb.os=&os;
	return nb;
}

NumberSystem base(int n)
{
	return NumberSystem {n};
}

int main()
{
	NumberSystem bin(2);
	std::cout << bin << 16 << std::endl;        /* 11110000 */
	std::cout << base(16) << 241 << std::endl;        /* 11110000 */
	std::cout<< base(8)<<123456<<" "<<base(2)<<7<<std::endl;

	return 0;
}
