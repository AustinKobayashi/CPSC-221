#include <iostream>
using namespace std;
int a = 7;
int b = 6;
int* c = &b;
void test( int& x, int y, int*& z ) {
  x++;
  y++;
  z= &a;
}
int main() {
  test(a,b,c); 
  cout << a << " " << b << " " << *c << endl;
  return 0;
}
