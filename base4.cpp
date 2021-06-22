#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void convertToBase(int n, vector<int>&); // converts a number to base 4
void printVec(vector<int>); // prints the passed vector to file

ofstream file; // to write output to a file

int main(){

    int n = 0; //given input
    int counter=0;

    file.open("output_for_Rama.txt"); // opens file to output

    cout << endl << "Enter a number of interest: ";
    cin >> n;
    cout << endl;

    file << "IterationNumber,TermValue,Base4" << endl;

    while(n!=1){

        counter++;

        vector<int> baseConvert;

        convertToBase(n,baseConvert);

        file << counter << "," << n << ",";
        printVec(baseConvert);
        file << endl;

        if(n%2==0){
            n = n/2;
        }
        else{
            n = 3*n+1;
        }

    }

    file << counter+1 << ",1,1";

    cout << "Output stored in output_for_Rama.txt" << endl;
    file.close();

}

void convertToBase(int n, vector<int>& baseVec){

    int b;

    while(n != 0){
            b = n%4;
            n = n/4;
            baseVec.insert(baseVec.begin(), b); // adds b to beginning of vector
    }

}

void printVec(vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        file << vec[i];
    }
}