#ifndef OPENCLOSEDPRINCIPLE
#define OPENCLOSEDPRINCIPLE

#include <iostream>

using namespace std;

enum class Color { Red, Green, Blue};
enum class Size { Small, Medium, Large};

struct Product
{
  string name;
  Color color;
  Size size;
};

struct ProductFilter
{
  vector<Product*>
  byColor(vector<Product*> items, Color color)
  {
    vector<Product*> result;
    for (auto &i : items)
      {
        if (i->color == color)
          {
            result.push_back(i);
          }
      }
    return result;
  }

  vector<Product*>
  bySize(vector<Product*> items, Size size)
  {
    vector<Product*> result;
    for (auto &i : items)
      {
        if (i->size == size)
          {
            result.push_back(i);
          }
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
  virtual vector<T*> filter( vector<T*> items, Specification<T> &spec ) =0;
};

struct betterFilter : Filter<Product>
{
  vector<Product*> filter( vector<Product*> items, Specification<Product> &spec )
  {
    vector<Product*> result;
    for (auto &item : items)
      {
        if ( spec.isSatisfied(item) )
          {
            result.push_back(item);
          }
      }
    return result;
  }
};

struct ColorSpecification : Specification<Product>
{
  Color color;
  ColorSpecification( Color color ) : color(color){}

  bool isSatisfied( Product *item ) override
  {
    return item->color == color;
  }
};

int openClosedPrinciple()
{
  cout << "this is open-closed principle" << endl;
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  vector<Product*> items { &apple, &tree, &house};
  ProductFilter pf;
  auto greenThings = pf.byColor(items, Color::Green);
  for (auto &item : greenThings)
    {
      cout << item->name << " is green\n";
    }
  cout << "Now on to better filter\n" << endl;
  betterFilter bf;
  ColorSpecification green(Color::Green);
  for (auto &item : bf.filter(items, green))
    {
      cout << item->name << " is green.\n";
    }
  return 0;

}

#endif // OPENCLOSEDPRINCIPLE
