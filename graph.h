#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
/* class Node:
 * Node is simply a node that contains a key (i.e. The value it contains), its
 * degree (deg) (i.e. how many edges are coming out of it), and all the adjNodes
 * it is directly connected to. */
template <typename T> class Node{
typedef Node<T>* pNode;
  public:
    Node(T key) : key(key), deg(0), adjNodes(0) {};
    Node() {};

    T getKey(){return key;};
    pNode * getAdjNodes(){return adjNodes;};

    void setKey(T value) {key = value;};

    /* connect(pNode adj, double edgeWeight=0)
     * input: adj is the adjacent node to be connected to the initial node;
     *        edgeWeight is the distance between the initial node and adjNode
     * output: No output. The nodes are connected */ 
    void connect(pNode adj, double edgeWeight=0){

      incrementAdjNodes();

      adjNodes[deg-1] = adj;      
    }; // end of connect(Node<T> adj, double edgeWeight=0)

    /* connect(T adj, double edgeWeight=0)
     * input: adj is the key of the node to connect to the original node;
     *        edgeWeight is the distance between the initial node and adjNode
     * output: No output. The nodes are connected */ 
    void connect(T adj, double edgeWeight=0){
      auto insert = new Node<T>();
      insert->key = adj;
      connect(insert, edgeWeight);
    }; // end of connect(T adj, double edgeWeight=0)

  private:
    T key;
    int deg;
    pNode * adjNodes; //array of nodes that connect to original node

    /* Increases the size of adjNodes size by 1 */
    void incrementAdjNodes(){
      pNode temp[deg]; 
      ++deg;

      for(int lcv = 0; lcv < deg-1; lcv++)
        temp[lcv] = adjNodes[lcv];
        
      delete adjNodes;
      adjNodes = new pNode[deg];

      for(int lcv = 0; lcv < deg-1; lcv++)
        adjNodes[lcv] = temp[lcv];
    };
};
/*
template <typename T> class Graph{	
  
  protected:
    T *node;
};

template <typename T> class SimpleUndirectedGraph: public Graph<T>{
  
  public:
    SimpleUndirectedGraph(T** adj);

  private:
    T ** adjList;

};
*/
#endif //_GRAPH_H_
