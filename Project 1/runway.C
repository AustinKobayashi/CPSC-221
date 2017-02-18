#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LQueue.h"

using namespace std;

Queue landingQueue;
Queue takeOffQueue;
int landingTime=3;
int takeOffTime=2;
int landingRate=10;
int takeOffRate=12;
int simTime=120;
int planeNum = 1000;
int curTime;
int numRunways;
int numBlackList = 0;
int* blacklist;

int maxLandingQueue = 0;
int maxTakeOffQueue = 0;
float avgMinsLanding = 0;
float avgMinsTakingOff = 0;
float numLandings = 0;
float numTakeOffs = 0;


//Random number generator for landing and takeoff
int RandomGen(){
    return rand()%(100 + 1);
}


//Returns the size of the given Queue
int QueueSize(Queue q){
    
    int i = 0;
    while(!q.empty()){
        q.dequeue();
        i ++;
    }
    return i;
}


/* Random number generator for remove_plane
 This is used to determine whether or not
 a plane needs to be removed from the list.
 For example, simulates a plane deciding that
 it is changing the aiport it wants to land at.
 */
int RandomGenRemove(){
    return rand()%(4 + 1);
}

int RandomGenPlane(int size){
    
    return rand()%(size);
}

//Removes a random landing plane
void RemoveLandingPlane(){
    
    int size = QueueSize(landingQueue);
    int planeToRemove;
    switch (size) {
        case 1:
            planeToRemove = landingQueue.front();
            landingQueue.remove_plane(planeToRemove);
            cout << "   " << "Plane " << planeToRemove
            << " has decided to land elsewhere; " << endl;
            cout << "   " << "Removed it from landing queue; "
            << QueueSize(landingQueue) << " in queue" << endl;
            break;
        case 2:
            planeToRemove = landingQueue.get_value_at_position(1);
            landingQueue.remove_plane(planeToRemove);
            cout << "   " << "Plane " << planeToRemove
            << " has decided to land elsewhere; " << endl;
            cout << "   " << "Removed it from landing queue; "
            << QueueSize(landingQueue) << " in queue" << endl;
            break;
        default:
            planeToRemove = landingQueue.get_value_at_position(RandomGenPlane(size));
            landingQueue.remove_plane(planeToRemove);
            cout << "   " << "Plane " << planeToRemove
            << " has decided to land elsewhere; " << endl;
            cout << "   " << "Removed it from landing queue; "
            << QueueSize(landingQueue) << " in queue" << endl;
            break;
    }
}



bool BlackListCheck(){
    
    for(int i = 0; i < numBlackList; i++){
        if(*(blacklist + i) == planeNum)
            return true;
    }
    
    return false;
}


//plane has been enqueued to landingQueue
void LandingRequest(){
    
    if(!BlackListCheck()){
        landingQueue.enqueue(planeNum);
        cout << "   " << "Plane " << planeNum << " wants to land; "
        << "Added to landing queue; "
        << QueueSize(landingQueue) << " in queue" << endl;
        planeNum ++;
        
        if(QueueSize(landingQueue) > maxLandingQueue)
            maxLandingQueue = QueueSize(landingQueue);
        
        numLandings++;
        
    } else {
        cout << "   " << "Plane " << planeNum << " wants to land; "
        << "This plane is black listed; " << endl;
        cout << "   " << "Landing request denied; "
        << QueueSize(landingQueue) << " in queue" << endl;
        planeNum ++;
    }
}



//plane has been enqueued to takeOffQueue
void TakeOffRequest(){
    
    if(!BlackListCheck()){
        takeOffQueue.enqueue(planeNum);
        cout << "   " << "Plane " << planeNum << " wants to takeoff; "
        << "Added to takeoff queue; "
        << QueueSize(takeOffQueue) << " in queue" << endl;
        planeNum ++;
        
        if(QueueSize(takeOffQueue) > maxTakeOffQueue)
            maxTakeOffQueue = QueueSize(takeOffQueue);
        
        numTakeOffs++;
        
    } else {
        cout << "   " << "Plane " << planeNum << " wants to takeoff; "
        << "This plane is black listed; " << endl;
        cout << "   " << "Takeoff request denied; "
        << QueueSize(takeOffQueue) << " in queue" << endl;
        planeNum ++;
    }
}


//returns true if the plane has landed
bool HasPlaneLanded(int timer){
    
    if(curTime - landingTime >= timer){
        cout << "   " << "Landing Complete; "
        << QueueSize(landingQueue) << " in queue" << endl;
    } else {
        cout << "   " << "A plane is landing; " << endl;
        cout << "   " << QueueSize(landingQueue) << " plane(s) in landing queue" << endl;
        cout << "   " << QueueSize(takeOffQueue) << " plane(s) in takeoff queue" << endl;
    }
    
    return curTime - landingTime >= timer;
}


//returns true if the plane has taken off
bool HasPlaneTakenOff(int timer){
    
    if(curTime - takeOffTime >= timer){
        cout << "   " << "Takeoff Complete; "
        << QueueSize(takeOffQueue) << " in queue" << endl;
    } else {
        cout << "   " << "A plane is taking off; " << endl;
        cout << "   " << QueueSize(landingQueue) << " plane(s) in landing queue" << endl;
        cout << "   " << QueueSize(takeOffQueue) << " plane(s) in takeoff queue" << endl;
    }
    
    return curTime - takeOffTime >= timer;
    
}



