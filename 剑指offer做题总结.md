# 剑指offer #
## 二维数组中的查找 ##
- 题目描述:在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
- 思路：先拿二维数组的右上角和目标值进行比较，如果右上角大于目标值，就往左移动一列，直到找到他所在的列，然后向下移动，找到它所在的行，时间复杂度：O(row+col);

```
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool found=false;
        int cols=array[0].size();
        int rows=array.size();
        int col=cols-1,row=0;
        while(col>=0&&row<rows)
        {
            if(array[row][col]==target)
            {
                found=true;
                return found;
            }
            else if(array[row][col]>target)
                col--;
            else
                row++;
        }
        return found;
    }
};
```
## 替换空格 ##
- 题目描述：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
- 思路：这里不仅仅要替换掉空格，替换掉后字符串的长度会变大，会涉及到字符串的移动，所以先遍历一遍计算空格的数量以及字符串的大小，计算出新字符串的长度，然后边移动边替换。时间复杂度：O（n）

```
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL||length<=0)
            return;
        int originallength=0;
        int numblank=0;
        int i=0;
        while(str[i]!='\0')
        {
            originallength++;
            if(str[i]==' ')
                numblank++;
            i++;
        }
        int newlength=originallength+numblank*2;
        if(newlength>length)
            return ;
        while(originallength>=0&&newlength>originallength)
        {
            if(str[originallength]==' ')
            {
                str[newlength--]='0';
                str[newlength--]='2';
                str[newlength--]='%';
            }
            else
            {
                str[newlength--]=str[originallength];
            }
            --originallength;
        }
	}
};
```
## 从尾到头打印链表 ##
- 题目描述：输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
- 思路：自然使用链表；

```
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        std::stack<int> s;
        vector<int> ans;
        ListNode* phead=head;
        while(phead!=NULL)
        {
            s.push(phead->val);
            phead=phead->next;
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
```
## 重建二叉树 ##
- 题目描述：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
- 思路：前序遍历的第一个元素就是根节点，然后在中序中找到根节点，根节点恰好把中序分成两部分，左部分是左子树，右部分是右子树，然后迭代找子树的根节点。。。。。。

```
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        TreeNode* root=new TreeNode(pre[0]);
        int tmp=find(vin.begin(),vin.end(),pre[0])-vin.begin();
        if(tmp!=0)//左子树存在
        {
            vector<int> pre_l(pre.begin()+1,pre.begin()+tmp+1);
            vector<int> vin_l(vin.begin(),vin.begin()+tmp);
            root->left=reConstructBinaryTree(pre_l,vin_l);
        }
        if(tmp!=vin.size()-1)//右子树存在
        {
            vector<int> pre_r(pre.begin()+tmp+1,pre.end());
            vector<int> vin_r(vin.begin()+tmp+1,vin.end());
            root->right=reConstructBinaryTree(pre_r,vin_r);
        }
        return root;
    }
};
```

## 用两个栈实现队列 ##
- 题目描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
- 思路：一个栈用来实现入队列，一个栈用来实现出队列。

```
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()<=0)
        {
            while(stack1.size())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ans=stack2.top();
        stack2.pop();
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```
## 旋转数组的最小数字 ##
- 题目描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

```
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int n1=0;
        int n2=rotateArray.size()-1;
        int n_mid=n1;
        while(rotateArray[n1]>=rotateArray[n2])
        {
            if(n2-n1==1)
            {
                n_mid=n2;
                break;
            }
            n_mid=n1+(n2-n1)/2;
            if(rotateArray[n1]==rotateArray[n_mid]&&rotateArray[n2]==rotateArray[n_mid])
                return minorder(rotateArray,n1,n2);
            if(rotateArray[n1]<=rotateArray[n_mid])
                n1=n_mid;
            if(rotateArray[n_mid]<=rotateArray[n2])
                n2=n_mid;
        }
        return rotateArray[n_mid];
    }
    int minorder(vector<int> rotateArray,int n1,int n2)
    {
        int ans=rotateArray[n1];
        for(int i=n1+1;i<=n2;i++)
        {
            if(ans>rotateArray[i])
                ans=rotateArray[i];
        }
        return ans;
    }
};
```
## 斐波那契数列 ##
- 题目描述：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39
- 思路：不用递归。

