#pragma once
#include <vector>
#include <optional>
#include <string>

#include "tokenization.hpp"

using namespace std;

namespace Trees {
    struct TreeNode {
        TreeNode* parentNode;
        vector<TreeNode*> childrenNodes;
        Token contents;
    };

    struct Tree {
        TreeNode* top;
        int nodesCount = 0;
    };

    TreeNode* insert(TreeNode* parent, Token data, Tree* tree) {
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
