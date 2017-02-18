#include <iostream>
#include <cstdlib>
#include "insertion.h"

using namespace std;



int main () {
    int x = 5, y = 15;
    int *p1, *p2;
                // value of     x       y       p1          p2              *p1     *p2
                //              5       15      uninit      uninit
    p1 = &x;    //              5       15      addr of x   uninit          5
    //
    p2 = &y;    //              5       15      addr of x   addr of y       5       15
    //
    *p1 = 6;    //              6       15      addr of x   addr of y       6       15
    //
    *p1 = *p2;  //              15      15      addr of x   addr of y       15      15
    //
    p2 = p1;    //              15      15      addr of x   addr of x       15      15
    //
    *p1 = *p2+10;   //          25      15      addr of x   addr of x       25      25
    //
    return 0;
}
