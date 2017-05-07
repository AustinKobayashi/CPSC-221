#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
// #include <conio.h>
#include <unistd.h>

using namespace std;


/* 
 * This function tests for a double hashing hash table
 * From the graphs it looks like mys01 is the double hash
 *  
 * Since the double hash table will need to resize,
 * We should insert n + 1 items and see which graph
 * shows a resize
 */

void test_3(int n){
    
    for(int i = 1; i < 30000; i++)
        cout << "I " << i << endl;
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

    test_3(n);
    
    return 0;
}








