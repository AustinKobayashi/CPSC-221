#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
// #include <conio.h>
#include <unistd.h>

using namespace std;

/* 
* This function tests for a sorted vector
* Judging from the graphs of this test it looks like mys03 is the sorted vector 
*
* Worst Case:
*  - Insert: O(n) (inserting high to low)
*  - Delete: O(n) (deleting first element)
*  - Search: O(log n)
*
* Best Case:
*  - Insert: O(1) (inserting high to low)
*  - Delete: O(1) (delete last element)
*  - Search: O(1) 
*
*/
void test_2(int n){
    
    
    // Worst case insert
    for(int i = 1; i <= n/4; i++)
        cout << "I " << (n/4) - (i - 1) << endl;
    
    // Worst case delete
    for(int i = 1; i <= n/4; i++)
        cout << "R " << i << endl;
    
    
    // Best case insert
    for(int i = 1; i <= n/4; i++)
        cout << "I " << i << endl;
    
    // Best case delete
    for(int i = 1; i <= n/4; i++)
        cout << "R " << (n/4) - (i - 1) << endl;
    
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

    test_2(n);
    
    return 0;
}








