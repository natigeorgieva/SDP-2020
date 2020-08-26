#include <iostream>
using namespace std;

struct BTNode
{
	int data;
	BTNode *left;
	BTNode *right;
};

bool deleteLeaves(BTNode* root) {
	if (root->left == nullptr && root->right == nullptr) {
		return true;
	}

	if (deleteLeaves(root->left)) {
		delete root->left;
		root->left = nullptr;
	}

	if (deleteLeaves(root->right)) {
		delete root->right;
		root->right = nullptr;
	}

	return false;

}

int main() {


}