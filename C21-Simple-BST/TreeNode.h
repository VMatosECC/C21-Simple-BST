#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

template <class T>
struct TreeNode
{
	T		  data;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	bool	  isLeftChild;

	TreeNode(T dataValue) {
		data = dataValue;  	
		parent = left = right = nullptr;  
		isLeftChild = false;
	}

	string toString() {
		ostringstream sout;
		sout << " " << this << " TreeNode[ Parent: " << parent
			<< ", Left: " << left << ", Right: " << right
			<< ", isLeftChild: " << isLeftChild << ", Data: " << data << "]";
		return sout.str();
	}

	friend ostream& operator<< (ostream& os, TreeNode<T>& n) {
		string out = n.toString();  os << n.toString();
		return os;
	}
};
