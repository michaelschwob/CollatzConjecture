#include <iomanip>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

int transform(int given); // obtains the Colletz transform from the given integer
int oddRoute(int given); // determines which odd integer outputs the given integer in the Colletz conjecture 

#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main(){

    int num;
    int kI; // keyboard input

    cout << endl << "Enter a number: ";
    cin >> num;
    cout << endl;

    while(!cin.fail()){

        cout << "[" << num << "]";

        for(int i=0; i < 9; i++){
            cout << " < " << num*pow(2,i+1);
            if(oddRoute(num*pow(2,i+1))!=0){
                cout << "__";
            }
        }

        cout << endl;
        int tempnum = oddRoute(num);

        if(oddRoute(num)==0){
            cout << endl << "No odd route.";
        }
        else{
            cout << " |" << endl << " " << tempnum << endl;
            for(int i = 0; i < 9; i++){
                cout << " |" << endl << " " << tempnum*pow(2,i+1);
                if(oddRoute(tempnum*pow(2,i+1)) != 0){ // if the odd route has an element that has be obtained from another odd route, we can obtain that
                    cout << " < " << oddRoute(tempnum*pow(2,i+1));
                }
                cout << endl;
            }
        }

        cout << endl << "Enter a number: ";
        cin >> num;
        cout << endl;

    }

}

int transform(int given){

    if( given%2 == 0 ){ // if the given number is even
        return given/2;
    }
    else{ // if the given number is odd
        return 3*given+1;
    }

}

int oddRoute(int given){

    if( (given-1)%3 == 0 ){ // if the given number can be obtained through the odd route, return the number
        return (given-1)/3;
    }
    else{ // otherwise, return 0
        return 0;
    }

}