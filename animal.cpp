#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
  virtual void greet(Animal *a) { print("hello animal"); }
  virtual void sniff(Animal *a) { print("sniff animal"); }
  virtual void praise(Animal *a) { print("u r cool animal"); }

  void print(string msg) { cout << msg << endl; }
};

class Dog : public Animal {
public:
  void sniff(Animal *a) override { print("dog sniff animal"); }
  void praise(Dog *a) { print("u r cool dog"); }
};

int main() {
  Animal *a = new Dog();
  Dog *d = new Dog();
  a->greet(d);  // hello animal
  a->sniff(d);  // dog sniff animal
  d->praise(d); // u r cool dog
  a->praise(d); // u r cool animal
  d->greet(d);  // hello animal
  delete a;
  delete d;
}