```
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> v(n+1,0);
        v[1]=1;
        for(int i=2;i<=n;i++)
        {
            v[i]=v[i-1]+v[i-2];
        }
        return v[n];
    }
};
```
- 题目描述:一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

```
class Solution {
public:
    int jumpFloor(int number) {
        if(number==0)
            return 0;
        vector<int> v(number+1,0);
        v[0]=1;
        v[1]=1;
        for(int i=2;i<=number;i++)
        {
            v[i]=v[i-1]+v[i-2];
        }
        return v[number];
    }
};
```
- 题目描述:我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

```
class Solution {
public:
    int rectCover(int number) {
        if(number==0)
            return 0;
        vector<int> ans(number+1,0);
        ans[0]=1;
        ans[1]=1;
        for(int i=2;i<=number;i++)
        {
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans[number];
    }
};
```
## 二进制中1的个数 ##
- 题目描述：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

```
class Solution {
public:
     int  NumberOf1(int n) {
         int ans=0;
         while(n)
         {
             ans++;
             n=(n-1)&n;
         }
         return ans;
     }
};
```
## 数值的整数次方 ##
- 题目描述：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

```
class Solution {
public:
    bool g_InvalidInput=false;
    double Power(double base, int exponent) {
        g_InvalidInput=false;
        if(equal(base,0.0)&&exponent<0)
        {
            g_InvalidInput=true;
            return 0.0;
        }
        unsigned int absexponent=(unsigned int)(exponent);
        if(exponent<0)
            absexponent=(unsigned int)(-exponent);
        double ans=Powerwithabsexponent(base,absexponent);
        if(exponent<0)
            ans=1.0/ans;
        return ans;
    }
    double Powerwithabsexponent(double base,unsigned int exponent)
    {
        double ans=1.0;
        for(int i=1;i<=exponent;i++)
        {
            ans*=base;
        }
        return ans;
    }
    bool equal(double n1,double n2)
    {
        if((n1-n2>-0.0000001)&&(n1-n2<0.0000001))
            return true;
        else 
            return false;
    }
};
```
## 调整数组顺序使奇数位于偶数前面 ##
- 题目描述：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

```
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int n=array.size();
        for(int i=0;i<n;i++)
        {
            if(array[i]%2==0)
            {
                array.push_back(array[i]);
                array.erase(array.begin()+i);
                i--;
                n--;
            }
        }
    }
};
```
## 链表中倒数第k个节点 ##
- 题目描述：输入一个链表，输出该链表中倒数第k个结点。

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0)
            return NULL;
        ListNode* pfHead=pListHead;
        ListNode* psHead=NULL;
        for(unsigned int i=0;i<k-1;i++)
        {
            if(pfHead->next!=NULL)
                pfHead=pfHead->next;
            else
                return NULL;
        }
        psHead=pListHead;
        while(pfHead->next!=NULL)
        {
            pfHead=pfHead->next;
            psHead=psHead->next;
        }
        return psHead;
    }
};
```
## 反转链表 ##
- 题目描述：输入一个链表，反转链表后，输出新链表的表头。

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* reHead=NULL;
        ListNode* pNode=pHead;
        ListNode* pPre=NULL;
        while(pNode)
        {
            ListNode* pNext=pNode->next;
            if(pNext==NULL)
                reHead=pNode;
            pNode->next=pPre;
            pPre=pNode;
            pNode=pNext;
        }
        return reHead;
    }
};
```
## 合并两个排序的链表 ##
- 题目描述：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        else if(pHead2==NULL)
            return pHead1;
        ListNode* ans=NULL;
        if(pHead1->val>pHead2->val)
        {
            ans=pHead2;
            ans->next=Merge(pHead1, pHead2->next);
        }
        else
        {
            ans=pHead1;
            ans->next=Merge(pHead1->next, pHead2);
        }
        return ans;
    }
};
```
## 树的子结构 ##
- 题目描述：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool ans=false;
        if(pRoot1!=NULL&&pRoot2!=NULL)
        {
            if(pRoot1->val==pRoot2->val)
                ans=doesTree1HaveTree2(pRoot1, pRoot2);
            if(!ans)
                ans=HasSubtree(pRoot1->left, pRoot2);
            if(!ans)
                ans=HasSubtree(pRoot1->right, pRoot2);
        }
        return ans;
    }
    bool doesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==NULL)
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val!=pRoot2->val)
            return false;
        return doesTree1HaveTree2(pRoot1->left, pRoot2->left)&&doesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }
};
```
## 二叉树的镜像 ##
- 题目描述：操作给定的二叉树，将其变换为源二叉树的镜像。
- 输入描述:

```
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
```

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot)
            return ;
        if(!pRoot->left&&!pRoot->right)
            return ;
        TreeNode* tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
    }
};
```
## 顺时针打印矩阵 ##
- 题目描述:输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： {{1 2 3 4} {5 6 7 8} {9 10 11 12} {13 14 15 16}} 则依次打印出数1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

```
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.size()==0||matrix[0].size()==0)
            return {};
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0;
        vector<int> ans;
        while(cols>start*2&&rows>start*2)
        {
            PrintMatrixCircle(matrix,cols,rows,start,ans);
            start++;
        }
        return ans;
    }
    void PrintMatrixCircle(vector<vector<int> > matrix,int cols,int rows,int start,vector<int>& ans)
    {
        int endX=cols-1-start;
        int endY=rows-1-start;
        for(int i=start;i<=endX;i++)
        {
            ans.push_back(matrix[start][i]);
        }
        if(start<endY)
        {
            for(int i=start+1;i<=endY;i++)
            {
                ans.push_back(matrix[i][endX]);
            }
        }
        if(start<endX&&start<endY)
        {
            for(int i=endX-1;i>=start;i--)
            {
                ans.push_back(matrix[endY][i]);
            }
        }
        if(start<endX&&start<endY-1)
        {
            for(int i=endY-1;i>=start+1;i--)
            {
                ans.push_back(matrix[i][start]);
            }
        }
    }
};
```
## 包含min函数的栈 ##
- 题目描述：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

```
class Solution {
public:
    void push(int value) {
        m_data.push(value);
        if(m_min.size()==0||value<m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    void pop() {
        m_data.pop();
        m_min.pop();
        
    }
    int top() {
        return m_data.top();
        
    }
    int min() {
        return m_min.top();
    }
    stack<int> m_data;
    stack<int> m_min;
};
```
## 栈的压入、弹出序列 ##
- 题目描述：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

```
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool ans=false;
        int i=0;
        if(!pushV.empty()&&!popV.empty())
        {
            stack<int> s_data;
            
            while(!popV.empty())
            {
                while(s_data.empty()||s_data.top()!=popV.front())
                {
                    if(popV.empty())
                    {
                        break;
                    }
                    s_data.push(pushV[i]);
                    i++;
                }
                s_data.pop();
                popV.erase(popV.begin());
            }
            if(s_data.empty()&&i==pushV.size())
                ans=true;
        }
        return ans;
    }
};
```
## 从上往下打印二叉树 ##
- 题目描述：从上往下打印出二叉树的每个节点，同层节点从左至右打印。

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector <int> ans;
        if(!root)
            return ans;
        deque<TreeNode*> d_treeNode;
        d_treeNode.push_back(root);
        while(d_treeNode.size())
        {
            TreeNode* tmp=d_treeNode.front();
            d_treeNode.pop_front();
            ans.push_back(tmp->val);
            if(tmp->left)
                d_treeNode.push_back(tmp->left);
            if(tmp->right)
                d_treeNode.push_back(tmp->right);
        }
        return ans;
    }
};
```
## 二叉搜索树的后序遍历序列 ##
- 题目描述：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

