#include <iostream>
#include "BinaryTree.h"
#include "tests.h"

using namespace std;

int main() {

    /*testInsertAndTraversal();
    testFindElement();
    testGetNodeByValue();*/

    testGetSubTree();

    BinaryTree<int> tree;
    tree.inputTree();

    cout << endl << "KLP: ";
    tree.klpTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl;

    cout << "KPL: ";
    tree.kplTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl;

    cout << "LPK: ";
    tree.lpkTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl;

    cout << "LKP: ";
    tree.lkpTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl;

    cout << "PLK: ";
    tree.plkTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl;

    cout << "PKL: ";
    tree.pklTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl << endl;


    cout << "Enter element to subtree: ";
    int element_to_extract;
    element_to_extract = getint();
    BinaryTree<int>* subtree = tree.GetSubTree(element_to_extract);
    if (subtree != nullptr) {
        cout << "Subtree (KLP): ";
        subtree->klpTraversal([](const int& data) {
            cout << data << " ";
            });
        cout << endl;
        delete subtree;
    }
    else {
        cout << "Failed" << endl;
    }


    cout << "Enter element to search: ";    
    int element_to_search;
    element_to_search = getint();
    cout << (tree.FindElement(tree.getRoot(), element_to_search) ? "Found" : "Not found") << endl;


    string saved_klp = tree.saveKLP();
    BinaryTree<int> new_tree;
    new_tree.loadKLP(saved_klp);

    cout << "Loaded tree (KLP): ";
    new_tree.klpTraversal([](const int& data) {
        cout << data << " ";
        });
    cout << endl;


    return 0;
}
