# leetcode做题总结 #

## Binary Tree Level Order Traversal ##
- Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
- For example:
Given binary tree 

```
[3,9,20,null,null,15,7],
	3
   / \
  9  20
    /  \
   15   7
```
return its level order traversal as:
```
[
  [3],
  [9,20],
  [15,7]
]
```
- 思路：层序用队列，这种思想是广度优先搜索。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> ans_cur;
        queue<TreeNode*> ans_next;
        vector<vector<int>>ans;
        vector<int>tmp;
        ans_cur.push(root);
        while(!ans_cur.empty()||!ans_next.empty())
        {
            tmp.push_back(ans_cur.front()->val);
            if(ans_cur.front()->left)
                ans_next.push(ans_cur.front()->left);
            if(ans_cur.front()->right)
                ans_next.push(ans_cur.front()->right);
            ans_cur.pop();
            if(ans_cur.empty())
            {
                ans.push_back(tmp);
                tmp.clear();
                swap(ans_cur,ans_next);
            }
        }
        return ans;
    }
};
```

## Binary Tree Preorder Traversal ##
- Given a binary tree, return the preorder traversal of its nodes' values.
- Example:

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
```
- Follow up: Recursive solution is trivial, could you do it iteratively?
- 思路：递归。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;
        preorder(ans, root);
        return ans;
    }
    void preorder(vector<int> &ans, TreeNode* root)
    {
        if(!root)
            return ;
        ans.push_back(root->val);
        preorder(ans, root->left);
        preorder(ans, root->right);
    }
};
```

## Binary Tree Inorder Traversal ##
- Given a binary tree, return the inorder traversal of its nodes' values.
- Example:

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
```
- 思路：递归

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        INO(root,ans);
        return ans;
    }
    void INO(TreeNode* root,vector<int>& ans)
    {
        if(root)
        {
            INO(root->left,ans);
            ans.push_back(root->val);
            INO(root->right,ans);
        }
    }
};
```
## Unique Binary Search Trees ##
- Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
- Example:

```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```
- 思路：动态规划。思路：空树和只有根节点时，也为BST。对于一点i，当其为根节点时，左子树的节点的个数为i-1，（为1,...i-1）,右子树的个数为n-i（为，i+1,...n）。对一个根来说，唯一二叉树的个数为左子树结点的个数乘以右子树的个数。而根节点可以从1到n中选择。

```
class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return 1;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)//根节点,可以从1到n中选择。
                dp[i]+=dp[j-1]*dp[i-j];
        }
        return dp[n];
    }
};
```

## Two Sum ##
- Given an array of integers, return indices of the two numbers such that they add up to a specific target.
- You may assume that each input would have exactly one solution, and you may not use the same element twice.
- Example:

```
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
- 思路：两层循环，第二层循环在第一层之后，两个数的和等于目标值就压入。

```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=target-nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(tmp==nums[j])
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag=1;
                    return ans;
                    break;
                    //return vector<int>{i,j}
                }
            }
            if(flag==1)
                break;
        }
        return ans;
    }
};
```
## Validate Binary Search Tree ##
- Given a binary tree, determine if it is a valid binary search tree (BST).
- Assume a BST is defined as follows:
	1. The left subtree of a node contains only nodes with keys less than the node's key.
	2. The right subtree of a node contains only nodes with keys greater than the node's key.
	3. Both the left and right subtrees must also be binary search trees.

- 思路：用递归找到每个节点的上下限，上下限在之前的根节点限制。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {        
        return validbst(root,LONG_MIN,LONG_MAX);
    }
    bool validbst(TreeNode* root,long min,long max)
    {
        if(!root)
            return true;
        if(root->val<=min||root->val>=max)
            return false;
        return validbst(root->left,min,root->val) && validbst(root->right,root->val,max);
    }
};

```

## Unique Binary Search Trees II ##
- Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
- Example:

```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```
- 思路：递归，每一个子树进行构建

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        return generatesubTrees(1,n+1);
    }
    vector<TreeNode*> generatesubTrees(int l,int r)
    {
        vector<TreeNode*> subTrees;
        if(l>=r)
        {
            subTrees.push_back(NULL);
            return subTrees;
        }
        if(l==r-1)
        {
            subTrees.push_back(new TreeNode(l));
            return subTrees;
        }
        for(int i=l;i<r;i++)
        {
            vector<TreeNode*> left_tree=generatesubTrees(l,i);
            vector<TreeNode*> right_tree=generatesubTrees(i+1,r);
            for(int m=0;m<left_tree.size();m++)
            {
                for(int n=0;n<right_tree.size();n++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left_tree[m];
                    root->right=right_tree[n];
                    subTrees.push_back(root);
                }
            }
        }
        
        return subTrees;
    }
    
};

```

## Binary Tree Zigzag Level Order Traversal ##
- Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
- For example:
Given binary tree 

```
[3,9,20,null,null,15,7],
 	3
   / \
  9  20
    /  \
   15   7
```
return its zigzag level order traversal as:
```
[
  [3],
  [20,9],
  [15,7]
]
```

- 思路：按照层序的思路，然后奇偶层分开

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root)
			return{};
		vector<vector<int>> ans;
		deque<TreeNode*> q{ root };
		deque<TreeNode*> q_n;
		int flag = 0;
		while (!q.empty() || !q_n.empty())
		{
			vector<int>tmp;
			deque<TreeNode*> q_empty;
			int n = q.size();
			for (int i = n; i > 0;i--)
			{
				if (flag % 2 == 0)
				{
					tmp.push_back(q[n - i]->val);
					if (q[n - i]->left)
						q_n.push_back(q[n - i]->left);
					if (q[n - i]->right)
						q_n.push_back(q[n - i]->right);
				}
				else
				{
					tmp.push_back(q[i-1]->val);
					if (q[n - i]->left)
						q_n.push_back(q[n - i]->left);
					if (q[n - i]->right)
						q_n.push_back(q[n - i]->right);
				}
				
			}
			swap(q_empty, q);
			flag++;
			ans.push_back(tmp);
			swap(q, q_n);
		}
		return ans;
	}
};
```

## Construct Binary Tree from Preorder and Inorder Traversal ##
- Given preorder and inorder traversal of a tree, construct the binary tree.
- Note:You may assume that duplicates do not exist in the tree.
- For example, given

```
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
```
Return the following binary tree:
```
 	3
   / \
  9  20
    /  \
   15   7
