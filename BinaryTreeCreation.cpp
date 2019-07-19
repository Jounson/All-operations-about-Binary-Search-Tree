// BinaryTreeCreation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct _BinaryTreeNode
{
	int _data;
	struct _BinaryTreeNode* _left;
	struct _BinaryTreeNode* _right;
}BinaryTreeNode;
/*
=====================================================================================//
@func Function:               to traverse a BST(Binary Search Tree)
@func Name:                   InsertDataToBstRecursionVersion
@Type of Return Value:        no return value
@Parameter1:                  BinaryTreeNode* r, replace it with a tree
@Implementation of function:  recursion version
@Statement:
=====================================================================================//
*/
// 二叉树的中序遍历函数/* 中序遍历的顺序：左->根->右 */
void midOrderTraverse(BinaryTreeNode* root)
{
	if (root)
	{	//递归的思想							
		midOrderTraverse(root->_left);//左
		printf("%d ", root->_data);//根
		midOrderTraverse(root->_right);//右
	}
}
/*
=====================================================================================//
@func Function:               to insert a node to the existed BST
@func Name:                   InsertDataToBstRecursionVersion
@Type of Return Value:        no return value
@Parameter1:                  BinaryTreeNode** r, replace it with a tree
@Parameter2:                  int data, the data included by the inserted node
@Implementation of function:  Cycle version
@Statement:
=====================================================================================//
*/
// 二叉搜索树结点插入函数（循环实现）
void InsertDataToBinarySearchTreeCycleVersion(BinaryTreeNode** r, int data)
{
	BinaryTreeNode* t = *r;
	if (*r == NULL)//如果树为空
	{
		*r = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		(*r)->_data = data;
		(*r)->_left = (*r)->_right = NULL;
	}
	else//树不为空
	{
		while (1)
		{
			if (data > t->_data)//插入的数据比树根的数据大
			{
				if (t->_right == NULL)//如果t的右子树为空
				{
					t->_right = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//申请空间
					t->_right->_data = data;//将插入的数据放入t指向的右结点的数据域中
					t->_right->_right = t->_right->_left = NULL;//将t指向的右结点的左指针域和右指针域都置空
					break;//跳出循环，插入结束
				}
				t = t->_right;
			}
			else//插入的数据比树根的数据小
			{
				if (t->_left == NULL)//如果t的左子树为空
				{
					t->_left = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));//申请空间
					t->_left->_data = data;//将插入的数据放入t指向的左结点的数据域中
					t->_left->_left = t->_left->_right = NULL;//将t指向的左结点的左指针域和右指针域都置空
					break;//跳出循环，插入结束
				}
				t = t->_left;
			}
		}
	}
}
/*
=====================================================================================//
@func Function:               to insert a node to the existed BST
@func Name:                   InsertDataToBstRecursionVersion
@Type of Return Value:        no return value
@Parameter1:                  BinaryTreeNode** r, replace it with a tree
@Parameter2:                  int data, the data included by the inserted node
@Implementation of function:  recursion version
@Statement: 
=====================================================================================//
*/
// 二叉搜索树结点插入函数（递归实现）
void InsertDataToBstRecursionVersion(BinaryTreeNode** r, int data)
{
	if (*r == NULL)
	{
		*r = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		(*r)->_data = data;
		(*r)->_left = (*r)->_right = NULL;
	}
	else
	{
		if (data > (*r)->_data)
			InsertDataToBstRecursionVersion(&(*r)->_right, data);
		else
			InsertDataToBstRecursionVersion(&(*r)->_left, data);
	}
}
/*
=====================================================================================//
@函数功能:    在某二叉搜索树中查找某数据
@函数名:      Search_BinarySearchTree_CycleVersion, 二叉搜索树之——查找函数
@返回值类型:  BinaryTreeNode*, 结点指针
@参数1:      BinaryTreeNode* root, 某二叉搜索树
@参数2:      int find, 要查找的int型数据find
@函数实现:    循环方式
=====================================================================================//
*/ 
BinaryTreeNode* Search_BinarySearchTree_CycleVersion(BinaryTreeNode* root,int find)
{
	while (root)//进入循环, 直到找到为止
	{
		if (find == root->_data)
			return root;
		else if (find > root->_data)
			root = root->_right;
		else
			root = root->_left;
	}
	return NULL;
}
/*
=====================================================================================//
@函数功能:    在某二叉搜索树中查找某数据
@函数名:      Search_BinarySearchTree_RecursionVersion, 二叉搜索树之——查找函数
@返回值类型:  BinaryTreeNode*, 结点指针
@参数1:      BinaryTreeNode* root, 某二叉搜索树
@参数2:      int find, 要查找的int型数据find
@函数实现:    递归方式
=====================================================================================//
*/
BinaryTreeNode* Search_BinarySearchTree_RecursionVersion(BinaryTreeNode* root, int find)
{
	if (root)//如果二叉树不为空
	{
		if (find == root->_data)
			return root;
		else if (find > root->_data)
			return Search_BinarySearchTree_RecursionVersion(root->_right, find);
		else
			return Search_BinarySearchTree_RecursionVersion(root->_left, find);
	}
	return NULL;//如果一开始二叉树为空, 直接返回NULL
}
/*
=====================================================================================//
@func Function:               Find the Minimum node of Binary Search Tree 
@func Name:                   getMinNode_From_BinarySearchTree
@Type of Return Value:        (BinaryTreeNode*)
@Parameter1:                  (BinaryTreeNode*) root
@Implementation of function:  Cycle Version
@Statement: the Minimum node locates in the leftmost end of Binary Search Tree 
=====================================================================================//
*/
BinaryTreeNode* getMinNode_From_BinarySearchTree(BinaryTreeNode* root)
{
	if (root)//if the tree is not null, enter into the While Cycle
	{
		while (root->_left)//if the left subtree is not null, enter into the While Cycle
		{
			root = root->_left;
		}
		return root;
	}
	return NULL;//if tree is null
}
/*
=====================================================================================//
@func Function:               Find the Maximum node of Binary Search Tree
@func Name:                   getMaxNode_From_BinarySearchTree
@Type of Return Value:        (BinaryTreeNode*)
@Parameter1:                  (BinaryTreeNode*) root
@Implementation of function:  Cycle Version
@Statement: the Minimum node locates in the rightmost end of Binary Search Tree
=====================================================================================//
*/
BinaryTreeNode* getMaxNode_From_BinarySearchTree(BinaryTreeNode* root)
{
	if (root)//if the tree is not null, enter into the While Cycle
	{
		while (root->_right)//if the left subtree is not null, enter into the While Cycle
		{
			root = root->_right;
		}
		return root;
	}
	return NULL;//if tree is null
}
/*
=====================================================================================//
@func Function:               to get the farther node of some node of BST
@func Name:                   getFatherNode_of_BST
@Type of Return Value:        BinaryTreeNode*(return the farther node of some node)
@Parameter1:                  BinaryTreeNode* root
@Parameter2:                  BinaryTreeNode* child
@Implementation of function:  if else branch
@Statement:
=====================================================================================//
*/
BinaryTreeNode* getFatherNode_of_BST(BinaryTreeNode* root, BinaryTreeNode* child)
{
	static BinaryTreeNode* parent = NULL; //define a static Node to mark the every preNode
	if (root)//if the tree is not null
	{
		if (root->_left == child || root->_right == child)
			parent = root;//ensure every Father node
		getFatherNode_of_BST(root->_left, child);//find the leftmost subtree
		getFatherNode_of_BST(root->_right, child);//find the rightmost subtree
	}
	return parent;
}
/*
=====================================================================================//
@func Function:               delete some Node of Binary search Tree
@func Name:                   deleteNode_Of_BinarySearchTree
@Type of Return Value:        no return value
@Parameter1:                  BinaryTreeNode** r
@Parameter2:                  BinaryTreeNode*  pointToDelete
@Implementation of function:  if else branch
@Statement: 
=====================================================================================//
*/
void deleteNode_Of_BinarySearchTree(BinaryTreeNode** r, BinaryTreeNode* pointToDelete)
{
	BinaryTreeNode* t = *r;
	BinaryTreeNode* parent = NULL;
	BinaryTreeNode* miniRight = NULL;
	/* 情形1: 被删除点的左右子树都为空 */
	if (pointToDelete->_left == NULL && pointToDelete->_right == NULL)
	{
		if (*r == pointToDelete)
		{
			free(t);
			*r = NULL;
			return;
		}
		parent = getFatherNode_of_BST(t, pointToDelete);
		if (pointToDelete == parent->_left)
			parent->_left = NULL;
		else
			parent->_right = NULL;
		free(pointToDelete);
	}
	/* 情形2: 被删除点的左子树不空, 右子树空 */
	else if (pointToDelete->_left != NULL && pointToDelete->_right == NULL)
	{
		if (*r == pointToDelete)
		{
			*r = pointToDelete->_left;
			free(pointToDelete);
			return;
		}
		parent = getFatherNode_of_BST(t, pointToDelete);
		if (pointToDelete == parent->_left)
			parent->_left = pointToDelete->_left;
		else
			parent->_right = pointToDelete->_left;
		free(pointToDelete);
	}
	/* 情形3: 被删除点的左子树空, 右子树不空 */
	else if (pointToDelete->_left == NULL && pointToDelete->_right != NULL)
	{
		if (*r == pointToDelete)
		{
			*r = pointToDelete->_right;
			free(pointToDelete);
			return;
		}
		parent = getFatherNode_of_BST(t, pointToDelete);
		if (pointToDelete == parent->_left)
			parent->_left = pointToDelete->_right;
		else
			parent->_right = pointToDelete->_right;
		free(pointToDelete);
	}
	/* 情形4: 被删除点的左右子树都不为空 */
	else
	{
		miniRight = getMinNode_From_BinarySearchTree(pointToDelete->_right);//to find the mimimum data of the right subtree the node to delete
		pointToDelete->_data = miniRight->_data;
		parent = getFatherNode_of_BST(t, miniRight);
		if (miniRight != pointToDelete->_right)
		{
			parent->_left = miniRight->_right;
		}
		else
		{
			parent->_right = miniRight->_right;
		}
		free(miniRight);
	}
}
/*
=====================================================================================//
@func Function:               destroy the binary search tree
@func Name:                   destroy_BinarySearchTree
@Type of Return Value:        no return value
@Parameter1:                  BinaryTreeNode* r
@Implementation of function:  recursion
@Statement:
=====================================================================================//
*/
void destroy_BinarySearchTree(BinaryTreeNode* r)
{
	if (r)//if the tree is not null
	{
		destroy_BinarySearchTree(r->_left);// first, destroy the left subtree
		destroy_BinarySearchTree(r->_right);//second, destroy the right subtree
		free(r);//third, destroy the tree root, destroy the whole tree
	}
}
int main()
{
	//BinaryTreeNode* root = NULL; /* 这就是一棵空树 */
	//InsertDataToBinarySearchTree(&root, 30); /* 完成树根创建 向空树插入的第一个结点 */
	//InsertDataToBinarySearchTree(&root, 50); /* 插入的第二个结点 */

#if 0
	// 下面是以循环的方式向二叉树里面插入结点
	BinaryTreeNode* root = NULL;
	InsertDataToBinarySearchTree(&root, 30);//插入的第一个点
	InsertDataToBinarySearchTree(&root, 8);
	InsertDataToBinarySearchTree(&root, 15);
	InsertDataToBinarySearchTree(&root, 36);
	InsertDataToBinarySearchTree(&root, 100);
	InsertDataToBinarySearchTree(&root, 32);//插入的最后一个点
	midOrderTraverse(root);//对二叉树进行中序遍历
#endif

#if 1
	// 下面以递归的方式进行插入
	BinaryTreeNode* root = NULL;
	InsertDataToBstRecursionVersion(&root, 30);//插入的第一个点
	InsertDataToBstRecursionVersion(&root, 8);
	InsertDataToBstRecursionVersion(&root, 15);
	InsertDataToBstRecursionVersion(&root, 36);
	InsertDataToBstRecursionVersion(&root, 100);
	InsertDataToBstRecursionVersion(&root, 32);//插入的最后一个点
	midOrderTraverse(root);//对二叉树进行中序遍历
	cout << endl;
#endif

#if 0
	// 下面是查找实现的循环方式实现
	BinaryTreeNode* pfind = Search_BinarySearchTree_CycleVersion(root, 36);
	if (pfind)
		cout << "成功找到了！ " << pfind->_data << endl;
#endif

#if 0
	// 下面是查找的递归方式实现
	BinaryTreeNode* pfind1 = Search_BinarySearchTree_RecursionVersion(root, 17);
	if (pfind1)
		cout << pfind1->_data << endl;
#endif

#if 0
	// 下面查找一下树中的最小结点
	BinaryTreeNode* MinNode = getMinNode_From_BinarySearchTree(root);
	if (MinNode)
		cout << "find  MinNode successfully! " << MinNode->_data << endl;
#endif 

#if 0
	// 下面查找一下树中的最大结点
	BinaryTreeNode* MaxNode = getMaxNode_From_BinarySearchTree(root);
	if (MaxNode)
		cout << "find  MaxNode successfully! " << MaxNode->_data << endl;
#endif

#if 0
	// 下面是查找需要查找的当前结点的父节点的实例
	BinaryTreeNode* pfind1 = Search_BinarySearchTree_RecursionVersion(root, 100);
	BinaryTreeNode* parent1 = getFatherNode_of_BST(root, pfind1);
	BinaryTreeNode* pfind2 = Search_BinarySearchTree_RecursionVersion(root, 32);
	BinaryTreeNode* parent2 = getFatherNode_of_BST(root, pfind2);
	BinaryTreeNode* pfind3 = Search_BinarySearchTree_RecursionVersion(root, 15);
	BinaryTreeNode* parent3 = getFatherNode_of_BST(root, pfind3);
	if (parent1)
		cout << "the Father Node of 100 is " << parent1->_data << endl;
	if (parent2)
		cout << "the Father Node of 32  is " << parent2->_data << endl;
	if (parent3)
		cout << "the Father Node of 15  is " << parent3->_data << endl;
#endif

#if 0
	// 下面一段代码是测试删除叶子节点是否有效
	BinaryTreeNode* pfind = Search_BinarySearchTree_RecursionVersion(root, 100);
	if (pfind)
		cout << "find the point " << pfind->_data << endl;
	deleteNode_Of_BinarySearchTree(&root, pfind);
	cout << "删除后的遍历结果为: ";
	midOrderTraverse(root);
#endif

#if 1
	// 下面一段是测试删除结点的左右有一端为空的情况
	BinaryTreeNode* pfind = Search_BinarySearchTree_CycleVersion(root, 30);
	if (pfind)
		cout << "find the point " << pfind->_data << endl;
	deleteNode_Of_BinarySearchTree(&root, pfind);
	cout << "删除后的遍历结果为: ";
	midOrderTraverse(root);
	
	// 下面几行代码是销毁树测试案例
	destroy_BinarySearchTree(root);
	root = NULL;
	if (root == NULL)
		cout << endl << "the tree has been destroied" << endl;
#endif

	return 0;

}

