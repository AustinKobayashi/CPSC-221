/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/
 
#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}



//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}



//--- Definition of Queue destructor
Queue::~Queue()
{ 
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}



//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}



//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == 0); 
}



//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}



//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}



//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}



//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }   
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}


//--- Definition of move_to_front()
void Queue::move_to_front(const QueueElement & value){
    
    Queue::NodePointer before, after;
    
    before = after = myFront;
    
    //Error when queue is empty
    if(empty()){
        cerr << "*** Queue is empty ***\n";
        return;
    }
    
    //If the key is at the front, simply return
    if(myFront->data == value)
        return;
    
    //Loop through the queue until after equals the node we are looking for
    while(after->data != value){

        //Error if after reaches the end of the list and hasn't found the node
        if(after == myBack && after->data != value){
            cerr << "*** Key Value is not in Queue ***\n";
            return;
        }
        
        before = after;
        after = after->next;
    }
    
    //Once the node is found, link the node before it to the node after it
    before->next = after->next;
    
    //if after is the last node, change myBack to the node before after
    //must do this or else myBack would point to the front node
    if(after == myBack){
        myBack = before;
        myBack->next = 0;
    }
    
    //make the node point to my front, effectively placing it at the front
    after->next = myFront;
    
    //Change the front to the node
    myFront = after;
}


//--- Definition of merge_two_queues()
void Queue::merge_two_queues(Queue & q2){

    Queue::NodePointer newBack, posQ1, posQ2;
    
    posQ1 = myFront;
    posQ2 = q2.myFront;
    
    //If q1 is empty, it equals to q2 and q2 is cleared
    //This is covered by Test 1
    if(empty()){
        myFront = q2.myFront;
        myBack = q2.myBack;
        q2.myFront = 0;
        q2.myBack = q2.myFront;
        return;
    }
    
    //Sinply return if q2 is empty
    //This is covered by Test 2
    if(q2.empty())
        return;
    
    
    //If q1 front is less than q2 front and q1 is greater than one element
    //This is covered by Test 5
    if(myFront->data <= q2.myFront->data && myFront != myBack){
        newBack = myFront;
        posQ1 = posQ1->next;
        
        
    //If q1 front is less than q2 front and q1 length equals 1
    //This is covered by Test 7
    }else if (myFront->data <= q2.myFront->data && myFront == myBack){
        myFront->next = q2.myFront;
        myBack = q2.myBack;
        q2.myFront = 0;
        q2.myBack = q2.myFront;
        return;
        
    
    //If q2 front is less than q1 front and q2 is greater than one element
    //This is covered by Test 6
    }else if (q2.myFront->data < myFront->data && q2.myFront != q2.myBack){
        newBack = posQ2;
        q2.myFront = posQ2->next;
        posQ2->next = posQ1;
        myFront = posQ2;
        posQ2 = q2.myFront;
        
     
    //If q2 front is less than q1 front and q2 length equals 1
    //This is covered by Test 8
    }else if (q2.myFront->data < myFront->data && q2.myFront == q2.myBack){
        q2.myFront->next = myFront;
        myFront = q2.myFront;
        q2.myFront = 0;
        q2.myBack = q2.myFront;
        return;
    }
    
    
    while(posQ1 != 0 || posQ2 != 0){

        //Covered by Test 5, 6, 9, 10
        if(posQ1->data <= posQ2->data && posQ1 != myBack){
            newBack->next = posQ1;
            newBack = posQ1;
            posQ1 = posQ1->next;

            
        //Covered by Test 5, 6, 9, 10
        } else if(posQ2->data < posQ1->data && posQ2 != q2.myBack){
            q2.myFront = posQ2->next;
            newBack->next = posQ2;
            newBack = newBack->next;
            posQ2 = posQ2->next;
            

        //Covered by Test 4, 10
        } else if(posQ1->data <= posQ2->data && posQ1 == myBack){
            posQ1->next = posQ2;
            newBack->next = posQ1;
            myBack = q2.myBack;
            q2.myFront = 0;
            q2.myBack = q2.myFront;
            return;
            
            
        //Covered by Test 3, 5, 6, 9
        } else if(posQ2->data <= posQ1->data && posQ2 == q2.myBack){
            posQ2->next = posQ1;
            newBack->next = posQ2;
            q2.myFront = 0;
            q2.myBack = q2.myFront;
            return;
        }
    }
}

//--- Definition of remove_plane()
void Queue::remove_plane(const QueueElement & value){
    
    Queue::NodePointer before, after;
    
    before = after = myFront;
    
    //Error when queue is empty
    //Covered by Test 1
    if(empty()){
        cerr << "*** Queue is empty ***\n";
        return;
    }
    
    //If the key is at the front and queue is longer than 1, delete it and move front forward
    //Covered by Test 2
    if(myFront->data == value && myFront->next != 0){
        myFront = myFront->next;
        before = 0;
        delete after;
        return;
        
    //If the key is at the front and the queue length equals 1,
    //Delete the front and the back
    //Covered by Test 3
    } else if(myFront->data == value && myFront == myBack){
        myFront = 0;
        delete myFront;
        delete myBack;
        return;
    }
    
    
    //Loop through the queue until after equals the node we are looking for
    while(after->data != value){
        
        //Error if after reaches the end of the list and hasn't found the node
        if(after == myBack && after->data != value){
            cerr << "*** Key Value is not in Queue ***\n";
            return;
        }
        
        before = after;
        after = after->next;
    }
    
    //Once the node is found, link the node before it to the node after it
    before->next = after->next;
    
    //if after is the last node, change myBack to the node before after
    //must do this or else myBack would point to the front node
    if(after == myBack){
        myBack = before;
        myBack->next = 0;
    }
    
    //delete the node
    delete after;
}


//--- Definition of get_value_at_position()
int Queue::get_value_at_position(const QueueElement & pos){
    
    Queue::NodePointer ptr;
    ptr = myFront;
    
    //Error when queue is empty
    if(empty()){
        cerr << "*** Queue is empty ***\n";
        return 0;
    }
    
    int size = 0;
    
    while(ptr != myBack){
        
        size++;
        ptr = ptr->next;
    }
    
    ptr = myFront;
    
    for(int i = 0; i <= size; i++){
            if(i == pos)
                return ptr->data;
        
        ptr = ptr->next;
    }
    
    cerr << "*** Position greater than queue length ***\n";
    return 0;
}


















