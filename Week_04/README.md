# BFS/DFS
## 模板
+ DFS
~~~c++
//C/C++
//递归写法：
map<int, int> visited;

void dfs(Node* root) {
  // terminator
  if (!root) return ;

  if (visited.count(root->val)) {
    // already visited
    return ;
  }

  visited[root->val] = 1;

  // process current node here. 
  // ...
  for (int i = 0; i < root->children.size(); ++i) {
    dfs(root->children[i]);
  }
  return ;
}

//C/C++
//非递归写法：
void dfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  stack<Node*> stackNode;
  stackNode.push(root);

  while (!stackNode.empty()) {
    Node* node = stackNode.top();
    stackNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;


    for (int i = node->children.size() - 1; i >= 0; --i) {
        stackNode.push(node->children[i]);
    }
  }

  return ;
}
~~~
+ BFS
~~~c++
// C/C++
void bfs(Node* root) {
  map<int, int> visited;
  if(!root) return ;

  queue<Node*> queueNode;
  queueNode.push(root);

  while (!queueNode.empty()) {
    Node* node = queueNode.top();
    queueNode.pop();
    if (visited.count(node->val)) continue;
    visited[node->val] = 1;

    for (int i = 0; i < node->children.size(); ++i) {
        queueNode.push(node->children[i]);
    }
  }

  return ;
}
~~~

## 问题分类
1. 在BFS/DFS框架内，对节点的不同状态作不同处理：
> 529.扫雷游戏
2. 通过BFS/DFS，来找出指定节点或维护某些值
> 22.括号生成
> 515.在每个树行中找最大值
3. 利用BFS/DFS遍历
> 102. 二叉树的层序遍历
4. 一个状态转移到另一个状态，问某个状态是否能转换到特定状态
> 127.单词接龙
> 126.单词接龙II
> 433.最小基因变化
5. 在某个图中，搜索关于某性质连通的所有节点，并对这些节点分别构成的集合进行计数
> 200.岛屿数量（也是先找1，找到1就coun++,并用bfs清掉相邻所有1；注意：找到1马上要清掉，否则遍历过程会产生大量重复节点）

# 二分查找
## 模板
~~~c++
C/C++

int binarySearch(const vector<int>& nums, int target) {
	int left = 0, right = (int)nums.size()-1;
	
	while (left <= right) {
		int mid = left + (right - left)/ 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	
	return -1;
}
~~~

## 使用条件
1. 数据有序
2. 有上下区间
3. 目标函数单调递增

## 细节是魔鬼
+ 注意初始的搜索区间
+ 注意搜索终止条件\状态
	+ while (left <= right), 终止时left == right;无论搜索过程的最后一个元素大于或小于target，插入位置都应时while结束时的left位置；如果要插入位置为0，证明target比所有元素都小；如果要插入位置等于nums.size() ,证明比所有元素都大
> 33. 搜索旋转排序数组 
> 35. 搜索插入位置
+ 区间划分条件
	+ 分情况对搜索区间进行划分
> 33. 搜索旋转排序数组
> 153. 寻找旋转排序数组中的最小值 