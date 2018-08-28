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