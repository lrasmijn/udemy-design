#ifndef OPENCLOSEEXERCISE
#define OPENCLOSEEXERCISE

#include <iostream>

using namespace std;

enum class Color { red, green, blue};
enum class Size { small, medium, large};

struct Product
{
  string m_name;
  Color m_color;
  Size m_size;
};

struct ProductFilter
{
  vector<Product*>
  byColor(vector<Product*> items, Color color)
  {
    vector<Product*> result;
    for(auto &item : items)
    {
      if(item->m_color == color)
        result.push_back(item);
    }
    return result;
  }
};

template <typename T>
struct Specification
{
  virtual bool isSatisfied(T *item) = 0;
};

template <typename T>
struct Filter
{
  virtual vector<T*> filter( vector<T*> items, Specification<T> &spec ) = 0;
};

struct BetterProductFilter : Filter<Product>
{
  vector<Product*> filter(vector<Product *> items, Specification<Product> &spec)
  {
    vector<Product*> result;
    for(auto &item : items)
      if( spec.isSatisfied(item) )
        result.push_back(item);
    return result;
  }
};

struct ProductColorSpecification : Specification<Product>
{
  Color color;
  ProductColorSpecification( Color color) : color(color){}
  bool isSatisfied(Product *item) override
  {
    return item->m_color == color;
  }
};

int openCloseExercise()
{
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};
  vector<Product*> items{ &apple, &tree, &house};

  ProductFilter pf;
  vector<Product*> greenProducts;
  greenProducts = pf.byColor( items, Color::green);
  for(auto &item : greenProducts)
    cout << item->m_name << " is green.\n";
  cout << "Now we will use better filter\n";

  BetterProductFilter bf;
  ProductColorSpecification green(Color::green);
  for(auto &item : bf.filter(items, green))
    cout << item->m_name << " is green.\n";


  return 0;
}

#endif // OPENCLOSEEXERCISE

