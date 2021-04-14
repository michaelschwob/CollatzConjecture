#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct counters{int counter0, counter1;}; // a struct to hold two counters
typedef struct counters Struct;

Struct collatzIterations(int n); // obtains the number of iterations in Collatz conjecture
void convertToBase(int n, int base, vector<int>&); // converts a number to a base
void printVec(vector<int>); // prints the passed vector to console

ofstream file; // to write output to a file

int main(){

    int n = 0; // the number that we go up to
    int baseTo = 0;
    vector<int> base; // will be the input number in the current base
    Struct tmp; // a temporary struct to hold counters

    file.open("output.txt");
    file << "N,Iterations_Until_One,Iterations_Until_Less_Than_N,Base2,Base3,Base4" << endl;

    cout << endl << "Up to which number should I analyze: ";
    cin >> n;
    cout << endl;

    for(int i = 3; i <= n; i=i+2){ // only odd integers

        if(i%100000==0){
            cout << i << " ";
        }

        tmp = collatzIterations(i);

        file << i << ",";
        file << tmp.counter0 << ","; // column 2
        file << tmp.counter1 << ","; // column 3
        base.clear();
        convertToBase(i, 2, base);
        printVec(base);
        base.clear();
        file << ",";
        convertToBase(i, 3, base);
        printVec(base);
        base.clear();
        file << ",";
        convertToBase(i, 4, base);
        printVec(base);
        base.clear();
        file << endl;

    }

    cout << "Output completed in output.txt" << endl << endl;

    return 0;
}

Struct collatzIterations(int n){

    Struct counts;

    int counter0 = 0; // number of iterations until n reaches 1
    int counter1 = 0; // number of iterations until n is less than n

    int originalN = n; // will store the original N

    if(n==1){ // edge case
        counts.counter0 = counter0;
        counts.counter1 = counter1;
        return counts;
    }
    while(n!=1){

        if(n%2 == 0){ // if n is even

            n = n/2;

        }
        else{ // if n is odd

            n = 3*n+1;

        }

        counter0++; // increase counter of iterations to reach 1

        if(n < originalN && counter1 == 0){

            counter1 = counter0; // increase counter of iterations to be less than original n

        }

    }

    counts.counter0 = counter0;
    counts.counter1 = counter1;

    return counts;

}

void convertToBase(int n, int base, vector<int>& baseVec){

    int b;

    while(n != 0){
            b = n%base;
            n = n/base;
            baseVec.insert(baseVec.begin(), b); // adds b to beginning of vector
    }

}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        file << vec[i];
    }
}