//plane is landing
void Land(){
    
    cout << "   " << "Landing: Plane " << landingQueue.front() << endl;
    landingQueue.dequeue();
}



//plane is taking off
void TakeOff(){
    
    cout << "   " << "Taking off: Plane " << takeOffQueue.front() << endl;
    takeOffQueue.dequeue();
}


void BlackListCreator(){
    
    blacklist = (int*) malloc(sizeof(int) * numBlackList);
    for(int i = 0; i < numBlackList; i++){
        int num;
        cout << "   " << "Enter a plane number to blacklist (Eg. 1000) : ";
        cin >> num;
        *(blacklist + i) = num;
    }
    
    
}
void Input(){
    
    cout << "\n" << "--------------------------------------------------------------" << endl;
    cout << "Please Input: " << endl;
    cout << "   " << "Time for a plane to land (in minutes) : ";
    cin >> landingTime;
    cout << "   " << "Time for a plane to takeOff (in minutes) : ";
    cin >> takeOffTime;
    cout << "   " << "Landing rate (planes per hour) : ";
    cin >> landingRate;
    cout << "   " << "Takeoff rate (planes per hour) : ";
    cin >> takeOffRate;
    cout << "   " << "How long to run the simulation (in minutes) : ";
    cin >> simTime;
    cout << "   " << "How many planes would you liked to blacklist\n "
    << "    " << "(Enter 0 to run the simulation normally): ";
    cin >> numBlackList;
    if(numBlackList > 0)
        BlackListCreator();
    cout << "--------------------------------------------------------------" << "\n" << endl;
}



void Statistics(){
    
    cout << "--------------------------------------------------------------" << endl;
    cout << "Statistics\n"
    << "--------------------------------------------------------------" << "\n" << endl;
    cout << "Maximum number of planes in landing queue was: " << maxLandingQueue << endl;
    
    if(numLandings > 0)
        cout << "Average minutes spent waiting to land: " << avgMinsLanding/numLandings << endl;
    else
        cout << "Average minutes spent waiting to land: 0" << endl;
    
    cout << "Maximum number of planes in takeoff queue was: " << maxTakeOffQueue << endl;
    
    if(numTakeOffs > 0)
        cout << "Average minutes spent waiting to takeoff: " << avgMinsTakingOff/numTakeOffs << endl;
    else
        cout << "Average minutes spent waiting to takeoff: 0" << endl;
    
    cout << "\n" << endl;
}


int main(void){
    
    int landingRand;
    int takeOffRand;
    int timer;
    
    bool runwayFree = true;
    bool takingOff = false;
    bool landing = false;
    
    Input();
    
    srand(time(NULL));
    
    for(int i = 1; i <= simTime; i++){
        
        curTime = i;
        cout << "\n" << endl;
        
        cout << "Time: " << curTime << endl;
        
        if(RandomGenRemove() > 3 && QueueSize(landingQueue) > 0)
            RemoveLandingPlane();
            
        if(!runwayFree && landing){
            runwayFree = HasPlaneLanded(timer);
        } else if (!runwayFree && takingOff){
            runwayFree = HasPlaneTakenOff(timer);
        }
        
        landingRand = RandomGen();
        takeOffRand = RandomGen();
        
        if( landingRand % 60 < landingRate)
            LandingRequest();
        
        if( takeOffRand % 60 < takeOffRate)
            TakeOffRequest();
        
        if(runwayFree){
            
            landing = false;
            takingOff = false;
            
            if(!landingQueue.empty()){
                Land();
                runwayFree = false;
                timer = i;
                landing = true;
            } else if(!takeOffQueue.empty()) {
                TakeOff();
                runwayFree = false;
                timer = i;
                takingOff = true;
            }
        }
        
        avgMinsLanding += QueueSize(landingQueue);
        avgMinsTakingOff += QueueSize(takeOffQueue);
    }
    
    
    cout << "\n--------------------------------------------------------------" << endl;
    cout << "No new takeoffs or landings will be generated" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    while (!landingQueue.empty() || !takeOffQueue.empty() || !runwayFree) {
        
        curTime++;
        
        cout << "\n" << endl;
        cout << "Time: " << curTime << endl;
        
        
        if(RandomGenRemove() > 3 && QueueSize(landingQueue) > 0)
            RemoveLandingPlane();

        if(!runwayFree && landing){
            runwayFree = HasPlaneLanded(timer);
        } else if (!runwayFree && takingOff){
            runwayFree = HasPlaneTakenOff(timer);
        }
        
        if(runwayFree){
            
            landing = false;
            takingOff = false;
            
            if(!landingQueue.empty()){
                Land();
                runwayFree = false;
                timer = curTime;
                landing = true;
            } else if(!takeOffQueue.empty()) {
                TakeOff();
                runwayFree = false;
                timer = curTime;
                takingOff = true;
            }
        }
        
        avgMinsLanding += QueueSize(landingQueue);
        avgMinsTakingOff += QueueSize(takeOffQueue);
    }
    
    cout << "\nEnd of program. \n" << "\n" << endl;
    
    Statistics();
}


