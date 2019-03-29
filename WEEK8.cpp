
#include<iostream>
#include<queue>
using namespace std;
class node{
public:
int data;
node*left;
node*right;
node*parent;
node(int value){
data=value;
left=NULL;
right=NULL;
parent=NULL;
}
};
class BST{
public:
node*root;
//constructor
BST(){
root=NULL;
}
void insert1(node*current,int value){
if(current==NULL){current=new node(value);
root=current;
root->parent=NULL;
//return root;
}
else if(value>current->data){
    if(current->right==NULL){current->right=new node(value);
       current->right->parent=current;
    }
    else insert1(current->right,value);
}
else{
    if(current->left==NULL){current->left=new node(value);
    current->left->parent=current;
    }
    else insert1(current->left,value);
}
}
void insert(int value){
insert1(root,value);
}
void display1(node*current){
if(current==NULL) return;
display1(current->left);
cout<<current->data<<"  ";
 display1(current->right);
}
void display(){
display1(root);
cout<<endl;
}
bool search3(node*current,int value){
if(current==NULL){return false;}
else if(current->data==value)
{return true;}
else if(value>current->data) return search3(current->right,value);
else if(value<current->data) return search3(current->left,value);
}
void search(int value){
    if(search3(root,value)==1)
    cout<<endl<<"the element "<<value<<" is  found in the binary search tree  ";
    else
        cout<<" The element  "<<value<<" is not found  ";
}
//function to find minimum of all values
 node*findmin1(node*current){
//take current as argument
if(current->left==NULL)
    {return current;}
else return findmin1(current->left);
}
//function to return address of min node
node* findmin(){
return findmin1(root);
}
//return min element of BST
int min(){
return findmin1(root)->data;}

//function to find the no of element present in the BST
int counte(node*current){
if(current==NULL)return 0;
else if(current!=NULL)
  return 1+counte(current->left)+counte(current->right);
}
int count(){
return counte(root);
}


void replace1(node*current,node*temp){

int x=temp->data;
temp->data=current->data;
current->data=x;
}
void replace(node*current,int value){
node*temp=new node(value);
replace1(current,temp);
}
//delete element of binary search tree
node* delete1(node*current,int value){
if(root==NULL) return root;
else if(value<current->data) current->left=delete1(current->left,value);
else if(value>current->data) current->right=delete1(current->right,value);
else{
    //desired element
    //CASE-------1
    if(current->left==NULL && current->right==NULL){
        delete current;
        current=NULL;
        return current;
    }
    //CASE--------2
    else if(current->left==NULL){
        node*temp=current;
        current=current->right;
        delete temp;
    }

    else if(current->right==NULL){
        node*temp=current;
        current=current->left;
        delete temp;
    }
   //CASE---------3
   else{
    node*temp=findmin1(current->right);
    node*as=current;
    current->data=temp->data;
     current->right=delete1(current->right,temp->data);
   }
}
  return current;
}
void Delete(int value){
if(search3(root,value)==1)
delete1(root,value);
else
    cout<<" entered no "<<value<<" is invalid"<<endl;
}
//function to find the height of
int maximum(int a,int b){
if(a>b)return b;
else return a;
}
int height(node*current){
if(root==NULL) return 0;
else if(current==NULL) return 0;
else{
    int lh=height(current->left)+1;
    int rh=height(current->right)+1;

return lh>rh?lh:rh;

}
}
void Height(){
  cout<<"  the height of tree is "<<height(root)<<endl;
}


//function to print the number between given range
void rangeprint(int value1,int value2,node*current){
    if(current==NULL) return;
 if(current->data>value1) rangeprint(value1,value2,current->left);
    if(value1<=current->data && value2>=current->data){
    cout<<current->data<< "  ";
   }
if(value2>current->data)
    rangeprint(value1,value2,current->right);

}
void Rprint(int val1,int val2){
rangeprint(val1,val2,root);
}
};

int main(){
BST b;
b.insert(6);
b.insert(5);
b.insert(3);
b.insert(8);
b.insert(4);
b.insert(10);
b.insert(9);
b.insert(13);
b.insert(14);
b.insert(18);
b.insert(17);
b.insert(16);
b.insert(15);
b.display();
b.search(5);
cout<<"the minimum element is :"<<b.findmin()->data<<endl;
cout<<"the no of element is :"<<b.count()<<endl;
cout<<endl;
b.display();
cout<<endl<<" Delete element "<<endl;
b.Delete(1);
b.display();
b.Delete(4);
cout<<endl<<"After delete element "<<endl;
b.display();
b.Height();
cout<<endl<<"the root is "<<b.root->data<<endl;
//function to print in between two range
cout<<"Print element within the range"<<endl;
b.Rprint(5,14);
return 0;
}
