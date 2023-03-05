#include <iostream>

using namespace std;

struct Node {
    int data, counter;
    Node *Left;
    Node *Right;
};

void AddElem(Node *tree, int input) {
        cout << "In function" << endl;
        cout << "tree = " << tree << endl;
        cout << "&tree = " << &tree << endl;
        //cout << "*tree = " << *tree << endl;
        if (tree == 0) {

            tree = new Node;
            cout << "tree after new = " << tree;
            tree->counter += 1;
            tree->Left = 0;
            tree->Right = 0;

            //cout << tree->counter;

        }
        //cout << "*tree " << *tree << endl;

    return;
}

int main()
{
    int input, counter = 0;
    char in;
    Node *tree = 0;  // значение переменной tree = 0;

    //cout << tree;
    cout << "Address of &tree = " << &tree << endl << endl; // адрес tree;

    while (in != 'x') {

        cout << "1. Add element " << endl;
        cout << "2. Show Tree " << endl;
        cout << "Input num: " << endl;
        cin >> in;

        switch (in) {
            case '1': {
                cout << "Input info: ";
                cin >> input;
                AddElem(&tree, input);
                cout << endl;
                cout << "Tree in case 1: " << &tree << " " << tree;
                break;
            }
            //case '2': {

            //}

        }

        cout << endl;

    }

    return 0;
}

/*
void AddElem(Node **tree, int input) {
    if (!(*tree)) {
        cout << "tree " << tree << endl;
        cout << "*tree " << *tree << endl;
        cout << "**tree " << *tree << endl;
        *tree = new Node;
        (*tree)->counter += 1;
        (*tree)->Left = 0;
        (*tree)->Right = 0;

    } else if (input > (*tree)->data) {
        AddElem(&(*tree)->Right, input);
        cout << "right " << right << endl;

    } else if (input < (*tree)->data) {
        AddElem(&(*tree)->Left, input);
        cout << "left " << right << endl;
    } else {
        (*tree)->counter +=1;
    }

    return;
}


// work

void AddElem(Node **tree, int input) {
        cout << "In function" << endl;
        cout << "tree = " << tree << endl;
        cout << "&tree = " << &tree << endl;
        cout << "*tree = " << *tree << endl;
        if ((*tree) == 0) {

            *tree = new Node;
            cout << "tree after new = " << *tree;
            (*tree)->counter += 1;
            (*tree)->Left = 0;
            (*tree)->Right = 0;

            //cout << tree->counter;

        }
        //cout << "*tree " << *tree << endl;

    return;
}

*/
