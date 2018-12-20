#include <string>
#include <iostream>
#include <vector>
#include <sstream>

struct classElement
{
  std::string m_varType, m_varName;
  std::vector<classElement> m_elements;
  classElement() {}
  classElement(std::string varType, std::string varName):
    m_varType(varType),
    m_varName(varName)
  {}

  std::string printElements() const
  {
  std::string i(2,' ');
  std::ostringstream oss;
  for (auto &e : m_elements)
  {
    oss << i << e.m_varType << " " << e.m_varName << ";" << std::endl;
  }
  return oss.str();
  }
};

struct classBuilder
{
  classElement m_root;
  std::string m_className;
  classBuilder(std::string rootName):
    m_root(),
    m_className(rootName)
  {}

  classBuilder &addElement(std::string varType, std::string varName)
  {
    classElement e(varType, varName);
    m_root.m_elements.emplace_back(e);
    return *this;
  }

  std::string printTotalClass()
  {
    std::ostringstream oss;
    oss << m_className << std::endl;
    oss << "{" << std::endl;
    oss << m_root.printElements();
    oss << "}" << std::endl;
    return oss.str();
  }
};

int main()
{
  std::cout << __cplusplus << std::endl;
  classBuilder class1("Person");
  class1.addElement("string", "name").addElement("int", "age");
  std::cout << class1.printTotalClass();

  return 0;
}

