#pragma once
#include <string>
#include "BinaryTree.h"

using namespace std;

void testTraversal();
void testFindElement();
void testGetNodeByValue();
void testGetSubTree();
void testSaveToString();
void testBuildKLP();
void testSaveKLP();
void testLoadKLP();

void menu() {
    cout << "Select a test to run:" << endl;
    cout << "1. Test Traversal" << endl;
    cout << "2. Test Find Element" << endl;
    cout << "3. Test Get Node By Value" << endl;
    cout << "4. Test Get SubTree" << endl;
    cout << "5. Test Save To String" << endl;
    cout << "6. Test Build KLP" << endl;
    cout << "7. Test Save KLP" << endl;
    cout << "8. Test Load KLP" << endl;
    cout << "0. Exit" << endl;
}

// Функция для выполнения выбранного теста
void runTest(int choice) {
    switch (choice) {
    case 1:
        testTraversal();
        break;
    case 2:
        testFindElement();
        break;
    case 3:
        testGetNodeByValue();
        break;
    case 4:
        testGetSubTree();
        break;
    case 5:
        testSaveToString();
        break;
    case 6:
        testBuildKLP();
        break;
    case 7:
        testSaveKLP();
        break;
    case 8:
        testLoadKLP();
        break;
    case 0:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}

void testTraversal() {
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
        cout << "All ok\n\n";
    }
    else {
        cout << "Some tests failed\n\n";
    }
    cout << endl;
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
        cout << "node 6 found.\n";
    }
    else {
        cout << "node 6 not found.\n";
    }

    node = tree.GetNodeByValue(tree.getRoot(), 10);

    if (node) {
        cout << "node 10 found.\n";
    }
    else {
        cout << "node 10 not found.\n";
    }
    cout << endl;
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
    cout << "Testing GetSubTree\n";

    cout << "tree:" << endl;
    tree.klpTraversal([](const int& data) { cout << data << " "; });
    

    BinaryTree<int>* subtree = tree.GetSubTree(3);

    if (subtree) {
        cout << "\nsubtree rooted at node 3:" << endl;
        cout << "KLP traversal: ";
        subtree->klpTraversal([](const int& data) { cout << data << " "; });
        cout << endl;
    }
    else {
        cout << "\nsubtree root at node 3 not found." << endl;
    }

    delete subtree;
    cout << endl;
}


void testSaveToString() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    string klpResult = tree.saveToString([&tree](TreeNode<int>* node, ostringstream& out) {
        tree.klpToString(node, out);
        });

    string expectedKLP = "5 3 2 4 7 6 8 ";

    cout << "Testing SaveToString:\n";
    cout << "result: " << klpResult << endl;
    cout << "epected: " << expectedKLP << endl;

    if (klpResult == expectedKLP) {
        cout << "ok\n";
    }
    else {
        cout << "failed\n";
    }
    cout << endl;
}

void testLoadFromString() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    cout << "Testing LoadFromString\n";

    string klpString = tree.saveKLP();
    BinaryTree<int> newTree;
    newTree.loadFromString(klpString, [&](istringstream& in) { return newTree.buildKLP(in); });

    stringstream resultStream;
    newTree.klpTraversal([&](const int& data) {
        resultStream << data << " ";
        });

    string result = resultStream.str();
    cout << "expected KLP: " << klpString << endl;
    cout << "result KLP: " << result << endl;

    if (klpString == result) {
        cout << "ok" << endl;
    }
    else {
        cout << "failed" << endl;
    }
    cout << endl;
}


void testBuildKLP() {
    cout << "Testing BuildKLP\n";

    string klpString = "5 3 2 4 7 6 8";

    istringstream in(klpString);

    BinaryTree<int> tree;

    tree.loadFromString(klpString, [&](istringstream& in) { return tree.buildKLP(in); });

    stringstream resultStream;
    tree.klpTraversal([&](const int& data) {
        resultStream << data << " ";
        });

    string result = resultStream.str();
    cout << "expected KLP: " << klpString << endl;
    cout << "result KLP: " << result << endl;

    if (klpString + " " == result) {
        cout << "ok" << endl;
    }
    else {
        cout << "failed" << endl;
    }
}

void testSaveKLP() {
    BinaryTree<int> tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    cout << "Testing SaveKLP\n";

    string resultKLP = tree.saveKLP();
    string expectedKLP = "5 3 2 4 7 6 8 ";

    cout << "expected: " << expectedKLP << endl;
    cout << "result: " << resultKLP << endl;

    if (resultKLP == expectedKLP) {
        cout << "ok" << endl; }
    else {
        cout << "failed" << endl; }
    cout << "\n";
}

void testLoadKLP() {
    string klpData = "5 3 2 4 7 6 8 ";

    cout << "Testing LoadKLP\n";

    BinaryTree<int> tree;
    tree.loadKLP(klpData);

    string resultKLP = tree.saveKLP();
    string expectedKLP = "5 3 2 4 7 6 8 ";

    cout << "expected: " << expectedKLP << endl;
    cout << "result: " << resultKLP << endl;

    if (resultKLP == expectedKLP) {
        cout << "ok" << endl;
    }
    else {
        cout << "failed" << endl;
    }
}