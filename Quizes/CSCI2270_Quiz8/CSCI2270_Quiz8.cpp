void push(int value){
    
    if (stackCounter < maxSize && stackCounter >= 0){
        node *newNode = new node;
        newNode -> next = top;
        newNode -> value = value;
        stackCounter = stackCounter + 1;
        top = newNode;
    }
    
    else if (stackCounter >= maxSize){
        cout << "Overflow" << endl;
    }
    
    else {
        cout << "Underflow" << endl;
    }
    

}

void pop(){

    node *x = nullptr;
    
    if (!isEmpty || stackCounter > 0){
        x = top;
    }
    else{
        cout << "Underflow" << endl;
        top = top;
        return;
    }
    top = top  -> next;
    cout << "Deleted element:" << x -> value <<endl;
    stackCounter = stackCounter - 1;
}

node * DeleteNode(node *head, int value){
    
    // need to create a tmp to traverse the list
    node *tmp = new node;
    tmp -> next = head;
    
    // case 1: head node to be deleted
    while (tmp !=NULL && head -> value == value){
        head = head -> next;
        delete tmp;
        tmp = head;
    }
    
    // case 2+3: middle or end node to be deleted
    while (tmp != NULL){
        node *left = head;
        // create a boolean variable to indicate if we have found the value to delete
        bool found = false;
        tmp= head -> next;
        while (tmp != NULL && !found){
            if (tmp -> value == value){
                left -> next = tmp -> next;
                if (left -> next == NULL){
                    tmp -> next = NULL;
                    found = true;
                }
                delete tmp;
                found = true;
            }
            else{
                left = tmp;
                tmp = tmp -> next;
            }
        }
    }
    
    return head;
}