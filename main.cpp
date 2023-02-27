#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *leftRoot;
    TreeNode *rightRoot;

    TreeNode(int x) {
        data = x;
        leftRoot = nullptr;
        rightRoot = nullptr;
    }
    TreeNode(int x, TreeNode* leftNode, TreeNode* rightNode) : data(x), leftRoot(leftNode), rightRoot(rightNode) {}
};

std::vector <int> vectorFill() {
    std::vector <int> vectorCopy;
    std::fstream input("text2.txt");
    std::copy(std::istream_iterator<int>(input), std::istream_iterator<int>(), std::back_inserter(vectorCopy));
    return vectorCopy;
}

TreeNode* getBalancedTree(const vector<int> vec) {
    vector<int> vectorCopy(vec);
    return vectorCopy.size() == 0 ? nullptr: vectorCopy.size() == 1 ? new TreeNode(vectorCopy[0])
                                                                    : new TreeNode(vectorCopy[vectorCopy.size() / 2], getBalancedTree({vectorCopy.begin(), vectorCopy.begin() + vectorCopy.size() / 2}),
                                                                                   getBalancedTree({vectorCopy.begin() + vectorCopy.size() / 2 + 1, vectorCopy.end()}));
}

void print(TreeNode* root) {
    function<void(queue<TreeNode*>&)> bfs = [&](queue<TreeNode*>& treeDataQueue) {
        bool flag = false;
        for (int i = 0; i < treeDataQueue.size(); i++)
        {
            TreeNode* node = treeDataQueue.front();
            treeDataQueue.pop();
            node ? (flag = true, (cout << node->data << " "), treeDataQueue.push(node->leftRoot), treeDataQueue.push(node->rightRoot)) : (flag ? (cout << "null "), void(): void());
        }
        !treeDataQueue.empty() && flag ? ( bfs(treeDataQueue)) : void();
    };
    queue<TreeNode*> rootQueue;
    rootQueue.push(root);
    bfs(rootQueue);
}
int main() {
    vector<int> vec = vectorFill();
    print(getBalancedTree(vec));
}