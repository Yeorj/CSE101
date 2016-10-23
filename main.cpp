#include "graph.h"

int main(){

  Node<char> test('A');
  for (int lcv = 1; lcv < 'Z'-'A'+1; lcv++){
    test.connect(lcv+'A');
  } 
  auto nodes = test.getAdjNodes();

  for(int lcv = 0; lcv < 'Z'-'A' ; lcv++)
    std::cout << nodes[lcv]->getKey() << "\n";

  return 0;
}
