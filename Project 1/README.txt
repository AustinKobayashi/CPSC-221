{\rtf1\ansi\ansicpg1252\cocoartf1504
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red255\green255\blue255;}
{\*\expandedcolortbl;\csgray\c100000;\csgray\c0;\csgray\c100000;}
\margl1440\margr1440\vieww12600\viewh7280\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \cb3 \CocoaLigature0 \
Included files:\
	- LQueue_driver.C: This is the main function of LQueue and tests the 					  implementation of LQueue.\
\
	- LQueue.C: This contains the implementations of the LQueue class.\
\
	- LQueue.h: This is the header file of the LQueue class.\
\
	- runway.C: This is the runway file that implements the LQueue header.\
\
	- Makefile: This is the make file for LQueue and runway\
\
\
LQueue_driver:  There are multiple tests in this file that test the implementation\
			   of LQueue.C. There are comments that describe what case is being 			   tested. There are also comments in the LQueue.C file at the 			   blocks of code that each test covers to help show the test coverage.\
\
Runway: Has the specified functionality plus 3 additional functionalities: Blacklist,\
		remove plane, value at position.\
\
\
Blacklist: When prompting the user for input data, there are additional fields:\
			The size of the blacklist, and the plane numbers. Ie, if the size is\
			5, then there will be 5 additional input fields for the plane numbers.\
			If a plane with a number on the blacklist tries to take off or land, it\
			is not added to its respective queue, and the plane number increases.\
\
			Eg) Plane 1000 is the only plane on the blacklist. It tries to land.\
				The program states that the request is denied, and the plane number\
				increases to 1001. This means that the next plane to request to land\
				or take off will have number 1001 (it will be enqueued to its respective\
				queue as: queue.enqueue(1001)).\
\
			To see the program run without the blacklist, simply input the size of the\
			blacklist to 0.\
\
			There are 2 helper functions to accomplish the blacklist functionality:\
			BlackListCheck() and BlackListCreator(). BlackListCreator is called when\
			the user is inputting data. It will create a dynamic array whose size is \
			determined by the user input, and it will add the planes to the list based\
			off user data. BlackListCheck() will loop through the blacklist and check if\
			the plane number is in the blacklist. It returns true if it is, or false if the\
			plane number is not.\
\
\
\
Value at position: This function is implemented in LQueue.C. It takes an int as a parameter\
					and will return the data of the node at the position (if any). It is\
					equivalent to calling array[n] to get the value of the array at \
					index n.\
\
Remove:	This function is implemented in LQueue.C. It takes an int as a parameter and will \
		remove the node whose value is equal to the int from the queue (if any). \
\
\
The reason why I added the value at position and remove functions is so that a plane can\
leave the landing list without having to land. For example, if a plane is queued to land\
and for some reason or another, it decides it doesn\'92t want to land at that airport\
(such as an emergency, impatient pilot, etc..), then the plane can be removed from the queue.\
So if we know that the plane is at position n in the queue, we can get the plane number\
by calling get_value_at_position(n). With the plane number, we can call remove_plane(planeNum)\
to remove the plane from the queue. The runway simulator implements this functionality\
with 3 functions: RandomGenRemove(), RandomGenPlane(), and RemoveLandingPlane().\
RandonGenRemove generates a random number between [0, 4] inclusive and returns the number.\
This is used the generator used to decide whether or not to land. If the random number equals\
to 4, RemoveLandingPlane is called. RemoveLandingPlane will remove a random plane from the\
queue. This will simulate a plane being dequeued without landing (although this probably\
happens much less frequently in real life, the probability of occurrence was intentionally\
set to be high so that the functionality has a greater chance of being demonstrated without\
having to run the program thousands of times). If the size of the landing queue is large \
(greater than 2), then RemoveLandingPlane will call RandomGenPlane, which takes an int as\
a parameter. This parameter is the size of the queue, and the function will calculate a random\
value between 0 and size, then return it. RemoveLandingPlane will then remove the plane\
at the position that was returned.\
\
Summary of additional functionality:\
\
- A blacklist to deny certain planes from takeoff or landing\
- A simulation of random planes leaving the landing queue without landing\
\
\
\
\
\
\
}