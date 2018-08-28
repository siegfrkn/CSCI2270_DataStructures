/* Write a function to return the value at nth position in a linked list. Start indexing at zero. The function takes two arguments: the linked list head and the position to search for. The function returns the value at that position. Return -1 if the position is not found. */


int LinkedListNthElement(Element *head, int position){
    
    // create a tmp node so we can iterate through
    Element *tmp = new Element;
    tmp -> next = head;
    tmp -> val = head -> val;
    
    // create a counter and flad
    int counter = 0;
    bool found = false;
    
    // traverse the list
    while (!found && counter<=position && tmp -> next != NULL){
        
        // case 1 - the position is 1
        if (position == 0){
            return tmp -> val;
            found=true;
            break;
        }
        
        // case 2 - the position is elsewhere on the list
        else{
            tmp = tmp -> next;
            if (counter == position){
                found=true;
                break;
            }
            else{
                counter = counter + 1;
            }
        }
        
        //cout << counter << endl;
    }

        if (counter == position){
            return tmp ->val;
        }
        else{
            return -1;
        }
}