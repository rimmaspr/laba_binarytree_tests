#pragma once
#include <iostream>
#include <functional>
#include <stdexcept>
#include <stack>
#include <sstream>
#include <queue>
#include <stdio.h>

using namespace std;

int getint() {
    int value{};
    int scanf_value{};
    scanf_value = scanf_s("%d", &value);    

    if (!scanf_value) {
        cout << "Invalid input. Try again: ";
        scanf_s("%*[^\n]");
        return getint();
    }
    return value;
}

int getchoise(int minval, int maxval) {
    int choise{};
    cin >> choise;
    if (cin.fail() || choise < minval || choise > maxval) {
        cout << "Invalid input. Enter number from " << minval << " to " << maxval << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return getchoise(minval, maxval);
    }
    return choise;
}


template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    void klpTraversalHelper(TreeNode<T>* node, function<void(const T&)> visit) const {
        if (node) {
            visit(node->data);
            klpTraversalHelper(node->left, visit);
            klpTraversalHelper(node->right, visit);
        }
    }

    void kplTraversalHelper(TreeNode<T>* node, function<void(const T&)> visit) const {
        if (node) {
            visit(node->data);
            kplTraversalHelper(node->right, visit);
            kplTraversalHelper(node->left, visit);
        }
    }

    void lpkTraversalHelper(TreeNode<T>* node, function<void(const T&)> visit) const {
        if (node) {
            lpkTraversalHelper(node->left, visit);
            lpkTraversalHelper(node->right, visit);
            visit(node->data);
        }
    }

    void lkpTraversalHelper(TreeNode<T>* node, function<void(const T&)> visit) const {
        if (node) {
            lkpTraversalHelper(node->left, visit);
            visit(node->data);
            lkpTraversalHelper(node->right, visit);
        }
    }

    void plkTraversalHelper(TreeNode<T>* node, function<void(const T&)> visit) const {
        if (node) {
            plkTraversalHelper(node->right, visit);
            plkTraversalHelper(node->left, visit);
            visit(node->data);
        }
    }

    void pklTraversalHelper(TreeNode<T>* node, function<void(const T&)> visit) const {
        if (node) {
            pklTraversalHelper(node->right, visit);
            visit(node->data);
            pklTraversalHelper(node->left, visit);
        }
    }

    TreeNode<T>* copyTree(TreeNode<T>* node) const {
        if (!node) {
            return nullptr;
        }
        TreeNode<T>* newNode = new TreeNode<T>(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void destroyTree(TreeNode<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:

    void inputTree() {
        root = nullptr;
        T value;
        cout << "Enter tree nodes (enter -1 to stop): ";
        while (true) {
            if (cin >> value) {
                if (value == -1)
                    break;
                try {
                    insert(value);
                }
                catch (const invalid_argument& e) {
                    cout << "Duplicate value " << value << " ignored." << endl;
                }
            }
            else {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    void insertHelper(TreeNode<T>*& node, T value) {
        if (!node) {
            node = new TreeNode<T>(value);
        }
        else if (value < node->data) {
            insertHelper(node->left, value);
        }
        else if (value > node->data) {
            insertHelper(node->right, value);
        }
        else {
            throw invalid_argument("Duplicate value");
        }
    }

    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    TreeNode<T>* getRoot() const {
        return root;
    }

    void insert(T value) {
        insertHelper(root, value);
    }

    void klpTraversal(function<void(const T&)> visit) const {
        klpTraversalHelper(root, visit);
    }

    void kplTraversal(function<void(const T&)> visit) const {
        kplTraversalHelper(root, visit);
    }

    void lpkTraversal(function<void(const T&)> visit) const {
        lpkTraversalHelper(root, visit);
    }

    void lkpTraversal(function<void(const T&)> visit) const {
        lkpTraversalHelper(root, visit);
    }

    void plkTraversal(function<void(const T&)> visit) const {
        plkTraversalHelper(root, visit);
    }

    void pklTraversal(function<void(const T&)> visit) const {
        pklTraversalHelper(root, visit);
    }

    TreeNode<T>* GetNodeByValue(TreeNode<T>* node, const T& value) {
        stack<TreeNode<T>*> nodes;
        nodes.push(node);

        while (!nodes.empty()) {
            TreeNode<T>* current = nodes.top();
            nodes.pop();

            if (current->data == value) {
                return current;
            }

            if (current->right) {
                nodes.push(current->right);
            }
            if (current->left) {
                nodes.push(current->left);
            }
        }

        return nullptr;
    }

    BinaryTree<T>* GetSubTree(const T& element) {
        TreeNode<T>* subNode = GetNodeByValue(root, element);
        if (!subNode) {
            return nullptr;
        }

        BinaryTree<T>* subtree = new BinaryTree<T>();
        subtree->root = copyTree(subNode);
        return subtree;
    }

    bool FindElement(TreeNode<T>* node, const T& value) const {
        stack<TreeNode<T>*> nodes;
        nodes.push(node);

        while (!nodes.empty()) {
            TreeNode<T>* current = nodes.top();
            nodes.pop();

            if (current->data == value) {
                return true;
            }

            if (current->right) {
                nodes.push(current->right);
            }
            if (current->left) {
                nodes.push(current->left);
            }
        }

        return false;
    }

    string Find(const T& value) const {
        if (FindElement(root, value)) {
            return "Found";
        }
        else {
            return "Not found";
        }
    }

    string saveToString(function<void(TreeNode<T>*, ostringstream&)> traversalFunction) const {
        ostringstream out;
        traversalFunction(root, out);
        return out.str();
    }

    void klpToString(TreeNode<T>* node, ostringstream& out) const {
        if (node) {
            out << node->data << " ";
            klpToString(node->left, out);
            klpToString(node->right, out);
        }
    }

    void kplToString(TreeNode<T>* node, ostringstream& out) const {
        if (node) {
            out << node->data << " ";
            kplToString(node->right, out);
            kplToString(node->left, out);
        }
    }

    void lpkToString(TreeNode<T>* node, ostringstream& out) const {
        if (node) {
            lpkToString(node->left, out);
            lpkToString(node->right, out);
            out << node->data << " ";
        }
    }

    void lkpToString(TreeNode<T>* node, ostringstream& out) const {
        if (node) {
            lkpToString(node->left, out);
            out << node->data << " ";
            lkpToString(node->right, out);
        }
    }

    void plkToString(TreeNode<T>* node, ostringstream& out) const {
        if (node) {
            plkToString(node->right, out);
            plkToString(node->left, out);
            out << node->data << " ";
        }
    }

    void pklToString(TreeNode<T>* node, ostringstream& out) const {
        if (node) {
            pklToString(node->right, out);
            out << node->data << " ";
            pklToString(node->left, out);
        }
    }

    void loadFromString(const string& data, function<TreeNode<T>* (istringstream&)> buildFunction) {
        istringstream in(data);
        root = buildFunction(in);
    }

    TreeNode<T>* buildKLP(istringstream& in) {
        T value;
        if (in >> value) {
            TreeNode<T>* node = new TreeNode<T>(value);
            node->left = buildKLP(in);
            node->right = buildKLP(in);
            return node;
        }
        return nullptr;
    }

    TreeNode<T>* buildKPL(istringstream& in) {
        T value;
        if (in >> value) {
            TreeNode<T>* node = new TreeNode<T>(value);
            node->right = buildKPL(in);
            node->left = buildKPL(in);
            return node;
        }
        return nullptr;
    }

    TreeNode<T>* buildLPK(istringstream& in) {
        T value;
        if (in >> value) {
            TreeNode<T>* node = new TreeNode<T>(value);
            node->left = buildLPK(in);
            node->right = buildLPK(in);
            return node;
        }
        return nullptr;
    }

    TreeNode<T>* buildLKP(istringstream& in) {
        T value;
        if (in >> value) {
            TreeNode<T>* node = new TreeNode<T>(value);
            node->left = buildLKP(in);
            node->right = buildLKP(in);
            return node;
        }
        return nullptr;
    }

    TreeNode<T>* buildPLK(istringstream& in) {
        T value;
        if (in >> value) {
            TreeNode<T>* node = new TreeNode<T>(value);
            node->right = buildPLK(in);
            node->left = buildPLK(in);
            return node;
        }
        return nullptr;
    }

    TreeNode<T>* buildPKL(istringstream& in) {
        T value;
        if (in >> value) {
            TreeNode<T>* node = new TreeNode<T>(value);
            node->right = buildPKL(in);
            node->left = buildPKL(in);
            return node;
        }
        return nullptr;
    }

    string saveKLP() const {
        return saveToString([this](TreeNode<T>* node, ostringstream& out) { klpToString(node, out); });
    }

    string saveKPL() const {
        return saveToString([this](TreeNode<T>* node, ostringstream& out) { kplToString(node, out); });
    }

    string saveLPK() const {
        return saveToString([this](TreeNode<T>* node, ostringstream& out) { lpkToString(node, out); });
    }

    string saveLKP() const {
        return saveToString([this](TreeNode<T>* node, ostringstream& out) { lkpToString(node, out); });
    }

    string savePLK() const {
        return saveToString([this](TreeNode<T>* node, ostringstream& out) { plkToString(node, out); });
    }

    string savePKL() const {
        return saveToString([this](TreeNode<T>* node, ostringstream& out) { pklToString(node, out); });
    }

    void loadKLP(const string& data) {
        loadFromString(data, [this](istringstream& in) { return buildKLP(in); });
    }

    void loadKPL(const string& data) {
        loadFromString(data, [this](istringstream& in) { return buildKPL(in); });
    }

    void loadLPK(const string& data) {
        loadFromString(data, [this](istringstream& in) { return buildLPK(in); });
    }

    void loadLKP(const string& data) {
        loadFromString(data, [this](istringstream& in) { return buildLKP(in); });
    }

    void loadPLK(const string& data) {
        loadFromString(data, [this](istringstream& in) { return buildPLK(in); });
    }

    void loadPKL(const string& data) {
        loadFromString(data, [this](istringstream& in) { return buildPKL(in); });
    }
};

