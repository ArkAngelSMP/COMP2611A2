#include <iostream>
#include <cstdlib>
#include <fstream>

#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Data.h"
#include <algorithm>
#include <functional>

using namespace std;


BTNode * initBSTFromFile (char fileName[]) {
	
	BTNode * root = NULL;
	
	ifstream inputFile;
	Movie movie;
	int numMovies;
	
	inputFile.open(fileName);
	
	if (!inputFile.is_open()) {
		cout << "Input file " << fileName << " could not be opened. Aborting ..." << endl;
		return root;
	}

	numMovies = 0;
	inputFile >> movie.ID;
		
	while (movie.ID != "END") {
		inputFile >> movie.yearReleased >> movie.duration >> movie.genre >> ws;
		getline (inputFile, movie.title);
		numMovies++;

		root = insertBST (root, movie);
		inputFile >> movie.ID;
	}

	inputFile.close();
	
	cout << numMovies << " movies read from " << fileName << " and stored in BST." << endl;
	
	return root;
}



BTNode * insertBST (BTNode * root, Movie data) {
	
	return NULL;
}



BTNode * containsBST (BTNode * root, string key) {

	return NULL;
}



BTNode * minimumBST (BTNode * root) {

	return NULL;
}



BTNode * maximumBST (BTNode * root) {

	return NULL;
}



BTNode * inOrderSuccessor (BTNode * node) {

	return NULL;	
}



void rangeBST (BTNode * root, string lowerID, string upperID) {
	
	return;
}

void traverse(BTNode* node, int& currentHeight, int& singleChildCount, std::string& minKey, std::string& maxKey) {
    if (node == NULL) {
        return;
    }

    minKey = std::min(minKey, node->data.ID);
    maxKey = std::max(maxKey, node->data.ID);

    if ((node->left == NULL) != (node->right == NULL)) {
        singleChildCount++;
    }

    currentHeight = std::max(currentHeight, 1 + std::max(height(node->left), height(node->right)));

    traverse(node->left, currentHeight, singleChildCount, minKey, maxKey);
    traverse(node->right, currentHeight, singleChildCount, minKey, maxKey);
}
	


void statisticsBST(BTNode *root) {
    if (root == NULL) {
        return;
    }

    int height = 0;
    int singleChildNodes = 0;
    std::string minKey = root->data.ID;
    std::string maxKey = root->data.ID;

    traverse(root, height, singleChildNodes, minKey, maxKey);

    std::cout << "Height of the BST: " << height << std::endl;
    std::cout << "Number of non-terminal nodes with only one child: " << singleChildNodes << std::endl;
    std::cout << "Minimum key: " << minKey << std::endl;
    std::cout << "Maximum key: " << maxKey << std::endl;
}


bool isIsomorphic(BTNode *root1, BTNode *root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->data.ID != root2->data.ID) {
        return false;
    }

    return isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
}


BTNode * deleteBST (BTNode * root, string key) {

	return root; 

}

