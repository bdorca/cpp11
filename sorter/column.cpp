#include "Column.h"
#include <iostream>
Column::Column(int v, int c)
{
    value = v;
    coordinate = c;
    listener = nullptr;
}

Column::~Column()
{
}

bool Column::operator<(Column const& rhs)
{
    //std::cout << coordinate << ":" << value << "<" << rhs.coordinate << ":" << rhs.value << std::endl;
    if(listener) {
		listener->onCompare(coordinate, rhs.coordinate,false);
    }
	compares++;
    return value < rhs.value;
}

bool Column::operator>(Column const& rhs)
{
    //std::cout << value << ">" << rhs.value << std::endl;
    if(listener) {
		listener->onCompare(coordinate, rhs.coordinate,false);
    }
	compares++;
    return value > rhs.value;
}

Column& Column::operator=(Column const& other)
{
    //std::cout <<coordinate<<" : "<< value << "="<<other.coordinate<<" : " << other.value << std::endl;
	value = other.value;
    if(!set){
		set=true;
		coordinate=other.coordinate;
	}else{
		swaps++;
	}
    if(listener!=nullptr) {
		listener->onCompare(other.coordinate, coordinate, true);
    }
    return *this;
}

bool Column::operator>=(Column const& rhs)
{
	//std::cout << value << ">=" << rhs.value << std::endl;
    if(listener) {
		listener->onCompare(coordinate, rhs.coordinate,false);
    }
	compares++;
    return value >= rhs.value;
}
bool Column::operator<=(Column const& rhs)
{
    //std::cout << coordinate << ":" << value << "<=" << rhs.coordinate << ":" << rhs.value << std::endl;
    if(listener) {
		listener->onCompare(coordinate, rhs.coordinate,false);
    }
	compares++;
    return value <= rhs.value;
}

int Column::compares=0;
int Column::swaps=0;