```
- 思路：利用中序遍历和前序遍历的特性，前序遍历的第一个元素一定是根节点，在中序中找到根节点，中序中跟节点左侧的是左子树，右侧的是右子树，前序中，左子树在一起，右子树在一起，这样就分开了，然后递归下去构建整棵树。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty())
            return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        if(preorder.size()==1)
            return root;
        auto it=find(inorder.begin(),inorder.end(),preorder[0]);
        int num=it-inorder.begin();
        
        vector<int> preorder_pre(preorder.begin()+1,preorder.begin()+num+1);
        vector<int> inorder_pre(inorder.begin(),it);
        it++;
        vector<int> preorder_cur(preorder.begin()+num+1,preorder.end());
        vector<int> inorder_cur(it,inorder.end());
        if(!preorder_pre.empty())
            root->left=buildTree(preorder_pre, inorder_pre);
        if(!preorder_cur.empty())
            root->right=buildTree(preorder_cur, inorder_cur);       
        return root;
    }
    
    
};

```

## Construct Binary Tree from Inorder and Postorder Traversal ##
- Given inorder and postorder traversal of a tree, construct the binary tree.
- Note:You may assume that duplicates do not exist in the tree.
- For example, given
```
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
```
Return the following binary tree:
```
    3
   / \
  9  20
    /  \
   15   7
```
- 思路：和上一题一样，后序遍历的最后一个元素是根节点，然后根据根节点在中序中分为左子树和右子树，然后递归下去。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()||postorder.empty())
            return NULL;
        int n=postorder.size();
        TreeNode* root=new TreeNode(postorder[n-1]);
        if(n==1)
            return root;
        auto it=find(inorder.begin(),inorder.end(),postorder[n-1]);
        int num=it-inorder.begin();
        vector<int> inorder_pre(inorder.begin(),it);
        vector<int> postorder_pre(postorder.begin(),postorder.begin()+num);
        it++;
        vector<int> inorder_cur(it,inorder.end());
        vector<int> postorder_cur(postorder.begin()+num,postorder.end()-1);
        
        if(!inorder_pre.empty())
            root->left=buildTree(inorder_pre, postorder_pre);
        if(!inorder_cur.empty())
            root->right=buildTree(inorder_cur, postorder_cur);
        
        return root;
    }
};
```
## Convert Sorted List to Binary Search Tree ##
- Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
- For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
- Example:

```
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```
- 思路：这道题是要求把有序链表转为二叉搜索树，和之前那道 Convert Sorted Array to Binary Search Tree 思路完全一样，只不过是操作的数据类型有所差别，一个是数组，一个是链表。数组方便就方便在可以通过index直接访问任意一个元素，而链表不行。由于二分查找法每次需要找到中点，而链表的查找中间点可以通过快慢指针来操作，可参见之前的两篇博客 Reorder List 和 Linked List Cycle II 有关快慢指针的应用。找到中点后，要以中点的值建立一个数的根节点，然后需要把原链表断开，分为前后两个链表，都不能包含原中节点，然后再分别对这两个链表递归调用原函数，分别连上左右子节点即可。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return new TreeNode(head->val);
        ListNode* slow=head,* fast=head,*last=slow;
        while(fast->next&&fast->next->next)
        {
            last=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        last->next=NULL;
        TreeNode* root=new TreeNode(slow->val);
        if(slow!=head)
            root->left=sortedListToBST(head);
        if(fast!=NULL)
            root->right=sortedListToBST(fast);
        return root;
    }
};
```

## Path Sum II ##
- Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
- Note: A leaf is a node with no children.
- Example:
Given the below binary tree and sum = 22,

```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```
Return:

```
[
   [5,4,11,2],
   [5,8,4,5]
]
```
- 思路：递归。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int>tmp;
        if(!root)
            return ans;
        subpathsum(ans, tmp, root, sum);
        return ans;
    }
    void subpathsum(vector<vector<int>>&ans,vector<int> tmp,TreeNode*root,int sum)
    {
        tmp.push_back(root->val);
        if(!root->left&&!root->right)
        {
            if(root->val==sum)
                ans.push_back(tmp);
            return ;
        }
        sum=sum-root->val;
        if(root->left)
            subpathsum(ans, tmp, root->left, sum);
        if(root->right)
            subpathsum(ans, tmp, root->right, sum);
            
        
    }
};
```

## Flatten Binary Tree to Linked List ##
- Given a binary tree, flatten it to a linked list in-place.
- For example, given the following tree:

```
    1
   / \
  2   5
 / \   \
3   4   6
```
The flattened tree should look like:
```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```
- 思路：这道题要求把二叉树展开成链表，根据展开后形成的链表的顺序分析出是使用先序遍历，那么只要是数的遍历就有递归和非递归的两种方法来求解，这里我们也用两种方法来求解。首先来看递归版本的，思路是先利用DFS的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。代码如下

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return ;
        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);
        if(!root->left&&!root->right)
            return ;
        TreeNode* tmp=root->right;
        root->right=root->left;
        root->left=NULL;
        while(root->right)
            root=root->right;
        root->right=tmp;
    }
};
```
- 例如，对于下面的二叉树，上述算法的变换的过程如下：

```
     1
    / \
   2   5
  / \   \
 3   4   6

     1
    / \
   2   5
    \   \
     3   6
      \    
       4

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
```

## Populating Next Right Pointers in Each Node ##
- You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

