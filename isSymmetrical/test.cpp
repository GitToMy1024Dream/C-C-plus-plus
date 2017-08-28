#include <iostream>
using namespace std;

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};

class Solution
{
public:

	bool _isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}
	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL && pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (pRoot1->_value != pRoot2->_value)
			return false;
		return isSymmetrical(pRoot1->_left, pRoot2->_right) &&
			isSymmetrical(pRoot1->_right, pRoot2->_left);
	}

};