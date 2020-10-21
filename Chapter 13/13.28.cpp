/*
 * Exercise 13.28 给定下面的类，为其实现一个默认构造函数和必要的拷贝控制成员
 * (a) class TreeNode{
 *  private:
 *      std::string values;
 *      int count;
 *      TreeNode *left;
 *      TreeNode *right;
 *  };
 * (b) class BinStrTree{
 *  private:
 *      TreeNode *root;
 *  };
 * */
#include <iostream>
#include <string>
#include <memory>
#include <utility>

using namespace std;

// 对于一个二叉树结点而言，使一个结点的拷贝行为类似于值可以简单认为是创建一个新的结点，
// 创建新节点可以定义一个简单的函数，而不应该使用类的拷贝控制
// 因此定义一个二叉树结点的拷贝行为类似于指针较为合理
class TreeNode {
public:
    TreeNode() : count(new int(1)), left(nullptr), right(nullptr) {}

    TreeNode(string str) : values(std::move(str)), count(new int(1)), left(nullptr), right(nullptr) {}

    TreeNode(const TreeNode &node) : values(node.values),
                                     left(node.left),
                                     right(node.right) {
        ++*node.count;
        count = node.count;
    }

    TreeNode &operator=(TreeNode &node) {
        ++*node.count;
        if (--*count == 0) {
            delete left;
            delete right;
            delete count;
        }
        values = node.values;
        left = node.left;
        right = node.right;
        count = node.count;
        return *this;
    }


    void addLeftNode(TreeNode &node) {
        ++*node.count;
        left = &node;
    }

    void addRightNode(TreeNode &node) {
        ++*node.count;
        right = &node;
    }

    string value() { return values; }

    int use_count() { return *count; }

    TreeNode *leftNode() { return left; }

    TreeNode *rightNode() { return right; }

    ~TreeNode() {
        if (--*count == 0) {
            delete left;
            delete right;
            delete count;
        }
        cout << __func__ << " - " << values << " use_count:" << *count << endl;
    }

private:
    string values;
    int *count;
    TreeNode *left;
    TreeNode *right;
};


class BinStrTree {
public:
    BinStrTree() : root(new TreeNode("root")) {}

    BinStrTree(TreeNode *p) : root(p) {}

    BinStrTree(BinStrTree &bst) : root(bst.root) {

    }

    BinStrTree &operator=(BinStrTree &rhs) {
        root = rhs.root;
        return *this;
    }

    void print(TreeNode *root) {
        cout << root->value() << " use_count:" << root->use_count() << endl;
        if (root->leftNode())
            print(root->leftNode());
        if (root->rightNode())
            print(root->rightNode());
    }

    ~BinStrTree() {
        delete root;
    }

private:
    TreeNode *root;
};


int main(int argc, char **argv) {
    TreeNode left("left"), right("right");
    TreeNode node("hello"), tmp1, tmp2, tmp3;
    node.addLeftNode(left);
    node.addRightNode(right);
    tmp1 = node;
    tmp2 = tmp1;
    tmp3 = node;
    BinStrTree tree;
    tree.print(&tmp3);

    return 0;
}