```
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```
- Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
- Initially, all next pointers are set to NULL.
- 思路，广度优先遍历，然后每层的next指针指向右元素。

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> q;
        q.push(root);  
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                Node* tmp=q.front();
                q.pop();
                if(i==1)
                    tmp->next=NULL;
                else
                    tmp->next=q.front();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return root;
    }
};
```

## Triangle ##
- Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
- For example, given the following triangle

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
- 思路：这道题给了我们一个二维数组组成的三角形，让我们寻找一条自上而下的路径，使得路径和最短。那么那道题后还是先考虑下暴力破解，我们可以发现如果要遍历所有的路径的话，那可以是阶乘级的时间复杂度啊，OJ必灭之，趁早断了念想比较好。必须要优化时间复杂度啊，题目中给的例子很容易把人带偏，让人误以为贪婪算法可以解题，因为看题例子中的红色数组，在根数字2的下方选小的数字3，在3的下方选小的数字5，在5的下方选小的数字1，每次只要选下一层相邻的两个数字中较小的一个，似乎就能得到答案了。其实是不对的，贪婪算法可以带到了局部最小，但不能保证每次都带到全局最小，很有可能在其他的分支的底层的数字突然变的超级小，但是贪婪算法已经将其他所有分支剪掉了。所以为了保证我们能得到全局最小，动态规划Dynamic Programming还是不二之选啊。其实这道题和 Dungeon Game 非常的类似，都是用DP来求解的问题。那么其实我们可以不新建dp数组，而是直接复用triangle数组，我们希望一层一层的累加下来，从而使得 triangle[i][j] 是从最顶层到 (i, j) 位置的最小路径和，那么我们如何得到状态转移方程呢？其实也不难，因为每个结点能往下走的只有跟它相邻的两个数字，那么每个位置 (i, j) 也就只能从上层跟它相邻的两个位置过来，也就是 (i-1, j-1) 和 (i-1, j) 这两个位置，那么状态转移方程为：

triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j])

我们从第二行开始更新，注意两边的数字直接赋值上一行的边界值，那么最终我们只要在最底层找出值最小的数字，就是全局最小的路径和啦，代码如下：
```
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//int ans=0;
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                    triangle[i][j]+=triangle[i-1][j];
                else if(j==triangle[i].size()-1)
                    triangle[i][j]+=triangle[i-1][j-1];
                else 
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        }
        return *min_element(triangle.back().begin(),triangle.back().end()); 
	}
	
};
```
## Word Ladder ##
- Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
	1. Only one letter can be changed at a time.
	2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
- Note:
	1. Return 0 if there is no such transformation sequence.
	2. All words have the same length.
	3. All words contain only lowercase alphabetic characters.
	4. You may assume no duplicates in the word list.
	5. You may assume beginWord and endWord are non-empty and are not the same.
- Example 1:

```
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
```
- Example 2:

```
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
```

- 思路：当拿到题就懵逼的我们如何才能找到一个科学的探索解题的路径呢，那就是先别去管代码实现，如果让我们肉身解题该怎么做呢？让你将 'hit' 变为 'cog'，那么我们发现这两个单词没有一个相同的字母，所以我们就尝试呗，博主会先将第一个 'h' 换成 'c'，看看 'cit' 在不在字典中，发现不在，那么把第二个 'i' 换成 'o'，看看 'hot' 在不在，发现在，完美！然后尝试 'cot' 或者 'hog'，发现都不在，那么就比较麻烦了，我们没法快速的达到目标单词，需要一些中间状态，但我们怎么知道中间状态是什么。简单粗暴的方法就是brute force，遍历所有的情况，我们将起始单词的每一个字母都用26个字母来替换，比如起始单词 'hit' 就要替换为 'ait', 'bit', 'cit', .... 'yit', 'zit'，将每个替换成的单词都在字典中查找一下，如果有的话，那么说明可能是潜在的路径，要保存下来。那么现在就有个问题，比如我们换到了 'hot' 的时候，此时发现在字典中存在，那么下一步我们是继续试接下来的 'hpt', 'hqt', 'hrt'... 还是直接从 'hot' 的首字母开始换 'aot', 'bot', 'cot' ... 这实际上就是BFS和DFS的区别，到底是广度优先，还是深度优先。讲到这里，不知道你有没有觉得这个跟什么很像？对了，跟迷宫遍历很像啊，你想啊，迷宫中每个点有上下左右四个方向可以走，而这里有26个字母，就是二十六个方向可以走，本质上没有啥区别啊！如果熟悉迷宫遍历的童鞋们应该知道，应该用BFS来求最短路径的长度，这也不难理解啊，DFS相当于一条路走到黑啊，你走的那条道不一定是最短的啊。而BFS相当于一个小圈慢慢的一层一层扩大，相当于往湖里扔个石头，一圈一圈扩大的水波纹那种感觉，当水波纹碰到湖上的树叶时，那么此时水圈的半径就是圆心到树叶的最短距离。脑海中有没有浮现出这个生动的场景呢？
明确了要用BFS，我们可以开始解题了，为了提到字典的查找效率，我们使用HashSet保存所有的单词。然后我们需要一个HashMap，来建立某条路径结尾单词和该路径长度之间的映射，并把起始单词映射为1。既然是BFS，我们需要一个队列queue，把起始单词排入队列中，开始队列的循环，取出队首词，然后对其每个位置上的字符，用26个字母进行替换，如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一。如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。如果循环完成则返回0，参见代码如下：

```
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordset(wordList.begin(),wordList.end());
        unordered_map<string,int> path;
        path.insert(make_pair(beginWord,1));
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            string tmp=q.front();
            q.pop();
            for(int i=0;i<tmp.size();i++)
            {
                string newword=tmp;
                for(char ch='a';ch<='z';ch++)
                {
                    newword[i]=ch;
                    if(wordset.count(newword)&&newword==endWord)
                        return path[tmp]+1;
                    if(wordset.count(newword)&&!path.count(newword))
                    {
                        q.push(newword);
                        path[newword]=path[tmp]+1;
                    }
                }
            }
        }
        return 0;
    }
};
```
## Sum Root to Leaf Numbers ##
- Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
- An example is the root-to-leaf path 1->2->3 which represents the number 123.
- Find the total sum of all root-to-leaf numbers.
- Note: A leaf is a node with no children.
- Example:

```
Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
```
Example 2:

```
Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
```
- 思路：广度优先搜索和深度优先搜索都可以，搜索的每个节点，如果是普通节点就跟新节点的值，如果是叶子节点，就把该节点的值加在结果上，很简单。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        if(!root)
            return ans;
        if(!root->left&&!root->right)
            return root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left)
                {
                    tmp->left->val+=tmp->val*10;
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    tmp->right->val+=tmp->val*10;
                    q.push(tmp->right);
                }
                if(!tmp->left&&!tmp->right)
                {
                    ans+=tmp->val;
                }
            }
        }
        return ans;
    }
};
```
## Surrounded Regions ##
- Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
- A region is captured by flipping all 'O's into 'X's in that surrounded region.
- Example:

