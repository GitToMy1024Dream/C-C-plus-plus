
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
		if (pNode == NULL)//�߽�����
			return NULL;
		TreeLinkNode* pNext = NULL;//������һ��Ҫ���ص����ڵ�
		if (pNode->right != NULL)//����ýڵ���������������������ߵľ�����һ���ڵ�
		{
			TreeLinkNode*pRight = pNode->right;
			while (pRight->left != NULL)
				pRight = pRight->left;

			pNext = pRight;

		}
		else if (pNode->next != NULL)//����ýڵ�û���������Ļ�
		{
			//��һ������ǣ�û�������������������Ǹ��׽ڵ����ڵ㣬��ô������һ��ָ��϶���ָ��˫�׽ڵ�
			TreeLinkNode* pCurrent = pNode;
			TreeLinkNode* pParent = pNode->next;
			while (pParent != NULL && pCurrent == pParent->right)//���˵��û�����������������������׽ڵ���Һ���
			{                                         //�Ǿ�Ҫһֱȥ���������ĸ��׽ڵ㣬֪����ǰ�ڵ��Ǹ��ڵ�����ӣ�Ҳ�Ƿ��ظ��׽ڵ�
				pCurrent = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;//���׽ڵ��������Ҫ�ҵ���һ���ڵ�
		}
		return pNext;

	}
};