```
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		int root = sequence.back();
		int i = 0;
		for (; i<sequence.size()-1; i++)
		{
			if (sequence[i]>root)
				break;
		}
		int j = i;
		for (; j<sequence.size()-1; j++)
		{
			if (sequence[j]<root)
				return false;
		}
		bool left = true;
		if (i>0)
		{
			vector<int>s_l(sequence.begin(), sequence.begin() + i);
			left = VerifySquenceOfBST(s_l);
		}
		bool right = true;
		if (i<sequence.size() - 1)
		{
			vector<int>s_r(sequence.begin() + i, sequence.end()-1);
			right = VerifySquenceOfBST(s_r);
		}
		return (left&&right);
	}
};
```
## 二叉树中和为某一值的路径 ##
- 题目描述：输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ans;
        vector<int> tmp;
        if(!root)
            return ans;
        pathcal(root,expectNumber,tmp,ans);
        return ans;
    }
    void pathcal(TreeNode* root,int expectNumber,vector<int> tmp,vector<vector<int>>&ans)
    {
        tmp.push_back(root->val);
        if(!root->left&&!root->right&&root->val==expectNumber)
        {
            ans.push_back(tmp);
            return;
        }
        else if(!root->left&&!root->right&&root->val!=expectNumber)
            return;
        if(root->left)
            pathcal(root->left,expectNumber-root->val,tmp,ans);
        if(root->right)
            pathcal(root->right,expectNumber-root->val,tmp,ans);
    }
};
```
## 复杂链表的复制 ##
- 题目描述：输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

```
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;
        unordered_map<RandomListNode*,RandomListNode*>m;
        RandomListNode* CloneHead=new RandomListNode(pHead->label);
        RandomListNode* curC=CloneHead;
        RandomListNode* cur=pHead->next;
        m[pHead]=curC;
        while(cur)
        {
            curC->next=new RandomListNode(cur->label);
            curC=curC->next;
            m[cur]=curC;
            cur=cur->next;
        }
        curC->next=NULL;
        cur=pHead;
        curC=CloneHead;
        while(cur)
        {
            if(m.find(cur->random)!=m.end())
                curC->random=m[cur->random];
            cur=cur->next;
            curC=curC->next;
        }
        return CloneHead;
    }
};
```
## 二叉搜索树与双向链表 ##
- 题目描述：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* plastHead=NULL;
        ConvertNode(pRootOfTree,&plastHead);
        TreeNode* head=plastHead;
        while(head&&head->left)
            head=head->left;
        return head;
    }
    void ConvertNode(TreeNode* pNode,TreeNode** pLastNodeInList)
    {
        if(!pNode)
            return ;
        TreeNode* pCur=pNode;
        if(pCur->left)
        {
            ConvertNode(pCur->left,pLastNodeInList);
        }
        pCur->left=*pLastNodeInList;
        if(*pLastNodeInList)
            (*pLastNodeInList)->right=pCur;
        *pLastNodeInList=pCur;
        if(pCur->right)
            ConvertNode(pCur->right,pLastNodeInList);
    }
};
```
## 字符串的排序 ##
- 题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

```
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        int n=str.size();
        if(n==0)
            return ans;
        Permutation(str,0,n,ans);
        return ans;
    }
    void Permutation(string str,int i,int num,vector<string>& ans)
    {
        if(i==num)
        {
            if(find(ans.begin(),ans.end(),str)==ans.end())
                ans.push_back(str);
        }
        else
        {
            for(int k=i;k<num;k++)
            {
                char tmp=str[i];
                str[i]=str[k];
                str[k]=tmp;
                
                Permutation(str,i+1,num,ans);
                
                tmp=str[i];
                str[i]=str[k];
                str[k]=tmp;
            }
        }
    }
};
```
## 数组中出现次数超过一半的数字 ##
- 题目描述：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

```
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int,int> m;
        int n=numbers.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(numbers[i])!=m.end())
            {
                m[numbers[i]]++;
            }
            else
            {
                m[numbers[i]]=1;
            }
        }
        for(auto it:m)
        {
            if(it.second>n/2)
            {
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};
```
## 最小的K个数 ##
- 题目描述：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

```
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int,greater<int>> intset;
        intset.clear();
        if(k<1||input.size()<k)
            return {};
        for(int i=0;i<input.size();i++)
        {
            if(intset.size()<k)
                intset.insert(input[i]);
            else
            {
                auto iter=intset.begin();
                if(input[i]<*iter)
                {
                    
                    intset.erase(iter);
                    intset.insert(input[i]);
                }
            }
        }
        vector<int> ans(intset.begin(),intset.end());
        return ans;
    }
};
```
## 连续子数组的最大和 ##
- 题目描述：HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

```
class Solution {
public:
    bool g_InvalidInput=false;
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
        {
            g_InvalidInput=true;
            return 0;
        }
        g_InvalidInput=false;
        int cursum=0;
        int greatsum=0x80000000;
        for(int i=0;i<array.size();i++)
        {
            if(cursum<=0)
                cursum=array[i];
            else 
                cursum+=array[i];
            if(greatsum<cursum)
                greatsum=cursum;
        }
        return greatsum;
    }
};
```
## 把数组排成最小的数 ##
- 题目描述：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

