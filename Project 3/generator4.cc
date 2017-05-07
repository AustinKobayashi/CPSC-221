#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
// #include <conio.h>
#include <unistd.h>

using namespace std;


/* test for AVL and Splay
 */
void test_5(int n){
    
    for(int i = 0; i < (n/2); i++)
        cout << "I" << i << endl;
    
    for(int j = 0; j < (n/2); j++)
        cout << "F" << 0 << endl;
}


/*
 * Main Testing
 */
int main(int argc, char* argv[])
{

    /* If program called incorrectly, terminate. */
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }

    /* else, take n = size. */
    int n = atoi(argv[1]);

    test_5(n);
    
    return 0;
}








