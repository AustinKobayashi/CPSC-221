#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
#include <unistd.h>

using namespace std;


// Inserts multiples of three then searches for last item
// Helps to distinguish between hash table with chaining and bst
void test_7(int n){
    
    srand(time(0));
    
    int* insertedElements = new int[n/2];
    
    for(int i = 0; i < n/2; i++){
        int m = rand() % n;
        cout << "I" << 3 * m << endl;
        insertedElements[i] = 3*m;
    }
    
    
    for(int i = (n/2); i > 0; i++)
        cout << "F" << insertedElements[i-1] << endl;
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

    test_7(n);
    
    return 0;
}