```
class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        return s1+s2<s2+s1;
    }
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return "";
        vector<string> v_s;
        for(int i=0;i<numbers.size();i++)
            v_s.push_back(to_string(numbers[i]));
        sort(v_s.begin(),v_s.end(),cmp);
        string ans="";
        for(int i=0;i<v_s.size();i++)
            ans+=v_s[i];
        return ans;
    }
};
```
## 第一次只出现一次的字符 ##
- 题目描述：在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）

```
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        const int tablesize=256;
        unsigned int hashtable[tablesize];
        for(unsigned int i=0;i<tablesize;i++)
            hashtable[i]=0;
        for(int i=0;i<str.size();i++)
            hashtable[str[i]]++;
        for(int i=0;i<str.size();i++)
        {
            if(hashtable[str[i]]==1)
                return i;
        }
        return -1;
            
    }
};
```
## 丑数 ##
- 题目描述：把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

```
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        int *pUglyNum=new int[index];
        pUglyNum[0]=1;
        int nextUglyIndex=1;
        int *pMultiply2=pUglyNum;
        int *pMultiply3=pUglyNum;
        int *pMultiply5=pUglyNum;
        while(nextUglyIndex<index)
        {
            int min=Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
            pUglyNum[nextUglyIndex]=min;
            while(*pMultiply2*2<=pUglyNum[nextUglyIndex])
                pMultiply2++;
            while(*pMultiply3*3<=pUglyNum[nextUglyIndex])
                pMultiply3++;
            while(*pMultiply5*5<=pUglyNum[nextUglyIndex])
                pMultiply5++;
            nextUglyIndex++;
        }
        int ans=pUglyNum[nextUglyIndex-1];
        delete[] pUglyNum;
        return ans;
    }
    int Min(int n1,int n2,int n3)
    {
        int min=(n1<n2)? n1:n2;
        min=(min<n3)? min:n3;
        return min;
    }
};
```
## 两个链表的第一个公共结点 ##
- 题目描述：输入两个链表，找出它们的第一个公共结点。

```
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unsigned int nlength1=getlength(pHead1);
        unsigned int nlength2=getlength(pHead2);
        int lengthdif=nlength1-nlength2;
        
        ListNode* plistlong=pHead1;
        ListNode* plistshort=pHead2;
        if(nlength2>nlength1)
        {
            lengthdif=nlength2-nlength1;
            ListNode* plistlong=pHead2;
            ListNode* plistshort=pHead1;
        }
        for(int i=0;i<lengthdif;i++)
            plistlong=plistlong->next;
        while(plistlong&&plistshort&&(plistlong!=plistshort))
        {
            plistlong=plistlong->next;
            plistshort=plistshort->next;
        }
        return plistshort;
    }
    int getlength(ListNode* pHead)
    {
        int ans=0;
        ListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            ans++;
            pNode=pNode->next;
        }
        return ans;
    }
};
```
## 数字在排序数组中出现的次数 ##
- 题目描述：统计一个数字在排序数组中出现的次数。 

```
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int ans=0;
        if(data.size()!=0)
        {
            int first=getfirstk(data,k,0,data.size()-1);
            int last=getlastk(data,k,0,data.size()-1);
            if(first>-1&&last>-1)
                ans=last-first+1;
            
        }
        return ans;
    }
    int getfirstk(vector<int> data,int k,int start,int end)
    {
        if(start>end)
            return -1;
        int mid=(start+end)/2;
        int middata=data[mid];
        if(middata==k)
        {
            if((mid>0&&data[mid-1]!=k)||(mid==0))
                return mid;
            else
                end=mid-1;
        }
        else if(middata>k)
            end=mid-1;
        else
            start=mid+1;
        return getfirstk(data,k,start,end);
    }
    int getlastk(vector<int> data,int k,int start,int end)
    {
        if(start>end)
            return -1;
        int mid=(start+end)/2;
        int middata=data[mid];
        if(middata==k)
        {
            if((mid<data.size()-1&&data[mid+1]!=k)||(mid==data.size()-1))
                return mid;
            else
                start=mid+1;
        }
        else if(middata>k)
            end=mid-1;
        else
            start=mid+1;
        return getlastk(data,k,start,end);
    }
};
```
## 二叉树的深度 ##
- 题目描述：输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

```
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        return (left>right)? (left+1):(right+1);
    }
};
```



