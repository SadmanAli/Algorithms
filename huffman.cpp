#include<bits/stdc++.h>

using namespace std;

struct node{

 node * lc;
 node * rc;
 double frequency;
 string content;
 string code;
};

vector<node> nodeArray;

node  extractMin(){

    double temp = (double) INT_MAX;
    vector<node>::iterator i1,pos;
    for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++){

  if(temp>(*i1).frequency){

     pos = i1;
     temp = (*i1).frequency;
  }
 }

 node tempNode = (*pos);
 nodeArray.erase(pos);

 return tempNode;
}



node getHuffmanTree(){

 while(!nodeArray.empty()){

   node * tempNode = new node;
      node * tempNode1 = new node;
   node * tempNode2 = new node;
      *tempNode1 = extractMin();
   *tempNode2 = extractMin();


   tempNode->lc= tempNode1;
   tempNode->rc = tempNode2;
   tempNode->frequency = tempNode1->frequency+tempNode2->frequency;
   nodeArray.push_back(*tempNode);
   if(nodeArray.size() == 1){

    break;
   }
 }
    return nodeArray[0];
}


void BFS(node * temproot,string s){

   node * root1 = new node;
   root1 = temproot;

   root1->code = s;
   if(root1 == NULL){}
   else if(root1->lc == NULL && root1->rc == NULL){

    cout<<root1->content<<"   "<<root1->code<<endl;
   }
   else{

      root1->lc->code = s.append("0");
      s.erase(s.end()-1);
      root1->rc->code = s.append("1");
      s.erase(s.end()-1);


      BFS(root1->lc,s.append("0"));
      s.erase(s.end()-1);
      BFS(root1->rc,s.append("1"));
      s.erase(s.end()-1);
 }

}

void getHuffmanCode(){

 int size,i;
 double tempDouble;
 string tempString = "";

 cin>>size;

 for(i = 0;i<size;i++){

  node tempNode;
  cin>>tempString;
  cin>>tempDouble;


  tempNode.frequency = tempDouble;
  tempNode.content = tempString;
  tempNode.lc = NULL;
  tempNode.rc = NULL;
  nodeArray.push_back(tempNode);
 }

  cout<<endl;

 node root = getHuffmanTree();


 BFS(&root,"");

}


int main(){

 vector<int> test;
 test.push_back(1);
 test.push_back(2);
 test.push_back(3);
 test.push_back(4);
 vector<int>::iterator i1 = test.begin();
 test.erase(i1);


 getHuffmanCode();
 return 0;
}

