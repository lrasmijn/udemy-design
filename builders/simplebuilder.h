#ifndef SIMPLEBUILDER
#define SIMPLEBUILDER

#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <iostream>
using namespace std;

struct htmlElement
{
  string m_name, m_text;
  vector<htmlElement> m_elements;
  const size_t indentSize = 2;
  htmlElement(){}
  htmlElement(const string &name, const string &text) :
    m_name(name),
    m_text(text) {}

  string str(int indent = 0) const
  {
    ostringstream oss;
    string i;
    i.append(indentSize*indent, ' ');
    oss << i << "<" << m_name << ">" << endl;
    if(m_text.size() > 0)
      oss << string(indentSize*(indent+1), ' ') << m_text << endl;
    for(const auto &e : m_elements)
      oss << e.str(indent + 1);
    oss << i << "</" << m_name << ">" << endl;
    return oss.str();
  }
};

struct htmlBuilder
{
  htmlElement m_root;
  htmlBuilder(string rootName)
  {
    m_root.m_name = rootName;
  }

  htmlBuilder &addChild(string childName, string childText)
  {
    htmlElement e{childName, childText};
    m_root.m_elements.emplace_back(e);
    cout << "text= " << childText << endl;
    cout << "this->str()=\n " << this->str() << endl;
    return *this;
  }

  string str() const { return m_root.str(); }
};

int simpleBuilder()
{
  cout << "This is simpleBuilder" << endl;
  htmlBuilder builder{"ul"};
  builder.addChild("li", "hello");
  builder.addChild("li","middle");
  builder.addChild("li", "world").addChild("li","world2").addChild("li","world3");
  cout << builder.str() << endl;
  return 0;
}

#endif // SIMPLEBUILDER

