#pragma once
#include <string>
#include "BinaryTree.h"

using namespace std;

void testInsertAndTraversal() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    
    cout << "KLP, KPL, LPK, LKP, PLK, PKL\n";
    cout << "tree: " << "2 3 7 2 4 6 8 \n";

    string klpResult;
    tree.klpTraversal([&klpResult](const int& data) {
        klpResult += to_string(data) + " ";
        });
    cout << "KLP: " << klpResult << endl;
    if (klpResult != "5 3 2 4 7 6 8 ") {
        cout << "failed\n\n";
    }
    else {
        cout << "Ok\n\n";
    }

    string kplResult;
    tree.kplTraversal([&kplResult](const int& data) {
        kplResult += to_string(data) + " ";
        });
    cout << "KPL: " << kplResult << endl;
    if (kplResult != "5 7 8 6 3 4 2 ") {
        cout << "failed\n\n";
    }
    else {
        cout << "Ok\n\n";
    }

    string lpkResult;
    tree.lpkTraversal([&lpkResult](const int& data) {
        lpkResult += to_string(data) + " ";
        });
    cout << "LPK: " << lpkResult << endl;
    if (lpkResult != "2 4 3 6 8 7 5 ") {
        cout << "failed\n\n";
    }
    else {
        cout << "Ok\n\n";
    }

    string lkpResult;
    tree.lkpTraversal([&lkpResult](const int& data) {
        lkpResult += to_string(data) + " ";
        });
    cout << "LKP: " << lkpResult << endl;
    if (lkpResult != "2 3 4 5 6 7 8 ") {
        cout << "failed\n\n";
    }
    else {
        cout << "Ok\n\n";
    }

    string plkResult;
    tree.plkTraversal([&plkResult](const int& data) {
        plkResult += to_string(data) + " ";
        });
    cout << "PLK: " << plkResult << endl;
    if (plkResult != "8 6 7 4 2 3 5 ") {
        cout << "failed\n\n";
    }
    else {
        cout << "Ok\n\n";
    }

    string pklResult;
    tree.pklTraversal([&pklResult](const int& data) {
        pklResult += to_string(data) + " ";
        });
    cout << "PKL: " << pklResult << endl;
    if (pklResult != "8 7 6 5 4 3 2 ") {
        cout << "failed\n\n\n";
    }
    else {
        cout << "Ok\n\n\n";
    }
}

void testFindElement() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "Testing FindElement:\n";

    cout << "Tree: 5 3 7 4 2 4 6 8 ";
    cout << endl;

    bool passed = true;

    if (!tree.FindElement(tree.getRoot(), 5)) {
        cout << "FindElement test failed for 5\n";
        passed = false;
    }
    else {
        cout << "element 5 found\n";
    }

    if (!tree.FindElement(tree.getRoot(), 3)) {
        cout << "FindElement test failed for 3\n";
        passed = false;
    }
    else {
        cout << "element 3 found\n";
    }

    if (!tree.FindElement(tree.getRoot(), 8)) {
        cout << "FindElement test failed for 8\n";
        passed = false;
    }
    else {
        cout << "element 8 found.\n";
    }

    if (tree.FindElement(tree.getRoot(), 10)) {
        passed = false;
    }
    else {
        cout << "element 10 not found\n";
    }

    if (tree.FindElement(tree.getRoot(), 25)) {
        passed = false;
    }
    else {
        cout << "element 25 not found\n";
    }

    if (passed) {
        cout << "All tests passed\n\n";
    }
    else {
        cout << "Some tests faile\n\n";
    }
}

void testGetNodeByValue() {
    cout << "Testing GetNodeByValue:\n";

    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "tree: 5 3 7 2 4 6 8\n";

    TreeNode<int>* node = tree.GetNodeByValue(tree.getRoot(), 6);

    if (node) {
        cout << "Node with value 6 found.\n";
    }
    else {
        cout << "Node with value 6 not found.\n";
    }

    node = tree.GetNodeByValue(tree.getRoot(), 10);

    if (node) {
        cout << "Node with value 10 found.\n";
    }
    else {
        cout << "Node with value 10 not found.\n";
    }
}

void testGetSubTree() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    cout << "tree:" << endl;
    tree.klpTraversal([](const int& data) { cout << data << " "; });
    cout << endl;

    BinaryTree<int>* subtree = tree.GetSubTree(3);

    if (subtree) {
        cout << "\nSubtree rooted at node with value 3:" << endl;
        cout << "KLP traversal: ";
        subtree->klpTraversal([](const int& data) { cout << data << " "; });
        cout << endl;
    }
    else {
        cout << "\nSubtree with root value 3 not found." << endl;
    }

    delete subtree;
}