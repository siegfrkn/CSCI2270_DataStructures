/*
Write a C++ function to delete the given value from the binary search tree. The function takes two arguments, tree node and node value whose left child has to be deleted. 

Also replace the deleted node with maximum value from its right subtree. 


// THIS IS THE CLASS SOLUTION - will need to add edge cases

TreeNode* findMinNode(TreeNode* min){
    TreeNode *current = min;
    if (root){
	    while (current -> left){
	        if (current -> key > current -> left -> key){ // this loop might not be necessary
	            current = current -> left;
	        }
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

// too much logic in this function to justify using recursion
// needs to only serve one purpose to use recursion
void deleteAndReplaceRightMax(TreeNode *root, int key){
	if (!root){
		return;
	}
	TreeNode *foundN = search(root, key);
	if (foudnN) {
		TreeNode * nodeToDelete = found -> left;
	}

	if (nodeToDelete) {
		TreeNode *min = findMinNode(nodeToDelete);
		max -> parent -> right = NULL;
		// just because we "disconnected" minNode, does not mean it is "gone" so we can still access it
		nodeToDelete -> key = min -> key;
		delete min;
	}


}
*/




// WHAT FOLLOWS IS MY OWN SOLUTION
/*
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


void deleteAndReplaceLeftMin(TreeNode *root, int key){
    TreeNode *nodeToDelete = search(root, key);
    if (nodeToDelete -> right -> right && nodeToDelete -> right -> left){
        nodeToDelete = nodeToDelete -> right;
    }
    TreeNode *minNode = findMinNode(nodeToDelete -> left);
    //cout << nodeToDelete -> key << endl;
    //cout << minNode -> key << endl;
    
    if (nodeToDelete -> key == key){
        delete nodeToDelete -> right;
        nodeToDelete -> right = NULL;
        return;
    }
    
    if (minNode -> key < minNode -> parent -> key){
        nodeToDelete -> key = minNode -> key;
        minNode -> parent -> left = NULL;
    }
    else if (minNode -> key > minNode -> parent -> key){
        nodeToDelete -> right = minNode -> right;
        //minNode -> parent -> right = NULL;
        nodeToDelete -> key = minNode -> key;
        
    }
    //delete nodeToDelete;
    delete minNode;
}
*/

/*
// NOTES

- recall for delete and most substitution type functions in BST require
close attention to the order of operations!

- the wider the better because I have less comparisons to make in search

- Balancing
	- node struct and color
	- we can make our object more complex to help us save time later
	- properties
		- root and leaves are black
		- if red then children are black
		- all the paths from n node to leaf == black nodes
	- cannot be two consecutive red nodes!
	- "leaf" nodes don't point to NULL, they point to actual NULL nodes with no values
	this maintains the validity of the red-black tree

	- Rotation is key in balancing BST - rotate around x (very loose pseudocode)
		-leftRotate(x)
		y = x -> right
		// we want to shift y (x->right) to be in x's position, left rotation
		x-> right -> parent = x -> parent
		x -> parent -> right = y
		y -> left -> parent = x
		x -> right = y -> left
		y -> left  = x;
		x -> parent = y
*/

/*
// WILL PROBABLY GIVE EXTRA CREDIT FOR RED BLACK TREES IF WE CREATE OUR OWN CLASS
// CREATING NODES, ROTATION, ETC

BRT Violation Case 1: Red Uncle
- coloring is not correct
- recolor
- move up 2
BST Violation Case 2: Black Uncle
- x is x.parent
- left rotate

*/


// QUIZ KEY: hola