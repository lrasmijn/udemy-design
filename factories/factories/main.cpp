#include <iostream>
#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
  Person(int id, string name):
    id(id),
    name(name)
  {}

};

class PersonFactory
{
public:
  PersonFactory() {};
  Person createPerson(const string &name);

private:
  static int m_currentId;
};

int PersonFactory::m_currentId = 0;

Person PersonFactory::createPerson(const string &name)
{
    Person p = Person(m_currentId, name);
    m_currentId += 1;
    return p;
}

int main()
{
  PersonFactory pf1 = PersonFactory();
  PersonFactory pf2 = PersonFactory();
  Person pLudwig =  pf1.createPerson("Ludwig");
  Person pJan    =  pf1.createPerson("Jan");
  Person pPiet   =  pf2.createPerson("Piet");
  Person pEd     =  pf2.createPerson("Ed");

  return 0;
}

