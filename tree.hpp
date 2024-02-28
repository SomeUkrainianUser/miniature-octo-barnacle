#pragma once
#include <vector>
#include <optional>
#include <string>

using namespace std;

namespace SyntaxTree {
    struct TreeNode{
        TreeNode* parentNode;
        vector<TreeNode*> childrenNodes;
        string contents;
    };

    struct Tree {
        TreeNode* top;
        int nodesCount = 0;
    };

    TreeNode* insert(TreeNode* parent, string data, Tree* tree) {
        if (parent == nullptr) {
            tree->top = new TreeNode;
            tree->top->parentNode = nullptr;
            tree->top->contents = data;
            return tree->top;
        } else {
            TreeNode* tmp;
            tmp->parentNode = parent;
            tmp->contents = data;
            parent->childrenNodes.push_back(tmp);
            delete tmp;
            return parent->childrenNodes.at(parent->childrenNodes.size() - 1);
        }
    }
};