```
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
```
- Explanation:

```
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
```
- 这是道关于XXOO的题，有点像围棋，将包住的O都变成X，但不同的是边缘的O不算被包围，刚开始我的思路是DFS遍历中间的O，如果没有到达边缘，都变成X，如果到达了边缘，将之前变成X的再变回来。但是这样做非常的不方便，在网上看到大家普遍的做法是扫面矩阵的四条边，如果有O，则用DFS遍历，将所有连着的O都变成另一个字符，比如$，这样剩下的O都是被包围的，然后将这些O变成X，把$变回O就行了。代码如下：

```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(i==0||i==board.size()-1||j==0||j==board[i].size()-1&&board[i][j]=='O')
                {
                    solveDFS(board,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='$')
                    board[i][j]='O';
                
            }
        }
    }
    void solveDFS(vector<vector<char>>& board,int i,int j)
    {
        if(board[i][j]=='O')
        {
            board[i][j]='$';
            if(i>0&&board[i-1][j]=='O')
                solveDFS(board,i-1,j);
            if(i<board.size()-1&&board[i+1][j]=='O')
                solveDFS(board,i+1,j);
            if(j>0&&board[i][j-1]=='O')
                solveDFS(board,i,j-1);
            if(j<board[i].size()-1&&board[i][j+1]=='O')
                solveDFS(board,i,j+1);
        }
    }
    
};
```

## Clone Graph ##
- Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph. Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
- Example:
![](113_sample.png)

```
Input:
{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

Explanation:
Node 1's value is 1, and it has two neighbors: Node 2 and 4.
Node 2's value is 2, and it has two neighbors: Node 1 and 3.
Node 3's value is 3, and it has two neighbors: Node 2 and 4.
Node 4's value is 4, and it has two neighbors: Node 1 and 3.
```
- 思路：这道无向图的复制问题和之前的 Copy List with Random Pointer 有些类似，那道题的难点是如何处理每个结点的随机指针，这道题目的难点在于如何处理每个结点的 neighbors，由于在深度拷贝每一个结点后，还要将其所有 neighbors 放到一个 vector 中，而如何避免重复拷贝呢？这道题好就好在所有结点值不同，所以我们可以使用 HashMap 来对应原图中的结点和新生成的克隆图中的结点。对于图的遍历的两大基本方法是深度优先搜索 DFS 和广度优先搜索 BFS，这里我们先使用深度优先搜索DFS来解答此题，在递归函数中，首先判空，然后再看当前的结点是否已经被克隆过了，若在 HashMap 中存在，则直接返回其映射结点。否则就克隆当前结点，并在 HashMap 中建立映射，然后遍历当前结点的所有 neihbor 结点，调用递归函数并且加到克隆结点的 neighbors 数组中即可，代码如下：

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>m;
        return DNF(node,m);
    }
    Node* DNF(Node* node,unordered_map<Node*,Node*>&m)
    {
        if(!node)
            return NULL;
        if(m.count(node))
            return m[node];
        Node* clone=new Node(node->val);
        m[node]=clone;
        for(Node* nei:node->neighbors)
        {
            clone->neighbors.push_back(DNF(nei,m));
        }
        return clone;
    }
   
};
```
## Gas Station ##
- There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
- You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
- Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
- Note:
	1. If there exists a solution, it is guaranteed to be unique.
	2. Both input arrays are non-empty and have the same length.
	3. Each element in the input arrays is a non-negative integer.
- Example 1:

```
Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output: 3

Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```
Example 2:

```
Input: 
gas  = [2,3,4]
cost = [3,4,3]

