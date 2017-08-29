#include <bitset>
#include <iostream>
#include <string>
using namespace std;

template <typename ValueType>
inline void print( const char* name, ValueType value )
{
  cout << name << " = "
    << bitset <8> ( value ).to_string()
    << " = "
    << (int)value << endl;
}

int main()
{
  int           i;
  signed   char s;
  unsigned char u;

  cout << "Please enter a signed value in [-128, 127]: " << flush;
  cin >> i;

  s = i;
  u = i;

  cout << endl;
  print( "signed       ", s );
  print( "unsigned     ", u );

  cout << endl;
  print( "signed   >> 1", s >> 1 );
  print( "unsigned >> 1", u >> 1 );

  cout << endl;
  print( "signed   >> 2", s >> 2 );
  print( "unsigned >> 2", u >> 2 );

  return 0;
}
