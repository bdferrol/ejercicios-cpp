// calc_err.cpp: Tests the function calc(),
// which throws exceptions.
// ----------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
double calc( int a, int b );
int main() {
    int x, y;
    double res;
    bool flag = false;
    do
    {
      try                                 // try block
      {
        cout << "Enter two positive integers: ";
        cin >> x >> y;
        res = calc( x, y);
        cout << x << "/" << y << " = " << res << endl;
flag = true;
}
catch( string& s)
{
  cerr << s << endl;
}
catch( Error& )
{
// Then to leave the loop.
         // 1st catch block
         // 2nd catch block
        cerr << "Division by 0! " << endl;
}
catch(...) // 3rd catch block {
        cerr << "Unexpected exception! \n";
exit(1);
}
   }while( !flag);
// continued ...
return 0; }
 
