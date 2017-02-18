
/*-- LQueue.h -------------------------------------------------------------
 
 This header file defines a Queue data type.
 Basic operations:
 constructor:  Constructs an empty queue
 empty:        Checks if a queue is empty
 enqueue:      Modifies a queue by adding a value at the back
 front:        Accesses the top queue value; leaves queue unchanged
 dequeue:      Modifies queue by removing the value at the front
 display:      Displays all the queue elements
 Note: Execution terminates if memory isn't available for a queue element.
 ---------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef LQUEUE
#define LQUEUE

typedef int QueueElement;

class Queue
{
public:
    /***** Function Members *****/
    
    /***** Constructors *****/
    Queue();
    /*-----------------------------------------------------------------------
     Construct a Queue object.
     
     Precondition:  None.
     Postcondition: An empty Queue object has been constructed.
     (myFront and myBack are initialized to null pointers).
     -----------------------------------------------------------------------*/
    
    Queue(const Queue & original);
    /*-----------------------------------------------------------------------
     Copy Constructor
     
     Precondition:  original is the queue to be copied and is received
     as a const reference parameter.
     Postcondition: A copy of original has been constructed.
     -----------------------------------------------------------------------*/
    
    /***** Destructor *****/
    ~Queue();
    /*-----------------------------------------------------------------------
     Class destructor
     
     Precondition:  None.
     Postcondition: The linked list in the queue has been deallocated.
     -----------------------------------------------------------------------*/
    
    /***** Assignment *****/
    const Queue & operator= (const Queue & rightHandSide);
    /*-----------------------------------------------------------------------
     Assignment Operator
     
     Precondition:  rightHandSide is the queue to be assigned and is
     received as a const reference parameter.
     Postcondition: The current queue becomes a copy of rightHandSide
     and a reference to it is returned.
     -----------------------------------------------------------------------*/
    
    bool empty() const;
    /*-----------------------------------------------------------------------
     Check if queue is empty.
     
     Precondition:  None.
     Postcondition: Returns true if queue is empty and false otherwise.
     -----------------------------------------------------------------------*/
    
    void enqueue(const QueueElement & value);
    /*-----------------------------------------------------------------------
     Add a value to a queue.
     
     Precondition:  value is to be added to this queue.
     Postcondition: value is added at back of queue.
     -----------------------------------------------------------------------*/
    
    void display(ostream & out) const;
    /*-----------------------------------------------------------------------
     Display values stored in the queue.
     
     Precondition:  ostream out is open.
     Postcondition: Queue's contents, from front to back, have been
     output to out.
     -----------------------------------------------------------------------*/
    
    QueueElement front() const;
    /*-----------------------------------------------------------------------
     Retrieve value at front of queue (if any).
     
     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue is returned, unless the queue
     is empty; in that case, an error message is displayed and a
     "garbage value" is returned.
     -----------------------------------------------------------------------*/
    
    void dequeue();
    /*-----------------------------------------------------------------------
     Remove value at front of queue (if any).
     
     Precondition:  Queue is nonempty.
     Postcondition: Value at front of queue has been removed, unless
     queue is empty; in that case, an error message is displayed
     and execution allowed to proceed.
     -----------------------------------------------------------------------*/
    
    void move_to_front(const QueueElement & value);
    /*-----------------------------------------------------------------------
     Searches the queue for the value and places that node at the front (if any)
     
     Precondition:  Queue is nonempty.
     Postcondition: Node with data equal to value is moved to the front of
     the queue, unless the queue is empty; in that case, and error message is
     displayed and execution is allowed to proceed.
     -----------------------------------------------------------------------*/
    
    void merge_two_queues(Queue & q2);
    /*-----------------------------------------------------------------------
     Merges two presorted queues into a single queue
     
     Precondition:  Queues are presorted into ascending order
     Postcondition: The queues are merged into a single large queue on the queue
     that called the function. The queue which is passed as a parameter will
     be empty after the function executes.
     -----------------------------------------------------------------------*/

    void remove_plane(const QueueElement & value);
    /*-----------------------------------------------------------------------
     This is part of the runway program.
     It will remove the node with a given key from the queue (if any)
     
     Precondition:  Queue is nonempty.
     Postcondition: The node with the value of the parameter is removed
     -----------------------------------------------------------------------*/
    
    int get_value_at_position(const QueueElement & pos);
    /*-----------------------------------------------------------------------
     This is part of the runway program.
     Returns the value at the given position
     
     Precondition:  Queue is nonempty.
     Postcondition: The value of the node at the given position is returned
     -----------------------------------------------------------------------*/
    
    
private:
    /*** Node class ***/
    class Node
    {
    public:
        QueueElement data;
        Node * next;
        //--- Node constructor
        Node(QueueElement value, Node * link = 0)
        /*-------------------------------------------------------------------
         Precondition:  value and link are received
         Postcondition: A Node has been constructed with value in its
         data part and its next part set to link (default 0).
         ------------------------------------------------------------------*/
        { data = value; next = link; }
        
    };
    
    typedef Node * NodePointer;
    
    /***** Data Members *****/
    NodePointer myFront,      // pointer to front of queue
    myBack;       // pointer to back of queue
    
}; // end of class declaration

#endif
