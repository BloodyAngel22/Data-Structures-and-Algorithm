#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
  public:
    int rating;
    Node* left;
    Node* right;

    Node(int val) : rating(val), left(nullptr), right(nullptr) {}
};

bool checkSize(vector<int> player_rating){
  for (int i = 4; i <= 1024; i*=2)
    if (player_rating.size() == i)
      return true;
  return false;
}

Node* buildTree(const vector<int>& ratings, int start, int end) {
  if (!checkSize(ratings)){
    cout << "Количество игроков должно соответствовать степеням двойки и должно быть больше 3\n";
    exit(1);
  }

  if (start == end) {
    return new Node(ratings[start]);
  }

  int mid = (start + end) / 2;
  Node* root = new Node(-1);  
  root->left = buildTree(ratings, start, mid);
  root->right = buildTree(ratings, mid + 1, end);

  return root;
}

void determineResults(Node* root) {
  if (root->left && root->right) {
    determineResults(root->left);
    determineResults(root->right);
    root->rating = max(root->left->rating, root->right->rating);
  }
}

//Используется выровненный обход
void tourTraversal(Node* root) {
  if (!root)
    return;

  queue<Node*> nodesQueue;
  nodesQueue.push(root);

  while (!nodesQueue.empty()) {
    Node* current = nodesQueue.front();
    nodesQueue.pop();

    if (current->left && current->right) {
      cout << "Игрок " << current->left->rating << " \tпротив  \tИгрока " << current->right->rating;
      cout << "\t Победитель: Игрок " << current->rating << endl;
    }

    if (current->left)
      nodesQueue.push(current->left);

    if (current->right)
      nodesQueue.push(current->right);
  }
}

void findTopThreeWinners(vector<int>& winners) {
  sort(winners.begin(), winners.end(), greater<int>());

  cout << "Первые три призера:" << endl;
  int i = 1;
  for (auto rating : winners) {
    cout << "Место " << i++ << ": Игрок с рейтингом " << rating << endl;
    if (i > 3) {
      break; 
    }
  }
}

int main() {
  vector<int> players_rating = {
    100, 90, 110, 85, 105, 120, 110, 95
  };

  Node* root = buildTree(players_rating, 0, players_rating.size()-1);

  determineResults(root);

  cout << "Игроки и их рейтинг:" << endl;
  for (int i = 0; i < players_rating.size(); ++i) {
    cout << "Игрок " << ": " << players_rating[i] << endl;
  }

  cout << "\nРезультаты туров:" << endl;
  tourTraversal(root);
  cout << "\n↑ Смотреть снизу вверх ↑\n";

  findTopThreeWinners(players_rating);

  delete root;

  return 0;
}