Output: -1

Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```
- 思路一：我的方法比较笨，就是遍历所有可能，成功了就返回下标，不成功就返回-1；

```
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if (gas.empty() || gas.size() != cost.size())
			return -1;
		int i = 0, j, k;
		int tank = 0;
		for (; i<gas.size(); i++)
		{
			tank = 0;
			for (j = i, k = 0; k<=gas.size(); k++)
			{
				//tank=tank+gas[j+k]-cost[];
				if (k == 0)
				{
					tank = tank + gas[j];
				}
				else
				{
					tank = tank - cost[(j + k - 1) % gas.size()];
					if (tank<0)
					{
						break;
					}
					else
					{
						if (k == gas.size())
							return i;

						tank += gas[(j + k) % gas.size()];
					}
				}
				
			}
			
		}
		return -1;
	}
};
```
- 思路二：这道转圈加油问题不算很难，只要想通其中的原理就很简单。我们首先要知道能走完整个环的前提是gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，剩余的gas加上当前的gas再减去cost，看是否大于0，若大于0，则继续前进。当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求。代码如下：

```
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total=0,sum=0,start=0;
        for(int i=0;i<gas.size();i++)
        {
            total+=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
            if(sum<0)
            {
                start=i+1;
                sum=0;
            }
        }
        return total<0? -1:start;
	}
};
```

## Single Number II ##
- Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
- Note:Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
- Example 1:

```
Input: [2,2,3,2]
Output: 3
```
- Example 2:

```
Input: [0,1,0,1,0,1,99]
Output: 99
```

- 思路：int类型为32位的，我把所有的数的每一位加起来，然后对3取余，之后就是出现一次的那个数，因为出现3次的取余后为0；代码为：

```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        
        for(int i=0;i<32;i++)
        {
            int sum=0;
            for(int j=0;j<nums.size();j++)
            {
                sum+=(nums[j]>>i)&1;
            }
            ans|=(sum%3)<<i;
        }
        
        return ans;
    }
};
```
## Copy List with Random Pointer ##
- A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
- Return a deep copy of the list.
- Example 1:

![](1470150906153-2yxeznm.png)

```
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
```
- Note:You must return the copy of the given head as a reference to the cloned list.
- 思路：这道链表的深度拷贝题的难点就在于如何处理随机指针的问题，由于每一个节点都有一个随机指针，这个指针可以为空，也可以指向链表的任意一个节点，如果我们在每生成一个新节点给其随机指针赋值时，都要去遍历原链表的话，OJ 上肯定会超时，所以我们可以考虑用 HashMap 来缩短查找时间，第一遍遍历生成所有新节点时同时建立一个原节点和新节点的 HashMap，第二遍给随机指针赋值时，查找时间是常数级。代码如下：

```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* ans=new Node(head->val,NULL,NULL);
        Node* cur=ans;
        Node* h_cur=head->next;
        unordered_map<Node*,Node*>m;//  <<before  after>>
        m[head]=cur;
        while(h_cur)
        {
            Node* t=new Node(h_cur->val,NULL,NULL);
            cur->next=t;
            cur=cur->next;
            m[h_cur]=cur;
            h_cur=h_cur->next;    
        }
        cur=ans;
        h_cur=head;
        while(h_cur)
        {
            cur->random=m[h_cur->random];
            cur=cur->next;
            h_cur=h_cur->next;
        }
        return ans;
    }
};
```
## Word Break ##
- Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
- Note:
	1. The same word in the dictionary may be reused multiple times in the segmentation.
	2. You may assume the dictionary does not contain duplicate words.
- Example 1:

```
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```
- Example 2:

```
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```
- Example 3:

```
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```
- 思路：这道题其实还是一道经典的DP题目，也就是动态规划Dynamic Programming。DP解法的两大难点，定义dp数组跟找出状态转移方程，先来看dp数组的定义，这里我们就用一个一维的dp数组，其中dp[i]表示范围[0, i)内的子串是否可以拆分，注意这里dp数组的长度比s串的长度大1，是因为我们要handle空串的情况，我们初始化dp[0]为true，然后开始遍历。注意这里我们需要两个for循环来遍历，因为此时已经没有递归函数了，所以我们必须要遍历所有的子串，我们用j把[0, i)范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是dp[j]，范围 [j, i) 就是s.substr(j, i-j)，其中dp[j]是之前的状态，我们已经算出来了，可以直接取，只需要在字典中查找s.substr(j, i-j)是否存在了，如果二者均为true，将dp[i]赋为true，并且break掉，此时就不需要再用j去分[0, i)范围了，因为[0, i)范围已经可以拆分了。最终我们返回dp数组的最后一个值，就是整个数组是否可以拆分的布尔值了，代码如下：

```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        int num=s.size()+1;
        int dp[s.size()+1]={0};
        dp[0]=1;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&wordset.count(s.substr(j,i-j)))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```
```
l 

le e 

lee ee e 

leet 

leetc eetc etc tc c 

leetco eetco etco tco co o 

leetcod eetcod etcod tcod cod od d 

leetcode eetcode etcode tcode code 

T F F F T F F F T 
```
## Linked List Cycle II ##
- Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
- To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
- Note: Do not modify the linked list.
- Example 1:

```
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```
![](circularlinkedlist.png)
- Example 2:

```
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```
![](circularlinkedlist_test2.png)
- Example 3:

```
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```
![](circularlinkedlist_test3.png)
- Follow up:Can you solve it without using extra space?
- 思路：我是首先用了额外的空间，所以做起来很容易，用hash把遍历过的节点存放起来，然后探索下个节点，在hash表就返回。代码如下：

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        unordered_set<ListNode *>s;
        ListNode * cur=head;
        while(cur&&cur->next)
        {
            s.insert(cur);
            if(s.count(cur->next))
                return cur->next;
            cur=cur->next;
        }
        return NULL;
    }
};
```
- 思路二：不建立hash表，用两个指针，一个快指针，一个慢指针。快指针的速度是慢指针的两倍，他们在c点相遇，说明有环存在，此时：2（x+y）=x+y+z+y，可以得到x=z，所以把快指针放在A点，相同速度往下走，会在入口B点相遇。

![](20190604094008.png)

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)
            return NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                fast=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
```
## Reorder List ##
- Given a singly linked list L: L0→L1→…→Ln-1→Ln,
- reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
- You may not modify the values in the list's nodes, only nodes itself may be changed.
- Example 1:

```
Given 1->2->3->4, reorder it to 1->4->2->3.
```
- Example 2:

```
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
```
- 思路：我用了两个容器，一个是队列，一个是栈，先把链表遍历一下，放在容器中，然后从容器中拿数据，构建成要求的链表。代码如下：

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next)
			return;
		stack<ListNode*> s;
		queue<ListNode*> q;
		ListNode* cur=NULL;
		int num = 0;
		while (head)
		{
			s.push(head);
			q.push(head);
			num++;
			head = head->next;
		}
		for (int i = 0; i<(num / 2 + num % 2); i++)
		{
			if (i == 0)
			{
				head = q.front();
				q.pop();
				head->next = s.top();
				cur = head->next;
				s.pop();
				continue;
			}
			if (q.front() == s.top())
			{
				cur->next = q.front();
				cur = cur->next; 
				break;
			}
			else
			{
				cur->next = q.front();
				q.pop();
				cur = cur->next;
				cur->next = s.top();
				s.pop();
				cur = cur->next;
			}
		}
		cur->next = NULL;
		return;
	}
};
```

## LRU Cache ##
- Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
- get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
- put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
- The cache is initialized with a positive capacity.
- Example:

```
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```
- 思路：最小最近内存管理算法。用一个数组维护时间，数组头部的表示最近使用过，尾部表示一直没有使用过的。key-value表示用关联容器，方便取的话用hash_map。代码如下：

