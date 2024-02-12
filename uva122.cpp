#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct node {
    node *left;
    node *right;
    int *value;
};

node *new_node(){
    node *p = (node *)malloc(sizeof(node));

    if (p != NULL) {
        p->left = NULL;
        p->right = NULL;
        p->value = NULL;
    }

    return p;
}

node *free_node(node *p){
    if (p != NULL) {
        p->left = free_node(p->left);
        p->right = free_node(p->right);
        free(p);
        p = NULL;
    }

    return p;
}

vector<int> check(node *p){

    vector<int> values;
    queue<node *> q_nodes;
    q_nodes.push(p);
    node *q_head;


    while (!q_nodes.empty()) {
        q_head = q_nodes.front();

        if (q_head->value == NULL) {
            values.clear();
            return values;
        }

        values.push_back(*(q_head->value));

        if (q_head->left != NULL) {
            q_nodes.push(q_head->left);
        }

        if (q_head->right != NULL) {
            q_nodes.push(q_head->right);
        }

        q_nodes.pop();
    }

    return values;
}

int main(int argc, char *argv[]){
    int m = 0;
    int ic;
    char c;
    string number = "";
    node *root = new_node();
    node *p = root;
    int repeat_size = 0;
    vector<int> values;

    while ((ic = getchar()) != EOF) {
        c = (char)ic;

        if (m == 0) {
            if (c == '\n' || c == ' ') {
                m = 0;
                continue;
            }

            if (c == '(') {
                m = 1;
                continue;
            }
        }

        if (m == 1) {
            if (ic >= 48 && ic <= 57) {
                number += c;
                m = 1;
                continue;
            }

            if (c == ',') {
                m = 2;
                continue;
            }

            if (c == ')') {
                values = check(root);

                if (repeat_size == 0 && values.size() != 0) {
                    cout << values[0];

                    for (int i = 1; i < values.size(); i += 1) {
                        cout << " " << values[i];
                    }
                } else {
                    cout << "not complete";
                }

                cout << endl;
                values.clear();
                root = free_node(root);
                root = new node();
                p = root;
                repeat_size = 0;
                m = 0;
                continue;
            }
        }

        if (m == 2) {
            if (c == ')') {
                if (p->value == NULL) {
                    p->value = (int *)malloc(sizeof(int));

                    if (p->value == NULL) {
                        return 0;
                    }

                    *(p->value) = stoi(number);
                } else {
                    repeat_size += 1;
                }

                number.clear();
                p = root;
                m = 0;
                continue;
            }

            if (c == 'L') {
                if (p->left == NULL) {
                    p->left = new_node();
                }

                p = p->left;
                m = 2;
                continue;
            }

            if (c == 'R') {
                if (p->right == NULL) {
                    p->right = new_node();
                }

                p = p->right;
                m = 2;
                continue;
            }
        }
    }

    return 0;
}