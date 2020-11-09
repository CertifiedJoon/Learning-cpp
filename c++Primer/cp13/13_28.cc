#include <string>
#include <iostream>

class TreeNode {
public:
    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &tn) : 
        value(tn.value), count(tn.count), left(tn.left), right(tn.right) {}
    TreeNode& operator=(const TreeNode &rhs);
    ~TreeNode() {delete left; delete right;}

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
    auto newl = rhs.left;
    auto newr = rhs.right;

    delete left;
    delete right;

    left = newl;
    right = newr;
    
    return *this;
}