```
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
        cur=0;
    }
    
    int get(int key) {
        auto it=find(v.begin(),v.end(),key);
        if(it==v.end())
            return -1;
        v.erase(it);
        v.emplace_back(key);
        return m[key];
    }
    
    void put(int key, int value) {
        if(m[key])
        {
            m[key]=value;
            auto it=find(v.begin(),v.end(),key);
            v.erase(it);
            v.emplace_back(key);
            return ;
        }
        if(cap==cur)
        {
            int p=v.front();
            m[p]=0;
            v.erase(v.begin());
            m[key]=value;
            v.emplace_back(key);
        }
        else
        {
            cur++;
            v.emplace_back(key);
            m[key]=value;
        }
        
    }
    int cap,cur;
    vector<int> v;
    unordered_map<int,int> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

## Insertion Sort List ##
- Sort a linked list using insertion sort.
![](Insertion-sort-example-300px.gif)
- A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
- With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
- Algorithm of Insertion Sort:
	1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
	2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
	3. It repeats until no input elements remain.
- Example 1:

```
Input: 4->2->1->3
Output: 1->2->3->4
```
- Example 2:

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```
- 代码如下：

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* new_head_pre=new ListNode(-1);
        ListNode* new_head_tmp=new_head_pre;
        ListNode* cur=head;
        ListNode* cur_pre=cur;
        while(cur)
        {
            cur_pre=cur->next;
            if(new_head_tmp->next&&new_head_tmp->next->val>cur->val)
                new_head_tmp=new_head_pre;
            while(new_head_tmp->next&&new_head_tmp->next->val<=cur->val)
                new_head_tmp=new_head_tmp->next;
            cur->next=new_head_tmp->next;
            new_head_tmp->next=cur;
            cur=cur_pre;
        }
        return new_head_pre->next;
    }
};
```
## 如何高效产生m个n范围内的不重复随机数 ##
如何产生不重复的随机数？最容易想到的方法，是逐个产生这些随机数，每产生一个，都跟前面的随机数比较如果重复，就重新产生。这是个很笨的方法，且比较次数呈线性增长，越往后次数越多。其实这些比较是多余的，完全可以不进行比较，只要反过来，按顺序产生这些数，但随机产生它们的位置。例如下面产生100个100以内不重复随机数的代码：
```
int a[100];
for(i=0; i<=99; ++i) a[i]=i;
for(i=99; i>=1; --i) swap(a[i], a[rand()%i]);
```
## 给你一个长度为N的链表。N很大，但你不知道N有多大。你的任务是从这N个元素中随机取出k个元素。你只能遍历这个链表一次。你的算法必须保证取出的元素恰好有k个，且它们是完全随机的 ##
蓄水池抽样：先保存前k个元素， 从第k+1个元素开始， 以1/i (i=k+1, k+2,…,N) 的概率选中第i个元素，并随机替换掉一个已保存的记录，这样遍历一次得到k个元素，可以保证完全随机选取。

## Sort List ##
- Sort a linked list in O(n log n) time using constant space complexity.
- Example 1:

```
Input: 4->2->1->3
Output: 1->2->3->4
```

- Example 2:

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```
- 归并排序（又称混合排序）因其可以利用递归来交换数字，天然适合链表这种结构。归并排序的核心是一个 merge() 函数，其主要是合并两个有序链表，那么对于一个无序的链表，如何才能拆分成有序的两个链表呢？我们从简单来想，什么时候两个链表一定都是有序的？就是当两个链表各只有一个结点的时候，一定是有序的。而归并排序的核心其实是分治法 Divide and Conquer，就是将链表从中间断开，分成两部分，左右两边再分别调用排序的递归函数 sortList()，得到各自有序的链表后，再进行 merge()，这样整体就是有序的了。因为子链表的递归函数中还是会再次拆成两半，当拆到链表只有一个结点时，无法继续拆分了，而这正好满足了前面所说的“一个结点的时候一定是有序的”，这样就可以进行 merge 了。然后再回溯回去，每次得到的都是有序的链表，然后进行 merge，直到还原整个长度。这里将链表从中间断开的方法，采用的就是快慢指针，大家可能对快慢指针找链表中的环比较熟悉，其实找链表中的中点同样好使，因为快指针每次走两步，慢指针每次走一步，当快指针到达链表末尾时，慢指针正好走到中间位置.

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else
            {
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1) cur->next=l1;
        if(l2) cur->next=l2;
        return dummy->next;
    }
};
```
## Evaluate Reverse Polish Notation ##
- Evaluate the value of an arithmetic expression in Reverse Polish Notation.
- Valid operators are +, -, *, /. Each operand may be an integer or another expression.
- Note:
 1. Division between two integers should truncate toward zero.
 2. The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

- Example 1:

```
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```
- Example 2:

```
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
```
- Example 3:

```
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```
- 思路：比较简单的，用一个栈容器放数据，遇到运算符就取出两个数据，直到把所有vector遍历。

```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int left,right;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                right=s.top();
                s.pop();
                left=s.top();
                s.pop();
                //int tmp=left+right;
                s.push(left+right);
            }
            else if(tokens[i]=="-")
            {
                right=s.top();
                s.pop();
                left=s.top();
                s.pop();
                //int tmp=left-right;
                s.push(left-right); 
            }
            else if(tokens[i]=="*")
            {
                right=s.top();
                s.pop();
                left=s.top();
                s.pop();
                //int tmp=left*right;
                s.push(left*right);
            }
            else if(tokens[i]=="/")
            {
                right=s.top();
                s.pop();
                left=s.top();
                s.pop();
                //int tmp=left/right;
                s.push(left/right);
            }
            else
            {
                s.push(atoi(tokens[i].c_str()));
            }      
        }
        return s.top();
    }
};
```
## Reverse Words in a String ##
- Given an input string, reverse the string word by word.
- Example 1:

```
Input: "the sky is blue"
Output: "blue is sky the"
```
- Example 2:

```
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```
- Example 3:

```
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```
- 代码如下：

```
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
            return s;
        vector<string> a;
        string ans="";
        string tmp="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                tmp+=s[i];
            }
            else
            {
                if(!tmp.empty())
                {
                    a.push_back(tmp);
                    tmp="";
                }
            }
        }
        if(!tmp.empty())
            a.push_back(tmp);
        for(int i=a.size()-1;i>=0;i--)
        {
            if(i!=0)
            {
                ans=ans+a[i]+" ";
            }
            else
            {
                ans=ans+a[i];
            }
        }
        return ans;
    }
};
```
## Maximum Product Subarray ##
- Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
- Example 1:

```
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```
- Example 2:

```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```
- 思路：一开始我的思路是，暴力搜索，就是把所有的子数组都找到，计算每个子数组的乘积，然后找最大，代码如下：O（n）

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>ans)
                ans=nums[i];
            int tmp=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                tmp=tmp*nums[j];
                if(ans<tmp)
                    ans=tmp;
            }
        }
        return ans;
    }
};
```
- 这样做，时间复杂度太大了，然后有一篇博客，用的是动态规划。其实这道题最直接的方法就是用DP来做，而且要用两个dp数组，其中maxN[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最大子数组乘积，minN[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最小子数组乘积，初始化时maxN[0]和minN[0]都初始化为nums[0]，其余都初始化为0。那么从数组的第二个数字开始遍历，那么此时的最大值和最小值只会在这三个数字之间产生，即maxN[i-1]*nums[i]，minN[i-1]*nums[i]，和nums[i]。所以我们用三者中的最大值来更新maxN[i]，用最小值来更新minN[i]，然后用maxN[i]来更新结果res即可，由于最终的结果不一定会包括nums[n-1]这个数字，所以maxN[n-1]不一定是最终解，不断更新的结果ans才是，参见代码如下：

```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        vector<int> maxN(n,0),minN(n,0);
        maxN[0]=nums[0];
        minN[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            maxN[i]=max(max(maxN[i-1]*nums[i],minN[i-1]*nums[i]),nums[i]);
            minN[i]=min(min(maxN[i-1]*nums[i],minN[i-1]*nums[i]),nums[i]);
            ans=max(ans,maxN[i]);
        }
        return ans;
    }
};
```
## Find Minimum in Rotated Sorted Array ##
- Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.`(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2])`.
- Find the minimum element.
- You may assume no duplicate exists in the array.
- Example 1:

```
Input: [3,4,5,1,2] 
Output: 1
```
- Example 2:

```
Input: [4,5,6,7,0,1,2]
Output: 0
```
- 思路：首先拿第一个数和最后一个数相比较，如果第一个数小于最后一个，说明这个数组是升序，第一个数就是最小值。否则最小值在数组中间某个数，从两边开始搜索，遇到突变的就是最小值出现的地方。时间复杂度O（n/2）.

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        int ans=nums[0],n=nums.size();
        if(nums[n-1]>ans)
            return ans;
        else
        {
            for(int i=1;i<n;i++)
            {
                if(nums[i]<nums[i-1]||nums[n-i-1]>nums[n-i])
                {
                    ans=min(nums[i],nums[n-i]);
                    break;
                }
            }
        }
        return ans;
        
    }
};
```
## Find Peak Element ##
- A peak element is an element that is greater than its neighbors.
- Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
- The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
- You may imagine that nums[-1] = nums[n] = -∞.
- Example 1:

```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```
- Example 2:

```
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2,  or index number 5 where the peak element is 6.
```
- 思路：题目中说了这个峰值可以是局部的最大值，所以我们只需要找到第一个局部峰值就可以了。所谓峰值就是比周围两个数字都大的数字，那么只需要跟周围两个数字比较就可以了。既然要跟左右的数字比较，就得考虑越界的问题，题目中给了nums[-1] = nums[n] = -∞，那么我们其实可以把这两个整型最小值直接加入到数组中，然后从第二个数字遍历到倒数第二个数字，这样就不会存在越界的可能了。由于题目中说了峰值一定存在，那么有一个很重要的corner case我们要注意，就是当原数组中只有一个数字，且是整型最小值的时候，我们如果还要首尾垫数字，就会形成一条水平线，从而没有峰值了，所以我们对于数组中只有一个数字的情况在开头直接判断一下即可，参见代码如下：

```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MIN);
        for (int i = 1; i < (int)nums.size() - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i - 1;
        }
        return -1;
    }
};
```
## Compare Version Numbers ##
- Compare two version numbers version1 and version2.
- If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
- You may assume that the version strings are non-empty and contain only digits and the . character.
- The . character does not represent a decimal point and is used to separate number sequences.
- For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
- You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.
- Example 1:

```
Input: version1 = "0.1", version2 = "1.1"
Output: -1
```
- Example 2:

```
Input: version1 = "1.0.1", version2 = "1"
Output: 1
```
- Example 3:

```
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
```
- Example 4:

```
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
```
- Example 5:

```
Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
```
- 思路：我首先是把两个字符串用‘.’进行分割，然后挨着对比的，代码如下：

```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1=slipstring(version1);
        vector<int> v2=slipstring(version2);
        int m1=v1.size();
        int m2=v2.size();
        int m=0;
        if(m1<m2)
        {
            for(int i=0;i<(m2-m1);i++)
                v1.push_back(0);
            m=m2;
        }
        else if(m1>m2)
        {
            for(int i=0;i<(m1-m2);i++)
                v2.push_back(0);
            m=m1;
        }
        else
        {
            m=m1;
        }
        for(int i=0;i<m;i++)
        {
            if(v1[i]>v2[i])
                return 1;
            else if(v1[i]<v2[i])
                return -1;
        }
        return 0;
    }
    vector<int> slipstring(string version)
    {
        string tmp="";
        vector<int> ans;
        for(int i=0;i<version.size();i++)
        {
            if(version[i]=='.')
            {
                ans.push_back(atoi(tmp.c_str()));
                tmp="";
            }
            else
            {
                tmp+=version[i];
            }
            if(i==version.size()-1)
                ans.push_back(atoi(tmp.c_str()));
        }
        return ans;
    }
};
```
## Fraction to Recurring Decimal ##
- Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
- If the fractional part is repeating, enclose the repeating part in parentheses.
- Example 1:

```
Input: numerator = 1, denominator = 2
Output: "0.5"
```
- Example 2:

```
Input: numerator = 2, denominator = 1
Output: "2"
```
- Example 3:

```
Input: numerator = 2, denominator = 3
Output: "0.(6)"
```
- 思路：设计的内容挺多的，负数的处理，INT_MIN的处理，将INT_MIN转化为正数会溢出，因此要使用long long int来计算。重点在于小数部分的处理，因为小数部分有可能会出现循环。所以我们可以设置一个哈希表，存储每一次的余数，以及该余数在返回结果ans中的下标。每一次得到新的余数，就查询该余数是否已经在哈希表中，是的话说明开始循环了，那么直接在ans中该余数对应的位置后面插入‘（’，ans末尾加上‘）’，结束运算。如果在哈希表中没找到，则继续正常运运算。代码如下：

```
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if(numerator==0)
            return "0";
        string ans = "";
		int flag = 0;
		unordered_map<int, int> m;
		if (numerator<0 ^ denominator<0) ans += '-';
		long long int n = numerator;
		n = abs(n);
		long long int d = denominator;
		d = abs(d);
		while (n)
		{
			long long int numerator_1 = n;
			int num = 0;
			while (numerator_1<d && (flag == 0))
			{
				num++;
				
				if (ans == ""||ans=="-")
					ans += "0.";
				else
					ans += ".";
				m[numerator_1] = ans.size();
				numerator_1 *= 10;
				flag = 1;
			}
			while (numerator_1<d)
			{
				if (m.find(numerator_1) != m.end())
				{
					ans.insert(m[numerator_1], 1, '(');

					ans = ans + ")";
					numerator_1 = 0;
					break;
				}
				
				num++;
				if (num >= 2)
					ans += '0';
				m[numerator_1] = ans.size();
				numerator_1 *= 10;
			}
			if (numerator_1 == 0)
				break;
			string tmp_s = to_string(numerator_1 / d);
			int tmp_i = numerator_1%d;
			ans = ans + tmp_s;
			n = tmp_i;
			
		}
		return ans;
	}
};
```
## Binary Search Tree Iterator ##
- Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
- Calling next() will return the next smallest number in the BST.
- Example:
![](Binary_Search_Tree_Iterator.png)
```
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false
```
- Note:
	1. next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
	2. You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.

- 思路：我的思路是：使用容器，因为要顺序打印，所以先把树进行中序迭代，迭代效果放在容器中，然后一个一个的取。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        order(root);
        i=0;
    }
    
    /** @return the next smallest number */
    int next() {
        return v[i++];
        
        //cout<<i<<endl;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i<v.size()? true:false;
    }
    vector<int> v;
    int i;
    void order(TreeNode* root)
    {
        if(root)
        {
            
            order(root->left);
            v.push_back(root->val);
            order(root->right);
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```
## Largest Number ##
- Given a list of non negative integers, arrange them such that they form the largest number.
- Example 1:

