#ifndef SINGLERESPONSIBILITY
#define SINGLERESPONSIBILITY

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

struct Journal
{
  string title;
  vector<string> entries;

  explicit Journal(const string &title) : title(title) {}

  void add_entry(const string &entry)
  {
    static int count =1;
    entries.push_back(lexical_cast<string>(count++) + ": " + entry);
  }

};

struct PersistenceManager
{
  static void save( const Journal &j, const string &filename)
  {
    ofstream ofs(filename);
    for ( auto &s : j.entries)
      {
        ofs << s << endl;
      }
  }
};

int singleResponsibility()
{
  cout << "This is single-responsibilty" << endl;
  Journal journal{"Dear Diary"};
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");
  PersistenceManager p;
  string filename = "journal.txt";
  p.save(journal, filename);
  return 0;
}

#endif // SINGLERESPONSIBILITY
