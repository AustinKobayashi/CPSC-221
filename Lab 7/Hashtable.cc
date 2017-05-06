#include "Hashtable.h"
#include <cstdlib>
#include <iostream>
#include <cassert> 

using namespace std; 
// (i) at load < 0.5 quadratic and linear are comparable
// (ii) Currently our hash2 function is comparable to quadratic
// (iii) hash2 is better than linear hash under load > 0.5 and comparable other times
//       Once the first ceiling(size/2) slots are filled, hash2 starts to pull ahead of quadratic
//       This is because quadratic will start to produce duplicate spots
// (iv) It depends on what we are trying to hash. If we know the data and know there will be low or no
//      chance of clustering, linear would be the best choice. If there will be high clustering, then
//      double hashing is the best. If there is an average amount, quadratic is best.

Hashtable::Hashtable(int size) {
	//constructor
	int prime = nextPrime( size ); 
	_size = size;
	if (prime != size) { 
	  cout << "Warning: size = " << size << " is not a prime number." << endl; 
/* uncomment these if you want */ 
//	  cout << "Using " << prime << " instead." << endl; 
//	  _size = prime; 
	}
	_totalProbes = 0;
	_numInserts = 0;
	_numFailures = 0; 
	_table = new int [ _size ];
	for (int ii=0; ii < _size; ii++) {
		_table[ ii ] = EMPTY;
	}
}
void Hashtable::clear(void) {
	_totalProbes = 0;
	_numInserts = 0;
	_numFailures = 0; 
	for (int ii=0; ii < _size; ii++) {
		_table[ ii ] = EMPTY;
	}
}    
    

Hashtable::~Hashtable() {
	//deconstructor
	delete[] _table;
}

void Hashtable::tallyProbes(int p) {
	// Add the number of probes, p, for one insert operation to the tally.
	_totalProbes += p;
	_numInserts += 1;
}

void Hashtable::printStats() {
	cout << "Average probes/insert = " <<
			probeRate() << " = " <<
			_totalProbes << "/" << _numInserts;
	cout <<", size = "<< _size;
	cout <<", failures = " << _numFailures << endl;
}

float Hashtable::probeRate() {
	return (float)_totalProbes / (float)_numInserts;
}

int Hashtable::hash(int k) {
	return k % _size;
}

void Hashtable::qinsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with quadratic probing and hash(k) = k % _size.

	// Tips:
	// - Look at the lecture slides if you don't remember how to implement these.
	// - You need to prevent against infinite loops. You should limit the number
	// of times you probe and print an error message upon exceeding this limit.
	// - You're welcome to add new declarations to hash.h, add to the constructor,
	// include libraries, or anything else you need. 
	// - You're also welcome to modify the main() method to automate your testing.

    // Only first _size/2 slots are distinct
    // Suffers from secondary clustering: 
    // all items that hash to the same spot follow the same probe sequence
    
    // ************* ADD YOUR CODE HERE *******************
        
    int p = hash(k);
    int tries = 1;

    while(tries <= _size){
        
        if(_table[p] == EMPTY){
            tallyProbes(tries);
            _table[p] = k;
            return;
        }
        
        p = (hash(k) + tries*tries) % _size;
        
        tries++;
    }
    
    // Your method should return after it stores the value in an EMPTY slot 
    // and calls tallyProbes, so if it gets here, it didn't find an EMPTY slot 
    _numFailures += 1; 
    cout << "Warning: qinsert(" << k << ") found no EMPTY slot, so no insert was done." << endl;
}

void Hashtable::linsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with linear probing and hash(k) = k % _size.

    // Works for (#items / _size) < 1
    // Suffers from primary clustering: creates a long, consecutive sequence of filled slots
    // Performance quickly degrades for (#items / _size) > 1/2
    
    
    // ************* ADD YOUR CODE HERE *******************
    
    int p = hash(k);
    int tries = 1;
    
    while(tries <= _size){
        
        if(_table[p] == EMPTY){
            tallyProbes(tries);
            _table[p] = k;
            return;
        }
        
        p = (hash(k) + tries) % _size;
        
        tries++;
    }

    
    // Your method should return after it stores the value in an EMPTY slot 
    // and calls tallyProbes, so if it gets here, it didn't find an EMPTY slot 
    _numFailures += 1; 
    cout << "Warning: linsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
}


int Hashtable::Hash2 (int k){
    
    int prime = 0;
    
    for(int i = _size - 1; i > 0; i--){
        if(isPrime(i)){
            prime = i;
            break;
        }
    }
        
    if(!isPrime(prime))
        return -1;
    
    return prime - (k % prime);
     
}

void Hashtable::dinsert(int k) {
	// Insert k in the hash table.
	// Use open addressing with double hashing. Use the existing hash function
	// and also implement a second hash function.

    // Problem with nextPrime function!!!
    // If given a prime, it will return the same prime
    // Ie) nextPrime(7) = 7
    
    // For (#items / _size) < 1 double hash will find a spot (if size and hash2 are well chosen)
    // No primary or secondary clustering
    // One extra hash calculation
    
    // ************* ADD YOUR CODE HERE *******************
    
    int p = hash(k);
    int tries = 1;
    
    while(tries <= _size){
        
        if(_table[p] == EMPTY){
            tallyProbes(tries);
            _table[p] = k;
            return;
        }
        
        if(Hash2(k) != -1) {
            p = (hash(k) + tries * Hash2(k)) % _size;
            tries++;
        } else {
            break;
        }
    }
    
    // Your method should return after it stores the value in an EMPTY slot 
    // and calls tallyProbes, so if it gets here, it didn't find an EMPTY slot 
    _numFailures += 1; 
    cout << "Warning: dinsert(" << k << ") found no EMPTY slot, so no insert was done." << endl; 
}

void Hashtable::print() {
	// Print the content of the hash table.

	for (int i=0; i<_size; i++) {
		cout<<"["<<i<<"] ";
		if (_table[i] != EMPTY)
			cout << _table[i];
		cout << endl;
	}
}

bool Hashtable::checkValue(int k, int i) {
	// Check if value k is at index i. Use this to help you with testing.

	return (_table[i] == k);
}

int Hashtable::nextPrime( int n ) { 
    int loops = (n < 100) ? 100 : n;
    for (int ii = 0; ii < loops; ii++ ){ 
      if ( isPrime( n + ii ) ) return (n + ii); 
    }
    assert( false ); // logic error 
}
bool Hashtable::isPrime( int n ) { 
    if (n < 2) return false; 
    if (n == 2) return true;
    if (n % 2 == 0) return false;  
    return isPrime( n, 3 ); 
}
bool Hashtable::isPrime( int n, int divisor ){ 
    if ((divisor * divisor) > n) return true; 
    if ((n % divisor) == 0) return false; 
    return isPrime( n, divisor + 2 ); 
}

