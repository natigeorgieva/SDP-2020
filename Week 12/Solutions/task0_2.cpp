#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Tree {
	std::string str;

	std::vector<Tree*> children;
};

void printTree(Tree* node, int level = 0) {
	if (node->str != "root") {
		std::string tabs;
		tabs.assign(3 * (level - 1), ' ');

		std::cout << tabs + node->str << std::endl;
	}

	for (Tree* ptr : node->children) {
		printTree(ptr, level + 1);
	}
}

int main() {
	std::string input;

	Tree root;
	root.str = "root";

	Tree* ptr = nullptr;

	std::fstream fstr("hierarchy.txt", std::ios::in);

	while (!fstr.eof()) {
		std::getline(fstr, input);

		ptr = &root;

		while (input.length() != 0) {

			int pos = input.find("->");
			std::string name = input.substr(0, pos);

			bool found = false;

			for (int i = 0; i < ptr->children.size(); i++) {
				if (ptr->children[i]->str == name) {
					ptr = ptr->children[i];
					found = true;
					break;
				}

			}

			if (!found) {
				ptr->children.push_back(new Tree);
				ptr->children.back()->str = name;
				ptr = ptr->children.back();
			}

			if (pos == std::string::npos) break;
			input = input.substr(pos + 2);
		}

	}

	printTree(&root);
}