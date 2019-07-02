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

