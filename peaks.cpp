#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ofstream file; // to write output to a file

int main(){

	file.open("peak_output.txt");
	file << "N,peak,#ofIterations" << endl;

	int n = 1; // the number that will be our upper-bound

	cout << "Enter the largest number to consider: ";
	cin >> n;
	cout << endl << endl;

	for(int i=1; i <=n ; i=i+2){

		file << i << ",";

		int tmp=i; // the temporary number in the Collatz sequence
		int peak=i; // the peak number that we've reached so far
		int counter = 0; // counts the number of iterations

		while(tmp != 1){ // while we are still iterating through Collatz sequence
			
			if(tmp%2==0){ // if tmp is even

				tmp=tmp/2;

			}
			else{ // if tmp is odd

				tmp=3*tmp+1;

			}

			if(peak <= tmp){ // if peak is less than the current tmp...

				peak = tmp; // update the peak value

			}

			counter++;

		}

		// at this point, we are down with the Collatz interation
		
		file << peak << "," << counter << endl; // output the peak


	}


	cout << "Output in peak_output.txt." << endl << endl;

}
