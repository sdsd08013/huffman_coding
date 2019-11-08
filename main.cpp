#include <iostream>
using namespace std;

typedef long long ll;

int N = 12;
// string L[18] = { "m", "i", "s", "s", "p", "e", "l", "l", "e", "d", "v", "a", "r", "i", "a", "b", "l", "e" };
int L[12] = { 13, 1 , 3 , 31, 3, 2,1, 23,45,6, 7, 7 };

struct node {
  node *parent;
  node *left;
  node *right;
  node *next;
  unsigned int freq;
  char chr;
};

struct code {
  char chr;
  int value;
  char bit;
  code *next;
};

node *newNode(char chr){
  node *newNode;

  newNode = new node;
  if(newNode == nullptr){
    return nullptr;
  }

  newNode->parent = nullptr;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->next = nullptr;

  newNode->freq = 1;
  newNode->chr = chr;

  return newNode;
}

node *searchNode(node *node, char chr){
  while(node != nullptr){
    if(node->chr == chr){
      return node;
    }
    node = node->next;
  }
  return node;
}

void countup() {
  ll size = sizeof(L);
  node *head;
  node *tail;
  node *add;
  node *searchedNode;
  head = nullptr;

  searchedNode = searchNode(head, 1);

  if(searchedNode == nullptr){
    add = newNode('a');
    if(head == nullptr) {
      head = add;
      tail = add;
    } else {
      tail->next = add;
      tail = add;
    }
  } else {
    searchedNode->freq++;
  }
}

int main() {
  ll ans = 0;

  while (N > 1) {

    int mii1 = 0, mii2 = 1;
    if (L[mii1] > L[mii2]) swap(mii1, mii2);

    // Lのソート
    for (int i = 2; i<N; i++) {
      // L[0]よりも小さい場合 -> 0 = i, 1=0
      if (L[i] < L[mii1]) {
        mii2 = mii1;
        mii1 = i;
      } 
      // L[1]よりも小さい場合 -> 0 = 0, 1=i
      else if (L[i] < L[mii2]) {
        mii2 = i;
      }
    }

    // 切り分けられていたものの合計
    int t = L[mii1] + L[mii2];
    ans += t;

    if (mii1 == N-1) swap(mii1, mii2);

    L[mii1] = t;
    // NがデクリメントされるのでN-1はソート対象とならない、使い終わったL[mii2]をL[N-1]とする
    L[mii2] = L[N-1];
    cout << "mii1:" << L[mii1] << " mii2:" << L[mii2] << " L[N-1]:" << L[N-1] << " N-1:" << N-1 << endl;
    N--;

    node *n = searchNode(nullptr, 1);

    cout << hex << &n->freq << endl;
  }

  cout << ans;
  return 0;
}
