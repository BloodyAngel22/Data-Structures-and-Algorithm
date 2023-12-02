#include <algorithm>
#include <iostream>
#include <vector>

class TreeNode {
  public:
    int data;
    std::vector<TreeNode*> children;

    TreeNode(int value) : data(value) {}

    void addChild(TreeNode* child) {
      children.push_back(child);
    }
};

void traverseFaculty(TreeNode* node, std::vector<int>& computers);
void traverseCampus(TreeNode* node, std::vector<int>& computers);

void findSharedAuditoriums(TreeNode* facultyRoot, TreeNode* campusRoot) {
  std::vector<int> computersInFaculty;
  traverseFaculty(facultyRoot, computersInFaculty);

  std::vector<int> computersInCampus;
  traverseCampus(campusRoot, computersInCampus);

  std::vector<int> sharedAuditoriums;
  for (int computer : computersInCampus) {
    if (std::find(computersInFaculty.begin(), computersInFaculty.end(), computer) != computersInFaculty.end()) {
      sharedAuditoriums.push_back(computer);
    }
  }

  std::cout << "Компьютеры, которые совпадают с кафедрами и аудиториями: ";
  for (int auditorium : sharedAuditoriums) {
    std::cout << auditorium << " ";
  }
  std::cout << std::endl;
}

void traverseFaculty(TreeNode* node, std::vector<int>& computers) {
  if (!node) 
    return;

  for (TreeNode* child : node->children) 
    traverseFaculty(child, computers);

  if (node->children.empty()) 
    computers.push_back(node->data);
}

void traverseCampus(TreeNode* node, std::vector<int>& computers) {
  if (!node) 
    return;

  for (TreeNode* child : node->children) 
    traverseCampus(child, computers);

  if (node->children.empty()) 
    computers.push_back(node->data);
  
}

int main() {
  TreeNode* facultyRoot = new TreeNode(1);
  TreeNode* department1 = new TreeNode(2);
  TreeNode* department2 = new TreeNode(3);
  TreeNode* computer1 = new TreeNode(101);
  TreeNode* computer2 = new TreeNode(102);
  TreeNode* computer3 = new TreeNode(103);
  TreeNode* computer4 = new TreeNode(104);
  TreeNode* computer5 = new TreeNode(105);
  TreeNode* computer6 = new TreeNode(121);
  TreeNode* computer7 = new TreeNode(132);
  TreeNode* computer14 = new TreeNode(233);

  facultyRoot->addChild(department1);
  facultyRoot->addChild(department2);
  department1->addChild(computer1);
  department1->addChild(computer5);
  department2->addChild(computer2);
  department2->addChild(computer3);
  department2->addChild(computer4);
  department1->addChild(computer6);
  department1->addChild(computer7);
  department1->addChild(computer14);

  TreeNode* campusRoot = new TreeNode(4);
  TreeNode* auditorium1 = new TreeNode(5);
  TreeNode* computer8 = new TreeNode(105);
  TreeNode* computer9 = new TreeNode(102);
  TreeNode* computer10 = new TreeNode(132);
  TreeNode* computer11 = new TreeNode(144);
  TreeNode* computer12 = new TreeNode(164);
  TreeNode* computer13 = new TreeNode(190);
  TreeNode* computer15 = new TreeNode(233);

  campusRoot->addChild(auditorium1);
  auditorium1->addChild(computer8);
  auditorium1->addChild(computer9);
  auditorium1->addChild(computer10);
  auditorium1->addChild(computer11);
  auditorium1->addChild(computer12);
  auditorium1->addChild(computer13);
  auditorium1->addChild(computer15);

  findSharedAuditoriums(facultyRoot, campusRoot);

  return 0;
}
