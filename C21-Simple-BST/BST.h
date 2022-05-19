#pragma once
#include "TreeNode.h"
#include <queue>

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


	void inOrder() { inOrder(root); }

	void inOrder(TreeNode<T>* ptr)
	{
		if (ptr == nullptr) return;

		inOrder(ptr->left);
		cout << ptr->toString() << endl;
		inOrder(ptr->right);
	}



	void postOrder() { postOrder(root); }

	void postOrder(TreeNode<T>* ptr)
	{
		if (ptr == nullptr) return;

		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->toString() << endl;
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
			if (ptr->data == keyData)
				break;
			if (ptr->data < keyData)
				ptr = ptr->right;
			else
				ptr = ptr->left;
				
		}
		return ptr;
	}

	void rowWiseTraversal()
	{
		rowWiseTraversal(root);
	}

	void rowWiseTraversal(TreeNode<T>* ptr)
	{
		if (ptr == nullptr)
		{
			cout << "Tree is empty - nothing to show\n";
			return;
		}

		queue<TreeNode<T>*> q;		
		q.push(ptr);
		while (!q.empty())
		{
			ptr = q.front();
			q.pop();
			cout << ptr->data << ", ";
			if (ptr->left != nullptr) q.push(ptr->left);
			if (ptr->right != nullptr) q.push(ptr->right);
		}
		cout << endl;
	}
};