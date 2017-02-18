// ..................................................  
// CDate driver 
// Adapted from Hagit Schechter, Jan 2007 for 2014W2
// ..................................................

#include "CDate.h"
#include <iostream>

void date_test( std::string msg, CDate *actual, int expect ) {
  std::cout << msg << ": ";
  actual->print();
  if( actual->getDate() != expect ) {
    std::cerr << "*ERROR* " << actual->getDate() << " != (expected) "
	      << expect << "\n";
  }
}

int main(void)
{
    
    CDate myDate0(2015,1,1);
    CDate myDate1(-1,"May",25);
    CDate myDate2(2012,"April",31);
    CDate myDate3(2011,"February",29);
    CDate myDate4(2000,"February",29);
    CDate myDate5(2014,"December",32);
    CDate myDate6(2014,"December",31);
    CDate myDate7(2010,"November",31);
    CDate myDate8(2010,"November",30);

    CDate* date9 = new CDate(2010, 2, 29); 
    CDate* date10 = new CDate(2012, 2, 29); 
    CDate* date11 = new CDate(2014, 9, 5); 

    date_test( "myDate0", &myDate0, 20150101 ); 
    date_test( "myDate1", &myDate1,        0 ); 
    date_test( "myDate2", &myDate2,        0 ); 
    date_test( "myDate3", &myDate3,        0 ); 
    date_test( "myDate4", &myDate4, 20000229 ); 
    date_test( "myDate5", &myDate5,        0 ); 
    date_test( "myDate6", &myDate6, 20141231 ); 
    date_test( "myDate7", &myDate7,        0 ); 
    date_test( "myDate8", &myDate8, 20101130 ); 
    date_test(   "date9",    date9,        0 ); 
    date_test(  "date10",   date10, 20120229 ); 
    date_test(  "date11",   date11, 20140905 ); 

    delete(date9); 
    delete(date10); 
    delete(date11); 

#ifdef _WIN32
    system("PAUSE"); // needed for windows to prevent the program from terminating and the command window to close
#endif

    return 0;
}
