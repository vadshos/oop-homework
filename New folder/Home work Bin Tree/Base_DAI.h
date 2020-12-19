#pragma once
#include "Violation.h"
class Base_DAI
{
public:
	void add(const size_t key, Violation violation);
	void eraseViolation(const size_t key, const size_t index);
	bool isEmpty() const;
	void print() const ;
	void printOne(const size_t& key) const;
	void printDiapason(const size_t* arr) const;
	void clear();
	void searchMaxCountViolation() const;

	~Base_DAI();
private:
	struct Node
	{
		size_t key;
		Violation violation;
		Node* left, * right, * parent;
		Node(const size_t key,Violation violation, Node* left = nullptr, Node* rigth = nullptr, Node* parent = nullptr) : key(key), left(left), right(rigth), parent(parent)
		{
			this->violation = violation;
			
		}

	};
	Node* root = nullptr;
public:
	void editViolation(size_t key, size_t index,std::string name, size_t sumViolation, date date);
	bool find(const size_t& data) const;
private:
	Node* findReturnNode(const size_t key) const;
	void clearHelper(Node* node);
	void printHelper(Node * node) const;
	void printHelperBasik(Node* node) const;
	bool findHelper(Node* node,const size_t& key) const;
};


inline bool Base_DAI::find(const size_t& data) const
{
	Node* node = root;
	return findHelper(node, data);
}


inline Base_DAI::Node* Base_DAI::findReturnNode(size_t key) const
{
	Node* node = root;
	while (node != nullptr) {
		if (node->key == key) {
			break;
		}
		else {
			if (node->key > key) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
	}

	return node;
}

inline Base_DAI::~Base_DAI()
{
	clear();
}

inline void Base_DAI::add(const size_t key, Violation Violation)
{

	Node* addNode = new Node(key, Violation);
	if (isEmpty()) {
		root = addNode;
		return;
	}
	else if (find(key)) {
		Node* node = root;
		while (node != nullptr) {
			if (node->key == key) {
				break;
			}
			else {
				if (node->key > key) {
					node  = node->left;
				}
				else {
					node = node->right;
				}
			}
		}
		node->violation.pushCopy(Violation);
		return;
	}
	bool found = false;
	Node* temp = root;
	while (!found) {
		if (key >= temp->key) {
			if (temp->right == nullptr) {
				temp->right = addNode;
				addNode->parent = temp;
				found = true;
				return;
			}
			else {
				temp = temp->right;
			}
		}
		else {
			if (key < temp->key) {
				if (temp->left == nullptr) {
					temp->left = addNode;
					addNode->parent = temp;
					found = true;
					return;
				}
				else {
					temp = temp->left;
				}
			}
		}

	}
}

inline void Base_DAI::eraseViolation(const size_t key, const size_t index)
{
	if (find(key) ) {
		Node* node = findReturnNode(key);
		if (node->violation.NameViolation.size() <= index) {
			std::string str = node->violation.NameViolation[index];
			node->violation.NameViolation.erase(node->violation.NameViolation.begin()+index);
			node->violation.Date.erase(node->violation.Date.begin() + index);

		}
	}
}

inline bool Base_DAI::isEmpty() const
{
	return root == nullptr;
}

inline void Base_DAI::print() const
{
	printHelper(root);
}

inline void Base_DAI::printOne(const size_t& key) const
{
	if (find(key) ){
		Node* node = findReturnNode(key);
			printHelperBasik(node);
	}
	else {
		std::cout << "Element not found" << std::endl;
	}
	
}

inline void Base_DAI::printDiapason(const size_t* arr) const
{
	for (size_t i = 0; i < sizeof(arr); i++)
	{
		printOne(arr[i]);
	}
}

inline void Base_DAI::clear()
{
	clearHelper(root);
	root = nullptr;
}

inline void Base_DAI::editViolation(size_t key,size_t index ,std::string name, size_t sumViolation, date date)
{
	Node* node = findReturnNode(key);
	if (index <= node->violation.NameViolation.size()) {
		node->violation.NameViolation[index] = name;
		node->violation.Date[index] = date;
		sumViolation = sumViolation;
	}
}

inline void Base_DAI::searchMaxCountViolation() const
{
	Node* node = root;
	Node* max = root;
	while (node != nullptr) {
		
		node = node->left;
		if (node != nullptr) {
			if (max->violation.size < node->violation.size) {
				max = node;
			}
		}
		else {
			break;
		}
		
		node  = node->right;
	}
	printHelperBasik(max);
}

inline void Base_DAI::clearHelper(Node* node)
{
	if (node != nullptr) {
		clearHelper(node->left);
		clearHelper(node->right);
		
	}
}

inline void Base_DAI::printHelper(Node* node) const
{
	if (node != nullptr) {
		printHelper(node->left);
		printHelperBasik(node);
		printHelper(node->right);
	}
}

inline void Base_DAI::printHelperBasik(Node* node) const
{
	std::cout << "Key: " << node->key << std::endl << "Name violation: " << std::endl;
	for (size_t i = 0; i < node->violation.NameViolation.size(); i++)
	{

		std::cout << i + 1 << " . " << node->violation.NameViolation[i] << std::endl << " Date: " << node->violation.Date[i].ShowDate();
	}
	std::cout << "Sum violation: " << node->violation.sumViolation << std::endl;
	std::cout << std::endl;
}

inline bool Base_DAI::findHelper(Node* node, const size_t& key) const
{
	if (node != nullptr) {
		if (node->key == key) {
			return true;
		}
		else {
			if (node->key > key) {
				return findHelper(node->left, key);
			}
			else {
				return findHelper(node->right, key);
			}
		}
	}
	return false;
}


