#include "builderexercise.h"
#include <string>
#include <vector>
#include <sstream>

struct classElement
{
  std::string m_className;
  std::string m_varType, m_varName;
  std::vector<classElement> m_elements;
  const size_t indent_size = 2;

  classElement() {}
  classElement(const std::string &varType, const std::string &varName) :
    m_varType(varType),
    m_varName(varName)
    {}
  std::string printElements() const
  {
    std::ostringstream oss;
    std::string i(indent_size, ' ');
    for (const auto &e : m_elements)
    {
      oss << i << e.m_varType << "  " << e.m_varName << ";" << std::endl;
    }
    return oss.str();
  }
};

struct classBuilder
{
  classElement m_root;

  classBuilder(std::string root_name)
  {
    m_root.m_className = root_name;
  }

  void addChild(std::string childVarType, std::string childVarName)
  {
    classElement e{childVarType, childVarName};
    m_root.m_elements.emplace_back(e);
  }

  std::string printElements() const
  {
    return m_root.printElements();
  }

};

builderExercise::builderExercise()
{

}
