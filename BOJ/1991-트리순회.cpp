// https://www.acmicpc.net/problem/1991

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct n {
    char a;
    struct n *left;
    struct n *right;
}node;

int N;
node n[27];

void pre(node* root) {
    cout << root->a;
    if(root->left !=NULL) pre(root->left);
    if (root->right != NULL) pre(root->right);
}

void in(node* root) {

    if (root->left != NULL) in(root->left);
    cout << root->a;
    if (root->right != NULL) in(root->right);
}

void post(node* root) {
        
    if (root->left != NULL)  post(root->left);
    if (root->right != NULL) post(root->right);

    cout << root->a;

}

int main() {
    FAIO;

    cin >> N;

    for (int i = 0; i < 26; i++) n[i].a = i + 'A';
    while (N--) {
        char a, b, c;
        cin >> a >> b >> c;
        if(b > 'A' && b < 'Z')
            n[a - 'A'].left = &n[b - 'A'];

        if (c > 'A' && c < 'Z')
            n[a - 'A'].right = &n[c - 'A'];
    }

    pre(&n[0]);
    cout << el;
    in(&n[0]);
    cout << el;
    post(&n[0]);
    cout << el;

    return 0;
}


/*
    Algorithm : tree , dfs, pre,order, inorder, postorder

    Time complexity : O(N)

*/