void printPath(city *head)
{
     // sanity check first
     
     cout << "===CURRENT PATH===" << endl;
     
     // simple list traversal and print
     city *printNode = new city;
     printNode = head;
     while (printNode != NULL){
        cout << printNode -> cityName;
        printNode = printNode -> next;
        cout << " -> ";
     }
    if (printNode == NULL){
        cout << "NULL" << endl;
        cout << "==================" << endl;
        return;
    }
}



void transmitMsg(city * head) { 
    // utilizes a queue ADT because it pushes a word in and then pops it out
     ifstream f;
     f.open("messageIn.txt");
     
     // check success
     if (!f.is_open()){
         cout << "error" << endl;
     }
     
     if (head == NULL){
         cout << "empty list" << endl;
         return;
     }
     
     std::string word;
     city*receiver;
     
     while (std::getline(f, word, ' ')){
         //remove the newline from the word if it has a return character
         //word.erase(remove);
         
         
         receiver = head; // restart at top of list each time
         while (receiver !=NULL){
             // set the message
             cout << receiver -> cityName  << " received "  << word << endl;
             receiver = receiver-> next;
         }
     }
     
}



// add city after previous city, return head
city *addCity(city *head, city *previous, string cityName){
    
    city *newCity = new city;
    
    if (head == nullptr){
        newCity -> next = head;
        newCity -> cityName = cityName;
        head = newCity;
        return head;
    }
    
    if (previous ==  nullptr){
        //cout << "previous is null" << endl;
        newCity -> cityName = cityName;
        newCity -> next = head; // point to the start of the list
        head = newCity; // add an elemnt to the start of the list
        return head;
    }
    
    newCity -> next = previous -> next;
    newCity -> cityName = cityName;
    previous -> next = newCity;
    
    return head;
}