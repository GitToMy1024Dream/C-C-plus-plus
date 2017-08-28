
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
}
};
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)//边界条件
			return NULL;
		TreeLinkNode* pNext = NULL;//定义下一个要返回的树节点
		if (pNode->right != NULL)//如果该节点有右子树，右子树最左边的就是下一个节点
		{
			TreeLinkNode*pRight = pNode->right;
			while (pRight->left != NULL)
				pRight = pRight->left;

			pNext = pRight;

		}
		else if (pNode->next != NULL)//如果该节点没有右子树的话
		{
			//第一种情况是，没有右子树，但是有他是父亲节点的左节点，那么他的下一个指针肯定是指向双亲节点
			TreeLinkNode* pCurrent = pNode;
			TreeLinkNode* pParent = pNode->next;
			while (pParent != NULL && pCurrent == pParent->right)//如果说他没有右子树，但是他是他父亲节点的右孩子
			{                                         //那就要一直去往上找他的父亲节点，知道当前节点是父节点的左孩子，也是返回父亲节点
				pCurrent = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;//父亲节点就是我们要找的下一个节点
		}
		return pNext;

	}
};