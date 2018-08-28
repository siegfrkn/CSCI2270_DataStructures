// Include libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


struct TreeNode

{

   int key;

   TreeNode *left;

   TreeNode *right;

};


// bool returnVal;

// bool maximum(int value1, int value2){
//     returnVal = false;
//     if (value1 > value2){
//         returnVal = true;
//     }
    
//     return returnVal;
// }

// bool isBST(TreeNode *node){
//     // make the root node
//     TreeNode *root = node;
//     bool tree = true;
    
//     // sanity check
//     if (!root){
//         return false;
//     }
    
//     // is the right child greater than the root?
//     maximum(root -> key, root -> right -> key);
//     if (returnVal == true){
//         tree = false;
//     }
    
//     // is the left child less than the root?
//     maximum(root -> key, root -> left -> key);
//     if (returnVal == false){
//         tree = true;
//     }
    
//     // Now iterate through and check the children on the right side
//     TreeNode *tmp = root -> right;
//     TreeNode *rightChild = tmp -> right;
//     TreeNode *leftChild = tmp -> left;
//     bool left = false;
//     bool right = false;
//     while (rightChild != NULL && leftChild != NULL){
//         // are all the values greater than the root? both should be true (larger)
//         left = maximum(root -> key, leftChild -> key);
//         right = maximum(root -> key, rightChild -> key);
//         if (left == false || right == false){
//             //cout << "root is bigger" << endl;
//             tree = false;
//         }
//         // are the children allocated properly to L and R?
//         left = maximum(tmp -> key, leftChild -> key);
//         right = maximum(tmp -> key, rightChild -> key);
//         if (left == true || right == true){
//             tree = false;
//         }
//         if (tmp -> right != NULL){
//             break;
//         }
//         tmp = tmp -> right;
//         if (tmp -> right != NULL){
//             rightChild = tmp -> right;
//         }
        
//         if (tmp -> left != NULL){
//             leftChild = tmp -> left;
//         }
//         if (tree == false){
//             return false;
//         }
//     }
//     if (leftChild != NULL){
//         left = maximum(root -> key, leftChild -> key);
//         right = maximum (tmp -> key, leftChild -> key);
//         if (left == true || right == false){
//             tree = false;
//         }
//     }

    

//     // Now iterate through and check the children on the left side
//     tmp = root -> left;
//     rightChild = tmp -> right;
//     leftChild = tmp -> left;
//     left = false;
//     right = false;
//     while (rightChild != NULL && leftChild != NULL){
        
//         if (rightChild == NULL || leftChild == NULL){
//             break;
//         }
//         // are all the values less than the root? both should not be true (smaller)
//         left = maximum(root -> key, leftChild -> key);
//         right = maximum(root -> key, rightChild -> key);
//         if (left == false || right == false){
//             tree = false;
//         }
//         // are the children allocated properly to L and R?
//         left = maximum(tmp -> key, leftChild -> key);
//         right = maximum(tmp -> key, rightChild -> key);
//         if (left == false || right == true){
//             tree = false;
//         }
//         if (tmp -> right  == NULL || tmp -> left == NULL){
//                 break;
//         }
//         tmp = tmp -> left;
//         if (tree == 1){
//             return true;
//         }
//     }
//     return tree;
// }


/*

bool returnVal;

bool maximum(int value1, int value2){
    returnVal = false;
    if (value1 > value2){
        returnVal = true;
    }
    
    return returnVal;
}

bool isBST(TreeNode *node){
    // make the root node
    TreeNode *root = node;
    bool tree = true;
    int holder = 0;
    int holder2 = 0;
    bool checkOrder = true;
    
    
    // sanity check
    if (!root){
        return false;
    }
    
    if(root){
        isBST(root -> left);
        cout << root -> key << endl;
        holder = root -> key;
        checkOrder = maximum(holder2, holder);
        if (checkOrder == false){
            tree = false;
            //cout << "check" << endl;
        }
        isBST(root -> right);
        holder2 = root -> right -> key;
        cout << holder2 << endl;

    }
    return tree;
}


int returnVal;

int maximum(int value1, int value2){
    returnVal = false;
    if (value1 > value2){
        returnVal = value1;
    }
    
    return value2;
}

bool isBST(TreeNode *node){
    // make the root node
    TreeNode *root = node;
    bool tree = false;
    int holder = 0;
    //bool checkOrder = true;
    int holder2 = 0;
    int holder3 = 0;
    
    
    // sanity check
    if (!root){
        return false;
    }
    
    if(root){
        isBST(root -> left);
        holder2 = root -> key;
        cout << "h2 " << holder2 << endl;
        //checkOrder = maximum(holder, root -> key);
        //cout << maximum(root -> key, holder) << endl;

        isBST(root -> right);
        holder = root -> key;
        cout << "h1 " << holder << endl;
        holder3 = maximum(holder, holder2);
        cout << "h3 " << holder3 << endl;

        
    }
    
    if (holder2 >= holder3){
        tree = true;
        cout << "tree" << endl;
        }
    return tree;
}




bool isLeftSubLess(Treenode *node, int value){
    if (!node){
        return true;
    }
    if(node -> left-> key > node -> key &&
    isLeftSubLess(node -> left, value) &&
    isLeftSubLess(node -> right, value) &&){
        return true;
    }
    return false;
}

bool isBST(TreeNode *node){
    
    if(!node){
        return true;
    }
    
    isLeftSubLess(node->left, node->key);
    
    if (node -> left && node -> left -> key > node -> key){
        return false;
    }
    if (node -> right && node -> right -> key < node -> key){
        return false;
    }
    
    if(!isBST(node->right) ||!isBST(node->left)){
        return false;
    }
    
    return true;
    
}



bool isLeftSubLess(TreeNode *node, int value){
    if (!node){
        return true;
    }
    if(node -> key < value &&
    isLeftSubLess(node -> left, value) &&
    isLeftSubLess(node -> right, value)){
        return true;
    }
    return false;
}


bool isRightSubLess(TreeNode *node, int value){
    if (!node){
        return true;
    }
    if(node -> key > value &&
    isRightSubLess(node -> left, value) &&
    isRightSubLess(node -> right, value)){
        return true;
    }
    return false;
}



bool isBST(TreeNode *node){
    
    
    if (isLeftSubLess(node->left, node->key) &&
    isRightSubLess(node->left, node->key) &&
    isBST(node->left) && isBST(node->right)){
        return true;
    }
    
    
    return false;
    
}

*/

