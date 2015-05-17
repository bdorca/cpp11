#ifndef COLUMN_H
#define COLUMN_H
#include "listener.h"
/**
 * @class Column
 * @author Dorka
 * @file Column.h
 * @brief sortable class
 */
class Column
{
    int value; ///< value of the Column
    int coordinate; ///< coordinate in the array
    ColumnListener* listener; ///< Listener
    bool set; ///< whether the coordinate is set
    static int compares; ///< number of compares in the current sort
    static int swaps; ///< number of swaps (operator=) in the current sort

public:
	/**
	 * @brief constructor
	 * sets everything to 0
	 */
    Column()
    {
		value = 0;
		coordinate = 0;
		listener = nullptr;
		set = false;
    }
    /**
     * @brief Constructor
     * @param v value
     * @param c coordinate
     */
    Column(int v, int c);
    /**
     * @brief Destructor
     */
    ~Column();
	/**
	 * @brief operator< 
	 * @param rhs right operand
	 * compares values, increases compares value by 1
	 */	
    bool operator<(Column const& rhs);
	/**
	 * @brief operator> 
	 * @param rhs right operand
	 * compares values, increases compares value by 1
	 */	
    bool operator>(Column const& rhs);
	/**
	 * @brief operator>= 
	 * @param rhs right operand
	 * compares values, increases compares value by 1
	 */	
    bool operator>=(Column const& rhs);
	/**
	 * @brief operator<= 
	 * @param rhs right operand
	 * compares values, increases compares value by 1
	 */	
    bool operator<=(Column const& rhs);
	/**
	 * @brief operator=
	 * @param other 
	 * sets the value to other.value and coordinate if it's not set yet
	 */	
    Column& operator=(Column const& other);
	/**
	 * @brief returns value
	 * @return value
	 */
    int getVaule()
    {
		return value;
    }
	/**
	 * @brief adds listener
	 * @param l
	 */
    void addListener(ColumnListener* l)
    {
		listener = l;
    }
	/**
	 * @brief sets compares value
	 * @param c compares
	 */
    static void setCompares(int c)
    {
		compares = c;
    }
	/**
	 * @brief return number of compares
	 * @return 
	 */
    static int getCompares()
    {
		return compares;
    }
	/**
	 * @brief sets swaps to c
	 * @param c
	 */
	static void setSwaps(int c){
		swaps = c;
	}
	/**
	 * @brief return number of swaps
	 * @return swaps/2
	 * 1 swap = 2 operator= calls
	 */
	static int getSwaps(){
		return swaps/2;
	}
};

#endif // COLUMN_H
