#include "Hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
        
		cout << "Running your test code..." << endl;
		/* ADD YOUR TEST CODE HERE */

         
        m = 7;
        Hashtable H(m);
        
        cout << "*** TESTING QINSERT ***" << endl;
        
        H.print();
        cout << "Inserting 76" << endl;
        H.qinsert(76);
        H.print();
        
        cout << "Inserting 93" << endl;
        H.qinsert(93);
        H.print();
        
        cout << "Inserting 40" << endl;
        H.qinsert(40);
        H.print();
        
        cout << "Inserting 35" << endl;
        H.qinsert(35);
        H.print();
        
        cout << "Inserting 47" << endl;
        H.qinsert(47);
        H.print();
        
        cout << "Inserting 54" << endl;
        cout << "54 follows same pattern as 47 and will fail" << endl;
        cout << "Ie) 54 mod 7 = 47 mod 7" << endl;
        H.qinsert(54);
        H.print();
        
        H.clear();
        cout << "\n*** TESTING LINSERT ***" << endl;
        
        H.print();
        cout << "Inserting 76" << endl;
        H.qinsert(76);
        H.print();
        
        cout << "Inserting 93" << endl;
        H.qinsert(93);
        H.print();
        
        cout << "Inserting 40" << endl;
        H.qinsert(40);
        H.print();
        
        cout << "Inserting 47" << endl;
        H.qinsert(47);
        H.print();
        
        cout << "Inserting 10" << endl;
        H.qinsert(10);
        H.print();
        
        cout << "Inserting 55" << endl;
        H.qinsert(55);
        H.print();

        
        H.clear();
        cout << "\n*** TESTING DINSERT ***" << endl;
        
        H.print();
        cout << "Inserting 76" << endl;
        H.dinsert(76);
        H.print();
        
        cout << "Inserting 93" << endl;
        H.dinsert(93);
        H.print();
        
        cout << "Inserting 40" << endl;
        H.dinsert(40);
        H.print();
        
        cout << "Inserting 47" << endl;
        H.dinsert(47);
        H.print();
        
        cout << "Inserting 10" << endl;
        H.dinsert(10);
        H.print();
        
        cout << "Inserting 55" << endl;
        H.dinsert(55);
        H.print();
        
        
        H.clear();
        m = 1009;
        Hashtable G(m);
        
        cout << "\n*** TESTING QINSERT AVG PROBE WITH LOAD FACTOR < 0.25 ***" << endl;

        for (int i = 0; i < 252; i++){
            int toInsert = rand() + 1;
            G.qinsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING QINSERT AVG PROBE WITH LOAD FACTOR < 0.5 ***" << endl;
        
        for (int i = 0; i < (1009/2); i++){
            int toInsert = rand() + 1;
            G.qinsert(toInsert);
        }
        G.printStats();
        G.clear();

        cout << "\n*** TESTING QINSERT AVG PROBE WITH LOAD FACTOR < 0.75 ***" << endl;
        
        for (int i = 0; i < (1009/4) * 3; i++){
            int toInsert = rand() + 1;
            G.qinsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING QINSERT AVG PROBE WITH LOAD FACTOR < 1 ***" << endl;
        
        for (int i = 0; i < 1009; i++){
            int toInsert = rand() + 1;
            G.qinsert(toInsert);
        }
        G.printStats();
        G.clear();
        
        cout << "\n\n" << endl;

        
        
        
        cout << "\n*** TESTING LINSERT AVG PROBE WITH LOAD FACTOR < 0.25 ***" << endl;
        
        for (int i = 0; i < 252; i++){
            int toInsert = rand() + 1;
            G.linsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING LINSERT AVG PROBE WITH LOAD FACTOR < 0.5 ***" << endl;
        
        for (int i = 0; i < (1009/2); i++){
            int toInsert = rand() + 1;
            G.linsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING LINSERT AVG PROBE WITH LOAD FACTOR < 0.75 ***" << endl;
        
        for (int i = 0; i < (1009/4) * 3; i++){
            int toInsert = rand() + 1;
            G.linsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING LINSERT AVG PROBE WITH LOAD FACTOR < 1 ***" << endl;
        
        for (int i = 0; i < 1009; i++){
            int toInsert = rand() + 1;
            G.linsert(toInsert);
        }
        G.printStats();
        G.clear();
        
        cout << "\n\n" << endl;
        
        
        
        
        cout << "\n*** TESTING DINSERT AVG PROBE WITH LOAD FACTOR < 0.25 ***" << endl;
        
        for (int i = 0; i < 252; i++){
            int toInsert = rand() + 1;
            G.dinsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING DINSERT AVG PROBE WITH LOAD FACTOR < 0.5 ***" << endl;
        
        for (int i = 0; i < (1009 / 2); i++){
            int toInsert = rand() + 1;
            G.dinsert(toInsert);
        }
        G.printStats();
        G.clear();

        cout << "\n*** TESTING DINSERT AVG PROBE WITH LOAD FACTOR < 0.75 ***" << endl;
        
        for (int i = 0; i < (1009/4) * 3; i++){
            int toInsert = rand() + 1;
            G.dinsert(toInsert);
        }
        G.printStats();
        G.clear();

        
        cout << "\n*** TESTING DINSERT AVG PROBE WITH LOAD FACTOR < 1 ***" << endl;
        
        for (int i = 0; i < 1009; i++){
            int toInsert = rand() + 1;
            G.dinsert(toInsert);
        }

        G.printStats();
        G.clear();
        
         
		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
}

