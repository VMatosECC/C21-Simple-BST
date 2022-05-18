#pragma once
#include "TreeNode.h"

template <class T>
class BST
{
private:
	TreeNode<T>* root = nullptr;
	int          size = 0;

public:
	BST()
	{
	}

	void preOrder() { preOrder(root); }

	void preOrder(TreeNode<T>* ptr)
	{
		if (ptr == nullptr) return;

		cout << ptr->toString() << endl;
		preOrder(ptr->left);
		preOrder(ptr->right);
	}


	void add(T newData)
	{
		TreeNode<T>* newNode = new TreeNode<T>(newData);

		//Is the tree empty
		if (root == nullptr)
		{
			root = newNode;
			size = 1;
			return;
		}

		TreeNode<T>* previous = nullptr;
		TreeNode<T>* ptr = root;
		bool left = true;
		while (ptr != nullptr)
		{
			previous = ptr;
			if (ptr->data < newData)
			{
				ptr = ptr->right;
				left = false;
			}
			else
			{
				ptr = ptr->left;
				left = true;
			}
		}

		//this is the right spot
		newNode->parent = previous;
		newNode->isLeftChild = left;
		if (left)
		{
			previous->left = newNode;
		}
		else
		{
			previous->right = newNode;
		}

	}

	TreeNode<T>* find(T keyData)
	{
		TreeNode<T>* ptr = root;

		while (ptr != nullptr)
		{
			if (ptr->data < keyData)
			{
				ptr = ptr->right;
			}
			else if (ptr->data > keyData)
			{
				ptr = ptr->left;
			}
			else if (ptr->data == keyData)
			{
				return ptr;
			}
		}

		return ptr;
	}
};