/*---------------------------------------------------------------------
 Driver program to test the Queue class.
 ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;


void print(Queue q)
{ q.display(cout); }

int main(void)
{
    Queue q1;
    cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;
    
    cout << "How many elements to add to the queue? ";
    int numItems;
    cin >> numItems;
    for (int i = 1; i <= numItems; i++)
        q1.enqueue(100*i);
    
    cout << "Contents of queue q1 (via  print):\n";
    print(q1);
    cout << endl;
    
    Queue q2;
    q2 = q1;
    cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
    print(q2);
    cout << endl;
    
    cout << "Queue q2 empty? " << q2.empty() << endl;
    
    cout << "Front value in q2: " << q2.front() << endl;
    
    while (!q2.empty())
    {
        cout << "Remove front -- Queue contents: ";
        q2.dequeue();
        q2.display(cout);
    }
    cout << "Queue q2 empty? " << q2.empty() << endl;
    cout << "Front value in q2?" << endl << q2.front() << endl;
    cout << "Trying to remove front of q2: " << endl;
    q2.dequeue();
    
    
    
    /*--------------------------------------------------------------------------
     Tests for move_to_front function
     
     These tests start by creating a third queue, q3, and copying q1 to q3.
     move_to_front is then called on every value in q3. After move_to_front
     is finished being called, q3 should be q1 in reverse.
     
     Then there is a test to try and move a key, equal to zero, that is not
     in the list. The expected output is the error:
     "*** Key Value is not in Queue ***".
     --------------------------------------------------------------------------*/

    
    cout << "\n\n\n-------------------------------------------------" << endl;
    cout << "MOVE TO FRONT TESTS" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    Queue q3 = q1;
    cout << "\nQ3 equals q1:" << endl;
    cout << "q1: ";
    q1.display(cout);
    cout << "q3: ";
    q3.display(cout);
    cout << "\n" << endl;
    
    for(int i = 1; i <= numItems; i++){
        
        cout << "Moving " << 100*i << " to the front of the q3" << endl;
        q3.move_to_front(100*i);
        cout << "Q3: ";
        q3.display(cout);
        cout << "\n" << endl;
    }
    
    cout << "Q3 should be q1 in reverse:" << endl;
    cout << "Q1: ";
    q1.display(cout);
    cout << "Q3: ";
    q3.display(cout);
    cout << "\nTrying to move invalid key 0 to front of q3" << endl;
    q3.move_to_front(0);
    cout << "\n\n" << endl;
    
    
    
    
    /*--------------------------------------------------------------------------
     Tests for merge_two_queues
     
     These tests start by creating two new queues, q4 and q5. q5 is then loaded
     with the values { 2, 4, 6, 8 }.
     
     Test 1: This checks the case when q4 is empty and q5 is not.
     Test 2: This checks the case when q5 is empty and q4 is not.
     Test 3: This checks the case when q4 is longer than q5.
     Test 4: This checks the case when q5 is longer than q4.
     Test 5: This checks the case when q4 front is less than q5 front.
     Test 6: This checks the case when q5 front is less than q4 front.
     Test 7: This checks the case when q4 front is less than q5 front and
             q4 length equals 1.
     Test 8: This checks the case when q5 front is less than q4 front and
             q5 length equals 1.
     Test 9: This checks the case when q4 front equals q2 front.
     Test 10: This checks the case when q4 equals to q5;
     
     --------------------------------------------------------------------------*/

    cout << "\n-------------------------------------------------" << endl;
    cout << "MERGE TWO QUEUES TESTS" << endl;
    cout << "-------------------------------------------------\n" << endl;

    Queue q4;
    Queue q5;
    for(int i = 1; i < 5; i ++){
        q5.enqueue(i + i);
    }
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 1] When q4 is empty and q5 is not:" << endl;
    cout << "-------------------------------------------------\n" << endl;

    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;
    
    cout << "\n" << endl;

    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 2] When q5 is empty and q4 is not:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 3] When q4 is longer than q5:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    q5.enqueue(3);

    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;
    
    
    cout << "\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 4] When q5 is longer than q4:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(2);
    
    q5.enqueue(1);
    q5.enqueue(3);
    q5.enqueue(5);

    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;
    
    
    cout << "\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 5] When q4 front is less than q5 front:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(1);
    q4.enqueue(4);
    q4.enqueue(6);

    q5.enqueue(2);
    q5.enqueue(3);
    q5.enqueue(5);
    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 6] When q5 front is less than q4 front:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(2);
    q4.enqueue(4);
    q4.enqueue(6);
    
    q5.enqueue(1);
    q5.enqueue(3);
    q5.enqueue(5);
    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 7] When q4 is length 1 and q5 is not:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(1);
    
    q5.enqueue(2);
    q5.enqueue(3);
    q5.enqueue(5);
    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;


    cout << "\n" << endl;

    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 8] When q5 is length 1 and q4 is not:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(3);
    q4.enqueue(4);
    q4.enqueue(5);

    q5.enqueue(1);

    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;


    cout << "\n" << endl;

    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 9] When q4 front equals q5 front:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(1);
    q4.enqueue(2);
    q4.enqueue(5);
    
    q5.enqueue(1);
    q5.enqueue(3);
    q5.enqueue(4);
    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;


    cout << "\n" << endl;

    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 10] When q4 equals q5:" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    while(!q4.empty())
        q4.dequeue();
    
    q4.enqueue(1);
    q4.enqueue(2);
    q4.enqueue(5);
    
    q5 = q4;
    
    cout << "Contents of queue q4:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5:\n";
    q5.display(cout);
    cout << endl;
    
    q4.merge_two_queues(q5);
    
    cout << "Contents of queue q4 after sort:\n";
    q4.display(cout);
    cout << endl;
    cout << "Contents of queue q5 after sort:\n";
    q5.display(cout);
    cout << endl;


    /*--------------------------------------------------------------------------
     Tests for remove_plane function
     This is used in runway
     
     These tests start by creating a queue, q6.

     "*** Key Value is not in Queue ***".
     --------------------------------------------------------------------------*/
    
    
    cout << "\n\n\n-------------------------------------------------" << endl;
    cout << "REMOVE PLANE TESTS" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    Queue q6;
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 1] Queue is empty" << endl;
    cout << "-------------------------------------------------\n" << endl;

    q6.remove_plane(0);
    
    cout << "\n" << endl;

    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 2] Value is at start of queue and queue is longer than 1" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    for(int i = 0; i < 5; i++)
        q6.enqueue(i);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;

    q6.remove_plane(0);
    
    cout << "Contents of queue q6 after remove_plane (0):\n";
    q6.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 3] Value is at start of queue and queue length equals 1" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    q6 = q5;
    
    q6.enqueue(5);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    q6.remove_plane(5);
    
    cout << "Contents of queue q6 after remove_plane (5):\n";
    q6.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 3] Value is in middle of queue" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    for(int i = 0; i < 5; i++)
        q6.enqueue(i);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    q6.remove_plane(2);
    
    cout << "Contents of queue q6 after remove_plane (2):\n";
    q6.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
  
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 4] Value is at end of queue" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    q6 = q5;
    
    for(int i = 0; i < 5; i++)
        q6.enqueue(i);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    q6.remove_plane(4);
    
    cout << "Contents of queue q6 after remove_plane (4):\n";
    q6.display(cout);
    cout << endl;
    
    cout << "\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 5] Value is not in queue" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    q6 = q5;
    
    for(int i = 0; i < 5; i++)
        q6.enqueue(i);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    q6.remove_plane(100);
    
    cout << "\nContents of queue q6 after remove_plane (100):\n";
    q6.display(cout);
    cout << endl;
    
    cout << "\n" << endl;



    /*--------------------------------------------------------------------------
     Tests for get_value_at_position function
     This is used in runway
     
     "*** Key Value is not in Queue ***".
     --------------------------------------------------------------------------*/
    
    
    cout << "\n\n\n-------------------------------------------------" << endl;
    cout << "GET VALUE AT POSITION TESTS" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 1] Queue is empty" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    q6 = q5;

    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    int val = q6.get_value_at_position(0);
    
    cout << "\n" << endl;
    
    
    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 2] Queue is populated" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    for(int i = 0; i < 5; i++)
        q6.enqueue(i+i);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    val = q6.get_value_at_position(4);

    cout << "\nValue at position (4): " << val << endl;
    
    cout << "\n" << endl;

    
    cout << "-------------------------------------------------" << endl;
    cout << "[Test 3] Position is greater than queue length" << endl;
    cout << "-------------------------------------------------\n" << endl;
    
    q6 = q5;
    
    for(int i = 0; i < 5; i++)
        q6.enqueue(i);
    
    cout << "Contents of queue q6:\n";
    q6.display(cout);
    cout << endl;
    
    val = q6.get_value_at_position(10);
    

    
    //system("PAUSE");
    return 0;
}
