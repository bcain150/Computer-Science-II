#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
  // Create IntArray objects and call methods here...
  IntArray ia(10);
  IntArray ib(10, 0);
  IntArray ic(10, 4);

  ia.Get(11);
  ia.Get(0);
  ia.Get(9);
  ia.Get(-1);

  if(ia == ib)
    cout << "they are equal" << endl;

  if(ia != ic)
    cout << "they are NOT equal" << endl;
  
  ic.Clear();
  if(ia == ic)
    cout << "they are now equal" << endl;

  ia.Del(10);
  ia.Del(-1);

  ic.Clear();

  ib.SetItem(10, 12);
  ib.SetItem(-1, 2);

  ic.~IntArray();
  ic.~IntArray();

  int i = ib[-1];
  int x = ib[10];

  ic.Del(9);

  ic.Contains(12);
  // Print out the number of errors/edge cases found
  cout << endl << endl << IntArray::GetProgress() << endl;
    
  return 0;
}
