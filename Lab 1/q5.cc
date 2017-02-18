#include <iostream>
#include <stdlib.h>
#include <time.h>

int random_gen();
bool guess_check(int num);

int randNum = random_gen();


int main(void){
    
    int guess;
    std::cout << "Guess a number: " << std::endl;
    std::cin >> guess;
    while(!guess_check(guess)){
        std::cout << "Please guess again: " << std::endl;
        std::cin >> guess;
    }
    
    std::cout << "You guessed right! The number was: " << randNum << std::endl;
    return 0;
}


int random_gen(){
    srand(time(NULL));
    return rand()%(101);
}


bool guess_check(int num){
    
    return num == ::randNum;
}





