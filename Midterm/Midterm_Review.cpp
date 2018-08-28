TwoArray* populateStruct(string Arr[], int Arr2[], int size){

TwoArray *returnArray = new TwoArray[size];

    for (int i=0; i<size; i++){
        returnArray[i].a1 = Arr[i];
        returnArray[i].a2 = Arr2[i];
    }
    
    return returnArray;
}


void arrayShift(int arr[],int length,int value){

    for (int i=0; i<length; i++){
    
        if (arr[i] == value){
        
            for (int j=i; j<length; j++){
                arr[j] = arr[j+1];
            }
            length = length-1;
            break;
        }
    }
    
    for (int k=0; k<length; k++){
        cout << arr[k] << " ";
    }
}



int searchStruct(Student *StudentArray,string sname,int marks,int size){
   
    bool isFound = false;
    int counter = size;
    
    for (int i=0; i<size; i++){
        
        if (StudentArray[i].name == sname && StudentArray[i].marks > marks){
            isFound = true;
            counter++;
        }
        
        counter--;;
    }
    
    if (isFound == false){
        counter = 0;
    }
    
    return counter;
}



int LinkedListNthNode(node *head, int position){
 
 node *tmp= new node;
 tmp = head;
 
 for (int i=0; i<position; i++){
    
    tmp = tmp -> next;
     
    if (tmp -> next == NULL){
        return -1;
    }
 }
 
    int returnVal = tmp -> value;

    return returnVal;
}



int *CopyArray(int array[], int length, int value){
    
    int *ArrayB = new int[length];
    
    int isFound = 0;
    
    for (int i=0; i< length; i++){
        if (array[i] == value){
            isFound++;
            length = length - 1;
        }
        if (array[i+isFound] != value){
            ArrayB[i] = array[i+isFound];
        }
        else{
            ArrayB[i] = array[i+isFound+1];
        }
    }
    
    return ArrayB;
}