// keep track of the "parent" node
TreeNode *previous = NULL;

// go through and state the instances where the binary tree would fail to
// exclude non-bst functions
bool isBST(TreeNode *node){
    // define the root so it's easier to understand colloquially
    TreeNode *root = new TreeNode;
    root = node;
    
    // first line is our sanity check, won't proceed if we don't have a root
    if (root != NULL){
        // use recursive function to parse through left child of the node
        // if the left node doesn't meet the criteria below, not a BST
        // remember, left half of the list is LESS THAN
        if (!isBST(root -> left)){
            return false;
        }
        // this is the hear of the comparison
        // if the parent exists and it's key is greater than the root key
        // then it is not a BST - recall the left half is all less than
        if (previous != NULL && previous -> key >= root -> key) {
            return false;
        }
        // "push down" the list
        previous = root;
        // check the right children as well, will return true if BST and false
        // if not
        return isBST(root ->right);
    }
    return true;
}

// was still having a hard time with the method we used in class, so I was able
// to leverage my understanding of recursion in printing a binary tree in order
// to get this to work, but I will come to office hours and see if I can't get
// the "helper" version to work





/* 
bool returnVal;

bool maximum(int value1, int value2){
    returnVal = false;
    if (value1 > value2){
        returnVal = true;
    }
    
    return returnVal;
}

bool isBST(TreeNode *node){
    // make the root node
    TreeNode *root = node;
    bool tree = true;
    
    // sanity check
    if (!root){
        return false;
    }
    
    // is the right child greater than the root?
    maximum(root -> key, root -> right -> key);
    if (returnVal == true){
        tree = false;
    }
    
    // is the left child less than the root?
    maximum(root -> key, root -> left -> key);
    if (returnVal == false){
        tree = true;
    }
    
    // Now iterate through and check the children on the right side
    TreeNode *tmp = root -> right;
    TreeNode *rightChild = tmp -> right;
    TreeNode *leftChild = tmp -> left;
    bool left = false;
    bool right = false;
    while (rightChild != NULL && leftChild != NULL){
        // are all the values greater than the root? both should be true (larger)
        left = maximum(root -> key, leftChild -> key);
        right = maximum(root -> key, rightChild -> key);
        if (left == false || right == false){
            //cout << "root is bigger" << endl;
            tree = false;
        }
        // are the children allocated properly to L and R?
        left = maximum(tmp -> key, leftChild -> key);
        right = maximum(tmp -> key, rightChild -> key);
        if (left == true || right == true){
            tree = false;
        }
        if (tmp -> right != NULL){
            break;
        }
        tmp = tmp -> right;
        if (tmp -> right != NULL){
            rightChild = tmp -> right;
        }
        
        if (tmp -> left != NULL){
            leftChild = tmp -> left;
        }
        if (tree == false){
            return false;
        }
    }
    if (leftChild != NULL){
        left = maximum(root -> key, leftChild -> key);
        right = maximum (tmp -> key, leftChild -> key);
        if (left == true || right == false){
            tree = false;
        }
    }

    

    // Now iterate through and check the children on the left side
    tmp = root -> left;
    rightChild = tmp -> right;
    leftChild = tmp -> left;
    left = false;
    right = false;
    while (rightChild != NULL && leftChild != NULL){
        
        if (rightChild == NULL || leftChild == NULL){
            break;
        }
        // are all the values less than the root? both should not be true (smaller)
        left = maximum(root -> key, leftChild -> key);
        right = maximum(root -> key, rightChild -> key);
        if (left == false || right == false){
            tree = false;
        }
        // are the children allocated properly to L and R?
        left = maximum(tmp -> key, leftChild -> key);
        right = maximum(tmp -> key, rightChild -> key);
        if (left == false || right == true){
            tree = false;
        }
        if (tmp -> right  == NULL || tmp -> left == NULL){
                break;
        }
        tmp = tmp -> left;
        if (tree == 1){
            return true;
        }
    }
    return tree;
}
