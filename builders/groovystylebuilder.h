#ifndef GROOVYSTYLEBUILDER
#define GROOVYSTYLEBUILDER

#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <iostream>
using namespace std;

struct tag
{
  string name, text;
  vector<tag> children;
  vector<pair<string, string>> attributes;
  friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
  {
    os << "<" << tag.name;

    for (const auto& att : tag.attributes)
      os << " " << att.first << "=\"" << att.second << "\"";

    if (tag.children.size() == 0 && tag.text.length() == 0)
      {
        os << "/>" << std::endl;
      }
    else
      {
        os << ">" << std::endl;

        if (tag.text.length())
          os << tag.text << std::endl;

        for (const auto& child : tag.children)
          os << child;

        os << "</" << tag.name << ">" << std::endl;
      }

    return os;
  }

};

#endif // GROOVYSTYLEBUILDER

