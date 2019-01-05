#include <iostream>
#include "protoypeexercise.h"

using namespace std;

struct Address
{
  string street,city;
  int suite;

  Address(const string &street, const string &city, int suite) :
    street(street),
    city(city),
    suite(suite)
  {}

  Address(const Address &other) :
    street(other.street),
    city(other.city),
    suite(other.suite)
  {}

  ~Address()
  {
    cout << "destroying Address suite number: " << this->suite << endl;
  }

  void printAddress()
  {
    cout << "street= " << street << " city= " << city <<
            " suite= " << suite << endl;
            //" memoryAddressAddressStruct= " << this << endl;
  }
};

struct Contact
{
  std::string name;
  Address *address;

  Contact(const string &name, Address *address) :
    name(name),
    address(address)
  {}

  Contact(const Contact &other) :
    name(other.name),
    address(new Address{ *other.address})
  {}

  ~Contact()
  {
    cout << "destroying Contact: " << this->name << endl;
    delete address;
  }

  void printContact()
  {
    cout << "name= " << name << endl;
    address->printAddress();
  }
};

//int main()
//{
//  Contact john{"John Doe", new Address{"Statenweg 580", "Rotterdam", 3}};
//  //Contact jane{"Jane Smith", Address{"Statenweg 580", "Rotterdam", 2}};
//  Contact jane = john;
//  jane.name = "Jane Smith";
//  jane.address->suite = 2;
//  john.printContact();
//  jane.printContact();
//  return 0;
//}

int main()
{
  //Point pointStart{1,1};
  //Point pointEnd{2,2};
  Line line1(new Point(1,1), new Point(2,2));
  Line line2 = line1.deep_copy();
  line2.end->x = 3;
  line2.end->y = 3;
  line1.printLine();
  line2.printLine();
  return 0;
}





