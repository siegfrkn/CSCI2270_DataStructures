#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

int iteration = 0;
int *ptrIteration = &iteration; // keep track of the iteration
int *ptrMyArray = NULL; 		// keep track of the size of the array

void quickSort(int *A, int left, int right) {

	// Prepare new values for new iteration 
	*ptrIteration += 1;
	int i = left;
	int j = right;

	
	cout<< "\nEntering # "<<*ptrIteration<< " iteration"<< endl;
	cout<< "------------------------"<< endl;
	cout<< "|   left   |   right   |"<<"    i    |    j    |"<< endl;
	cout<< "|   "<<left<<"   "<<"   |   "<<right<<"    "<<"   |";
	cout<< "    "<<i<<" "<<"   |    "<<j<<" "<<"   |"<< endl;
	cout<< "------------------------"<< endl;

	int pivot = A[(left+right)/2];
	cout<<"Index of PIVOT is "<<(left+right)/2<<endl;
	cout<<"Value of PIVOT is "<<pivot<<endl;
	cout<< "------------------------"<< endl;
	cout<< "| Array current state  |"<< endl;
	cout<< "------------------------"<< endl;
	
	cout<< "Values: ";
	for (int k = 0; k < *ptrMyArray; k++)
	{
		cout<< "| "<<A[k]<<" ";
	}
	cout<< "|\n------------------------"<< endl;
	cout<< "Index:  ";
	for (int k = 0; k < *ptrMyArray; k++)
	{
		cout<< "| "<<k<<" ";
	}
	
	cout<< "|\n------------------------"<< endl;

	while(i <= j)
	{
		
		cout<< "------------------------"<< endl;
		cout<<"ACTION: comparing "<<A[i]<<" and pivot value "<< pivot<<endl;
		cout<<"Is "<<A[i]<<" < "<< pivot<<" ? ";
		
		while(A[i] < pivot)
		{
			getchar();
			cout<< "YES: i -> ->"<<endl;
			i = i+1;
			getchar();
			cout<<"ACTION: comparing "<<A[i]<<" and pivot value "<< pivot<<endl;
			cout<<"Is "<<A[i]<<" < "<< pivot<<" ? ";
		}

		if (A[i] >= pivot)
		{
			getchar();
			cout<< "NO: i is now "<<i<<endl;
		}

		cout<<"\nACTION: comparing "<<A[j]<<" and pivot value "<< pivot<<endl;
		cout<<"Is "<<A[j]<<" > "<< pivot<<" ? ";
		while(A[j] > pivot)
		{
			getchar();
			cout<< "YES:  <- <- j"<<endl;
			j = j-1;
			getchar();
			cout<<"ACTION: comparing "<<A[j]<<" and pivot value "<< pivot<<endl;
			cout<<"Is "<<A[j]<<" > "<< pivot<<" ? ";
		}

		if (A[j] <= pivot)
		{
			getchar();
			cout<< "NO: j is now "<<j<<endl;
		}

		if (i<=j)
		{
			int tmp = A[i];
			cout<<"\nACTION: shifting "<<A[j]<<" in position "<<i<<endl;
			A[i] = A[j];
			cout<<"ACTION: shifting "<<tmp<<" in position "<<j<<endl;
			A[j] = tmp;

			i = i+1;
			j =j-1;
		}
	}

	cout<< endl;

	cout<<"Is left ("<<left<<") < j ("<<j <<") ? ";
	getchar();
	if (left < j)
	{
		cout<< "YES"<<endl;
		cout<<"ACTION: recursive call quickSort(A, left, j) where: "<<endl;
		cout<<"    A    = { ";
		for (int k = 0; k < *ptrMyArray; k++)
		{
			cout<<A[k]<<" ";
		}
		cout<<"}"<<endl;
		cout<<"    left = "<<left<<endl;
		cout<<"    j    = "<<j<<endl;
		getchar();
		quickSort(A, left, j);
	}

	cout<< "NO"<<endl;
	cout<<endl;
	cout<<"Is i ("<<i<<") < right ("<<right <<") ? ";
	getchar();
	if (i < right)
	{
		cout<< "YES"<<endl;
		cout<<"ACTION: recursive call quickSort(A, i, right) where: "<<endl;
		cout<<"    A     =  { ";
		for (int k = 0; k < *ptrMyArray; k++)
		{
			cout<<A[k]<<" ";
		}
		cout<<"}"<<endl;
		cout<<"    i     = "<<left<<endl;
		cout<<"    right = "<<j<<endl;
		getchar();
		quickSort(A, i, right);
	}
}


int main(int argc, char *argv[]){

	/* TO DO:
	 * get values from command line and create the array
	 * to be sorte.
	*/

	int myArray[] = {2, 7, 1, 11};
	cout << argc << endl;
	for(int a=0; a<argc; a++){
		if (sizeof(atoi(argv[a])) == sizeof(int)) { // checking if we 
		cout << "INTEGER"<< endl;
		}
	}

	// we need to convert argc from char to integer
	// stoi (or atoi part of different library)




	// string store;
	// cout << "Enter array values separated by spaces" << endl;
	// getline(cin, store);

	// int arraySize = sizeof(myArray)/sizeof(myArray[0]);
	// //stringstream(store) >> myArray
	// ptrMyArray = &arraySize;

	// // Sort the Array
	// quickSort(myArray, 0, 3);
	// cout<< "NO"<<endl;
	// cout<< "ARRAY SORTED !!"<<endl;
	return 0;

}