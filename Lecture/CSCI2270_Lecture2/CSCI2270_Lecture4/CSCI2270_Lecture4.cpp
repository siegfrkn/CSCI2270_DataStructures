/* SPRINT 4 - Write a function that swaps two integers a,b

int a=3;
int b=5;
int tmp;


void swap(int*a,int*b) {
    int*tmp = new int; // creating a pointer 
    *tmp = *a;
    *a = *b;
    *b = *tmp;
    delete tmp; // always delete the dynamic variables when you are done
}

*/

/* REVIEW OF STRUCT
- collection of data elements
- gives us more flexibility
- complex composite object

struct WeatherData{
	double temp;
	double humidity;
	double windVelocity;
}

struct GarageItem {
	GarageItem(); // instantiate constuctor (needs to have the same name)
	string name;  // new object with type string, i.e. bicycle
	int cost;     // could be int, double, float, etc.
}

now every time I create one I can create by calling:
   GarageItem firsgarageitem; // create a new variable of type GarageItem, generating the first garage item
   firstgarageitem.name = "microwave";
   firstgarageitem.price = 15; // if given a type of int and has a decimal might create a truncation and won't preserve actual data value
   // this could be tedius... we overload the constructor
   // GarageItem(string myName, int myCost);{
      	name = myName;
      	cost = myCost;
      }
      GarageItem.garageitem = [new GarageItem("microwave", 15)


ARRAYS
effectively have to double to expand without dynamic allocation
command line arguments:

int main(int argc, char*argv[])
{
	.... how do we convert to something meaningful?
	remember you are passing as a buffer of chars, need to convert that!
}

In this assignment you will have to pass arguments through the command line
son be sure to implement your int main as above.

Homework, open a file, read it, and store the values in an array
We need to get to a specific spot in the array and compare

ARRAY SORTING
PreCondition is we have an array of stuff
PostCondition we want to have that array of stuff sorted

BubbleSort - slow, does the job, bubble up
InsertionSort - pivot down, more efficient than bubble, more coding
QuickSort - recursion, divide and conquer, more efficient than others on average, complex coding / recursion (perform until I reach
unpredictable end of my unpredictable data, function is invoking itself, have to be really careful b.c. it can create infinite loops)

Quiz Key: nonna