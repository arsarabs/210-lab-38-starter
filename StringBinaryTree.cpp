// Implementation file for the IntBinaryTree class

#include "StringBinaryTree.h"

// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by 
// the TreeNode pointer. This function is called recursively.
void StringBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
   if (!nodePtr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

// insertNode creates a new node to hold num as its value,
// and passes it to the insert function.                  
void StringBinaryTree::insertNode(const string& str) {
    TreeNode* newNode = new TreeNode(str); // creates new node

   // Insert the node.
   insert(root, newNode);
}

// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.                
void StringBinaryTree::destroySubTree(TreeNode *nodePtr) {
   if (nodePtr) {
         destroySubTree(nodePtr->left);
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   

// searchNode determines if a value is present in  
// the tree. If so, the function returns true.     
// Otherwise, it returns false.                    
bool StringBinaryTree::searchNode(const string &str) const{
   TreeNode *nodePtr = root;

   while (nodePtr)    {
      if (str == nodePtr->value)
         return true;
      else if (str < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

// remove calls deleteNode to delete the      
// node whose value member is the same as num.
void StringBinaryTree::remove(const string& str) {
   deleteNode(str, root);
}

// deleteNode deletes the node whose value 
// member is the same as num.              
void StringBinaryTree::deleteNode(const string& str, TreeNode *&nodePtr) {

    if (!nodePtr) {
        cout << "Error: \"" << str << "\" not found in the BST.\n";
        return; // Value not found; nothing to delete.
    }

   if (str < nodePtr->value)
      deleteNode(str, nodePtr->left);
   else if (str > nodePtr->value)
      deleteNode(str, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


// makeDeletion takes a reference to a pointer to the node 
// that is to be deleted. The node is removed and the      
// branches of the tree below the node are reattached.     
void StringBinaryTree::makeDeletion(TreeNode *&nodePtr) {
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;


   // Case 1 - No child (Leaf Node)
   if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
       delete nodePtr;
       nodePtr = nullptr;
   }
   else if (nodePtr->left == nullptr) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;   // Reattach the left child
      delete tempNodePtr;
   } else if (nodePtr->right == nullptr) {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else {
      // find the in - order successor(smallest value in the right subtree).
       TreeNode* current = nodePtr->right; 
       while (current->left != nullptr) {
           current = current->left;
       }

       //replace node's value with in-order successor's value
       nodePtr->value = current->value;

       // and then delete the in-order successor
       deleteNode(current->value, nodePtr->right);
    
   }
}

// The displayInOrder member function displays the values       
// in the subtree pointed to by nodePtr, via inorder traversal. 
void StringBinaryTree::displayInOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

// The displayPreOrder member function displays the values      
// in the subtree pointed to by nodePtr, via preorder traversal.
void StringBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

// The displayPostOrder member function displays the values     
// in the subtree pointed to by nodePtr, via postorder traversal.
void StringBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
   if (nodePtr) {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

bool StringBinaryTree::modify(const string& oldStr, const string& newStr) {
    if (searchNode(oldStr)) {
        remove(oldStr);
        insertNode(newStr);
        return true;
    }
    return false; // oldStr not found; modification failed.
}