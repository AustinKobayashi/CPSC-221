#include <iostream>
#include <ctime>
#include <cstdlib>
//pick a random element
//place it in the correct spot so that everything on left is smaller and right is larger
//do it recursivley on either side of the pivot
//ect..
int * x;
int comps = 0;
void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int randint(int a, int b) {
    return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
    if (a >= b) 
        return;
    
    int p = randint(a,b); // pivot
    swap(x[a], x[p]);
    int m = a;
    int i;
    // in-place partition:
    for (i = a+1; i <= b; i++) {
        if (x[i] < x[a]){
            swap(x[++m], x[i]);
            comps++;
        }
    }
    swap(x[a],x[m]);
    quicksort(a, m-1);
    quicksort(m+1, b);
}

#define NN 1000

int main(int argc, char *argv[]) {
    srand(time(0));
    /*
    // change the following code
    x = new int[NN];
    for (int i=0; i<NN; ++i) {
        x[i] = rand() % NN;
    }
    
    quicksort(0, NN-1);
    
    for (int i=0; i<NN; ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    */
    
    x = new int [NN];
    
    for(int n = 0; n < 100; n++){
        for (int i=0; i<NN; ++i) 
            x[i] = rand() % NN;
        
        quicksort(0, NN-1);
    }
    std::cout << comps / 100 << std::endl;
    delete[] x;
    return 0;
}
