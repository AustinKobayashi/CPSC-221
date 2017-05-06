#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
// #include <conio.h>
#include <unistd.h>

using namespace std;

/* 
 * This function tests for an unsorted linked list
 * From the graphs it looks like mys06 is the unsorted linked list
 *
 * Worst Case:
 *  - Insert: O(1) 
 *  - Delete: O(n) - it takes O(n) to find the element and O(1) to delete
 *  - Search: O(n)
 */

void test_1(int n){
    
    srand(time(0));

    // List of inserted elements
    int* insertedElements = new int[n/4];
    
    // Insert elements (value of element doesnt matter)
    // Randomly generate elements and add them to the array
    for(int i = 0; i < n/4; i++){
        int n = rand() + 1;
        cout << "I " << n << endl;
        insertedElements[i] = n;
    }
    
    // Remove elements in worst case (remove last element)
    // Since the list is single linked, the last element
    // will be the first element of insertedElements
    for(int i = 0; i < n/4; i++)
        cout << "R " << insertedElements[i] << endl;
    
    // Insert elements (value of element doesnt matter)
    for(int i = 0; i < n/4; i++){
        int n = rand() + 1;
        cout << "I " << n << endl;
        insertedElements[i] = n;
    }
    
    // Find an element x, then it will be moved to the front
    // All the next finds for x will be in relatively constant time
    for(int i = 1; i <= n/4; i++)
        cout << "F " << insertedElements[0] << endl;
 
    
    delete [] insertedElements;
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

    test_1(n);
    
    return 0;
}








