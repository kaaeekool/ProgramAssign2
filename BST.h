//***********************************************************************************
// CSCI 3333.03	Spring 2023
// Instructor: Dr. Andres Figueroa
// Programming Assignment 2: Movies Dataset using BST
// Students Name and SID#:
// Karen Velazquez 20386098
//***********************************************************************************

#include <string>
#include <vector>
using namespace std;


struct Node {
    // data fields 
    string titleID;
    string movieTitle;
    string region;

    struct Node *left;  //left child
    struct Node *right;	//right child
};

class BinarySearchTree{
private:
	int numberNodes; // number of nodes in the tree
	Node* root; // root of the tree
	Node* newNode(string id, string title, string region){
		Node* tempNode = new Node;
		tempNode->titleID = id;
		tempNode->movieTitle = title;
		tempNode->region = region;
		tempNode->left = NULL;
		tempNode->right= NULL;
		return tempNode;
	}
public:
	BinarySearchTree();
	void insert(string id, string title, string region, Node* rootNode);
	void inOrder(Node* rootNode);
    	Node* search(string title, Node* rootNode);
	int size();
};

BinarySearchTree::BinarySearchTree(){
	numberNodes = 0;
	root = NULL;
}

void BinarySearchTree::insert(string id, string title, string region, Node* currentNode = NULL){
	if(currentNode == NULL){
        	currentNode = (*this).root;
	}
//COMPLETE THIS FUNCITON WITH YOUR CODE HERE

	// checking if title is before or after root 
	if (title < root->title) {
		root->left = insert(root->left, id, title, region);
	}
	else if (title > root->title) {
		root->right = insert(root->right, id, title, region);
	}

	// same title? checking id 
	if (id < root->title) {
		root->left = insert(root->left, id, title, region);
	}
	else if (id > root->title) {
		root->right = insert(root->right, id, title, region);
	}

	//same title and id? checking the region and placing it alphabetically
	if (region < root->title) {
		root->left = insert(root->left, id, title, region);
	}
	else if (region > root->title) {
		root->right = insert(root->right, id, title, region);
	}
	
	numberNodes++;
	return root;
	
}


void BinarySearchTree::inOrder(Node* currentNode = NULL){
	if (currentNode == NULL){
        	currentNode = (*this).root;
	}
//COMPLETE THIS FUNCITON WITH YOUR CODE HERE
	inOrder(currentNode->left);
	cout << currentNode->id << " " << currentNode->title << " " << currentNode->region << endl;
	inOrder(currentNode->right);
}


Node* BinarySearchTree::search(string title, Node* currentNode = NULL){
	if (currentNode == NULL){
        	currentNode = (*this).root;
	}
	if( title.compare(currentNode->movieTitle) ==  0){
        	return currentNode;
    	}
	else if( title.compare(currentNode->movieTitle) > 0){
	    if( currentNode->right != NULL)
            	return search(title,currentNode->right);
            else{
            	return NULL;
            }

    	}
    	else{
        	if( currentNode->left != NULL)
            		return search(title,currentNode->left);
        	else{
            		return NULL;
        	}
    	}
}

int BinarySearchTree::size()
{
	return numberNodes;
}