```
Input: [10,2]
Output: "210"
```
- Example 2:

```
Input: [3,30,34,5,9]
Output: "9534330"
```
- Note: The result may be very large, so you need to return a string instead of an integer.
- 思路：关键是确定每个数在最后结果中的先后位置，比较直观的是个位数越大的越靠前，如例子中9在5, 4, 3之前；个位相同的再看十位，如例子中34应当在30之前；难点是位数不等时，先后关系怎么确定？如例子中3应当放在30和34之前、之后还是中间？结果是3放在了34和30中间，为什么呢？这是因为十位上的4比个位上3大，所以34在3之前，而十位上的0比个数上的3小，所以30在3之后。这样貌似可以找到规律，就是对于那些有包含关系的数，如1234包含12，那么只需看1234比12多出的部分34比12大还是小。通过这样的方法，貌似也可判断出个先后顺序。只是这样需要考虑的情况太复杂了，如565656和56……可以换一下思路，要想比较两个数在最终结果中的先后位置，何不直接比较一下不同组合的结果大小？举个例子：要比较3和34的先后位置，可以比较334和343的大小，而343比334大，所以34应当在前。这样，有了比较两个数的方法，就可以对整个数组进行排序。然后再把排好序的数拼接在一起就好了。

```
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i:nums)
        {
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for(auto tmp:v)
            ans+=tmp;
        while(ans[0]=='0'&&ans.size()>1)
            ans.erase(0,1);
        return ans;
    }
    static bool cmp(string a,string b)
    {
        return a+b>b+a;
    }
};
```
## Repeated DNA Sequences ##
- All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
- Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
- Example:

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
```
- 思路：建立一个hash表，把每个10位的子字符串和hash表进行比较，如果在，说明是重复子字符串，否则加入hash表中。

```
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<=10)
            return ans;
        unordered_map<string,int> u_s;
        string tmp;
        for(int i=0;i<s.size()-9;i++)
        {
            tmp=s.substr(i,10);
            if(u_s.find(tmp)!=u_s.end())
            {
                if(u_s[tmp]==1)
                {
                    ans.push_back(tmp);
                    u_s[tmp]++;
                }
                else
                    u_s[tmp]++;
            }
            else
            {
                u_s[tmp]=1;
            }
        }
        return ans;
    }
};
```
## Binary Tree Right Side View ##
- Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
- Example:

```
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
```
- 思路：层序遍历，结果只保留每一层的最后一个元素。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        if(!root->left&&!root->right)
            return {root->val};
        vector<int>ans;
        queue<TreeNode*> q;
        queue<TreeNode*> q_next;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp=q.front();
            if(q.size()==1)
            {
                ans.push_back(tmp->val);
            }
            if(tmp->left)
                q_next.push(tmp->left);
            if(tmp->right)
                q_next.push(tmp->right);
            q.pop();
            if(q.empty())
                swap(q,q_next);
        }
        return ans;
    }
};
```

