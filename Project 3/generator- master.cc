#include <iostream>
#include <cstdlib> // for atoi
#include <ctime>
#include <iostream>
#include <climits>
// #include <conio.h>
#include <unistd.h>

using namespace std;

/*
 * Includes all the general tests for Removing elements from
 *  a data structure, implemented using a switch and input n.
 */
void remove_tests(int in)
{
    // TODO: Write this test function.
}

/*
 * Includes all the general tests for Finding elements from
 *  a data structure, implemented using a switch and input n.
 */
void find_tests(int in)
{
    int num_els = in;

    /* Look for random-magnitude elements. */
    for(int i = 0; i <= num_els/2; i++)
        cout << "I" << i << endl;

    /* Look for els with increasing magnitude. */
    for(int i = 0; i < num_els/2; i++)
        cout << "F" << 0 << endl;

}

/*
 * Includes all the general tests for Inserting elements from
 *  a data structure, implemented using a switch and input n.
 */
void insert_tests(int in)
{
    srand(time(0));

    int num_els = 1000000;

    switch(in)
    {
        case 0:
            /* Insert random-magnitude elements. */
            for(int i = 0; i < num_els; i++)
                cout << "I" << (rand() % 10000) << endl;
            
            break;

        case 1:
            /* Insert with increasing magnitude. */
            for(int i = 0; i < num_els; i++)
                cout << "I" << ( i + 1 ) << endl;

            break;
    }
}

/*
 * This function tests for identification between the BST and AVL Tree
 *   data structures by looking at their worst case.
 *
 *  BST : 
 *  Insert - O(lg n), O(n)
 *  Find   - O(lg n), O(n)
 *  Remove - O(lg n), O(n)
 *
 * AVL Tree :
 * Insert  - O(lg n)
 * Find    - O(lg n)
 * Remove  - O(lg n), O(n)
 *
 */
void test_1()
{
    /* Possible Ways to Call */
    // cout << "I " << 100 << endl;
    // cout << "F" << 100 << endl;
    // cout << "R " << 100 << endl;

    /* Insert num_items into both structures. */
    int num_items = 1000;

    /* Data Strucs contain { 1, 2, .... 1000 } */
    for(int i = 0; i < num_items; i++)
    {
        /* Insert items with increasing magnitude to create long extension. */
        cout << "I" << (i + 1) << endl;
    }

    /* Search for the Worst-Case I/F/R. */
    // Search through last 10% of items
    int start_search = num_items - (num_items / 10) - 1;

    for( start_search; start_search < num_items; start_search++)
    {
        cout << "F" << start_search << endl;
    }

    /* Delete second 50% of all elements */
    start_search = num_items / 2;

    for(start_search; start_search < num_items; start_search++)
    {
        cout << "R" << start_search << endl;
    }
}

/*
 * This function tests for identification between the AVL Tree and SPT 
 *   data structures by looking at their worst case.
 *
 * AVL Tree :
 * Insert  - O(lg n)
 * Find    - O(lg n)
 * Remove  - O(lg n), O(n)
 *
 *  SPT : 
 *  Insert - O(lg n), O(n)
 *  Find   - O(lg n), O(n)
 *  Remove - O(lg n), O(n)
 *
 */
void test_2()
{
    // TODO: Write this test. 

   /* Possible Ways to Call */
    // cout << "I " << 100 << endl;
    // cout << "F" << 100 << endl;
    // cout << "R " << 100 << endl;
}




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
void test_6(int n){
    
    
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
 * This function tests for a double hashing hash table
 * From the graphs it looks like mys01 is the double hash
 *  
 * Since the double hash table will need to resize,
 * We should insert n + 1 items and see which graph
 * shows a resize
 */

void test_7(int n){
    
    for(int i = 1; i < 30000; i++)
        cout << "I " << i << endl;
}




/* 
 * This function tests for an unsorted linked list
 * From the graphs it looks like mys06 is the unsorted linked list
 *
 * Worst Case:
 *  - Insert: O(1) 
 *  - Delete: O(n) - it takes O(n) to find the element and O(1) to delete
 *  - Search: O(n)
 */

void test_8(int n){
    
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

void test_9(int n)
{
    int num = 3;

    int arr[] = {3,6,9,12,15,18,21,24,27,30};

    for(int i =0; i <n ;i++)
    {
        cout << "I" << arr[rand()%10] << endl; 
    }

}

void test_10(int n){
    
    for(int i = 0; i < (100); i++){
        cout << "I " << i << endl;
    }
    
    for(int i = 0; i < (n); i++){
        cout << "F " << 0 << endl;
    }
}

/*
 * Main Testing
 */
int main(int argc, char* argv[])
{
    srand(time(0));

    /* If program called incorrectly, terminate. */
    if (argc != 2) // remember, argv[0] is the program name
    {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }

    /* else, take n = size. */
    int n = atoi(argv[1]);

    /* To test for specific data structure differances. */
        
    /* BST vs AVL */
    // test_1();

    /* AVL vs SPT */
    // test_2();

    /* Sorted Vector test */
    // test_6(n);
    
    /* Double Hash test */
    //test_7(n);
    
    /* Unsorted Linked List test */
    // test_8(n);
    
    /* All general Insert tests. */
    //insert_tests(n);

    /* All general Find tests. */
    find_tests(n);

    /* All general Remove tests. */
    // remove_tests(n);

    /* Mod test */
    // test_9(n);

    // test_10(n);

    return 0;
}
