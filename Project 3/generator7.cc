#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
#include <unistd.h>

using namespace std;


// Helps to distinguish between an AVL and an unsorted Linked List
void test_8(int n){
    
    for(int i = 1; i <= n/2; i++){
        cout << "I" << i << endl;
    }
    
    
    for(int i = 0; i < n/2; i++)
        cout << "F" << (n/2) << endl;
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

    test_8(n);
    
    return 0;
}








