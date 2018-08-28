TreeNode* findMinNode(TreeNode* min){
    TreeNode *current = min;
    while (current -> left != NULL){
        if (current -> key > current -> left -> key){
            current = current -> left;
        }
    }
    //cout << current -> key << endl;
    return current;
}

TreeNode *search(TreeNode *root, int valueToDelete) {
    TreeNode *searchNode = root;
    if (root){
        if (searchNode -> key > valueToDelete && root -> left){
            return search(searchNode -> left, valueToDelete);
        }
        else if (searchNode -> key < valueToDelete && root -> right) {
            return search(searchNode -> right, valueToDelete);
        }
        else if (searchNode -> key == valueToDelete) {
            return searchNode;
        }
        else {
            return NULL;
        }
    }
    return NULL;
}


void deleteAndReplaceMinRight(TreeNode *root, int key){
    TreeNode *nodeToDelete = search(root, key);
    //cout << nodeToDelete -> key << endl;
    TreeNode *minNode = findMinNode(nodeToDelete -> right);
    //cout << minNode -> key << endl;
        
    if (minNode -> key < minNode -> parent -> key){
        nodeToDelete -> key = minNode -> key;
        minNode -> parent -> left = NULL;
    }
    else if (minNode -> key > minNode -> parent -> key){
        nodeToDelete -> right = minNode -> right;
        nodeToDelete -> key = minNode -> key;
        
    }
    //delete nodeToDelete;
    delete minNode;
}