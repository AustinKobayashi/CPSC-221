#include <cstdlib> // for atoi
#include <iostream>

void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);


int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
        return -1;
    }
    
    int n = atoi(argv[1]);
    moveDisks(n, "peg A", "peg B", "peg C");
    return 0;
}


void moveDisks(int n, const char* FROM, const char* VIA, const char* TO){
    
    if(n >= 1){
        moveDisks(n-1, FROM, TO, VIA);
        std::cout << "Move disk from " << FROM << " to " << TO << std::endl;
        moveDisks(n-1, VIA, FROM, TO);
    }
}
