#ifndef MYSTRING_H
#define MYSTRING_H

/** @brief StringValue osztály
  *
  * String tárolására és referencia számlálásra
  */

class StringValue
{

    int counter; // számláló
    char *data; //a string maga

public:

    /** @brief Konstruktor
      * @param str a kívánt string
      * char*-ból csinál StringValue-t
      */
    StringValue(const char *str);

    /** @brief Default Konstruktor
      */
    StringValue() {
        counter=0;
    }

    /** @brief Másoló Konstruktor
      * @param other a kívánt string-et tartalmazó StringValue
      * StringValue-ból csinál StringValue-t
      */
    StringValue(StringValue const& other);

    /** @brief Destruktor
      */
    ~StringValue();

    /** @brief számláló növelése
      * @return új érték
      */
    int incrCounter() {
        return ++counter;
    }

    /** @brief számláló csökkentése
      * @return új érték
      */
    int decrCounter() {
        return --counter;
    }

    /** @brief += operátor
      * @return A baloldali (összefűzött) StrinValue referenciája
      * @param rhs A jobboldalra kerülő részstring
      */
    StringValue& operator+=(const char* rhs);

    /** @brief + operátor
      * @return Az összefűzött StrinValue
      * @param rhs A jobboldalra kerülő részstring
      */
    StringValue operator+(const char* rhs);

    /** @brief += operátor
      * @return A baloldali (összefűzött) StrinValue referenciája
      * @param rhs A jobboldalra kerülő részstring
      */
    StringValue& operator+=(StringValue const& rhs);

    /** @brief + operátor
      * @return Az összefűzött StrinValue pointere
      * @param rhs A jobboldalra kerülő részstring
      */
    StringValue* operator+(StringValue const& rhs);

    /** @brief hossz függvény
      * @return a tárolt string hossza
      */
    int length();

    /** @brief ondexelő operátor
      * @param i a kívánt index
      * @return indexedik karakter
      */
    char operator[](int i);

    /** @brief számláló érték
      * @return számláló értéke
      */
    int getCounter() {
        return counter;
    }
    /** @brief streamre író operátor
    * kíirja a stringet és a számláló értékét
    */
    friend std::ostream &operator<<(std::ostream &stream, StringValue &sv);
};

/**
* Saját string osztály
*/
class MyString
{

    StringValue *stringValue; // string pointer

    /** @brief string eltávolító függvény
    */
    void removeSV();
public:

    /** @brief Default Konstruktor
    * üres striget inicializál
    */
    MyString();

    /** @brief Kostruktor
    * @param str kívánt string
    */
    MyString(char const *str);

    /** @brief Másoló Kostruktor
    * @param other kívánt string
    */
    MyString(MyString const &other);

    /** @brief Move Kostruktor
    * @param other kívánt string
    */
    MyString(MyString&& other);

    /** @brief értékadó operátor
    * @param other kívánt string
    * @return a baloldali string referenciája
    */
    MyString& operator=(MyString const &other);

    /** @brief move értékadó operátor
    * @param other kívánt string
    * @return a baloldali string referenciája
    */
    MyString& operator=(MyString&& other);

    /** @brief += operátor
    * @param rhs jobboldali részstring
    * @return a baloldali összefűzött string referenciája
    */
    MyString& operator+=(MyString const& rhs);

    /** @brief + operátor
    * @param rhs jobboldali részstring
    * @return az összefűzött string
    */
    MyString operator+(MyString const& rhs);

    /** @brief += operátor
    * @param rhs jobboldali részstring
    * @return a baloldali összefűzött string referenciája
    */
    MyString& operator+=(const char* rhs);

    /** @brief + operátor
    * @param rhs jobboldali részstring
    * @return az összefűzött string
    */
    MyString operator+(const char* rhs);

    /** @brief indexelő operátor
    * @param i kívánt inedx
    * @return az i. karakter
    */
    char operator[](int i);

    /** @brief hossz
    * @return a tárolt string hossza
    */
    int length();
    /** @brief Destruktor
    */
    ~MyString();
    /** @brief stremre író operátor
    * kiírja a StringValue-t
    */
    friend std::ostream &operator<<(std::ostream &stream, MyString &ms);
    /** @brief streamről olvasó operátor
    * beolvas egy max 100 hosszúságú stringet
    */
    friend std::istream& operator>>(std::istream &stream, MyString &ms);
};


#endif
