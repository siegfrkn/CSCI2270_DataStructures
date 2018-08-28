// QUESTION 1
void doubleTree(TreeNode *node){
    
    TreeNode *newNode = new TreeNode;
    newNode  -> key = node -> key;
    newNode -> right = NULL;
    newNode -> left = NULL;

    if (node){
        if (node -> left) {
            newNode -> left  = node -> left;
            doubleTree(node -> left);
        }
        node -> left = newNode;

        if (node -> right) {

            doubleTree(node -> right);
        }
    }
}

// QUESTION 2
int *printNodesInOrder(TreeNode*nodeToPrint, int *array, int &index, int &count) {
    if (nodeToPrint && count != index){
    if (nodeToPrint -> left) {
        printNodesInOrder(nodeToPrint -> left, array, index, count);
    }
        //cout << nodeToPrint -> key << endl;
        array[count] = nodeToPrint -> key;
        count++;
    if (nodeToPrint -> right) {
        printNodesInOrder(nodeToPrint -> right, array, index, count);
    }
    }
    return array;
}


bool sameValueTree(TreeNode *node1, TreeNode *node2, int *& array1, int *& array2 ){
    
    if (!node1 && !node2){
        return isEqual;
    }
    
    //print in order and compare the two arrays
    int count1 = 0;
    index1 = sizeTree(node1);
    array1 = new int[index1];
    array1= printNodesInOrder(node1, array1, index1, count1);
    
    int count2 = 0;
    index2 = sizeTree(node2);
    array2 = new int[index2];
    array2= printNodesInOrder(node2, array2, index2, count2);
    
   int biggerSize = max(index1, index2);
   if (index1 != index2) {
        isEqual = false;
   }
   else {
       treeSize= index2;
   }
   for (int j=0; j< biggerSize; j++) {
       if (array1[j] != array2[j]) {
           isEqual = false;
           return isEqual;
       }
   }
   return isEqual;

}