#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include"entry.h"
#include<fstream>
#include<set>


using namespace std;



struct node{

	entry *point;
	struct node* parent;
	struct node* left;
	struct node* right;
	int height;
};

struct node* root = NULL;


void preOrder(struct node *Node) 
{ 

    if(Node != NULL) 
    { 
        cout<<Node->point->getword()<<"  THe height is:  "<<Node->height<<endl; 
        preOrder(Node->left); 
        preOrder(Node->right); 
    } 
    
} 

int max(int a, int b){
	
	if(a>=b){
		return a;
	}

	else {
		return b;
	}
}

void renewheight(struct node *Node){

	while(Node!=root){
	

		if(Node->parent->left==NULL){
		
			Node->parent->height=1+Node->height;
		}	
		
		else if(Node->parent->right==NULL){
			
			Node->parent->height=1+Node->height;
		}
		else{
		
			Node->parent->height=1+max(Node->parent->left->height, Node->parent->right->height);
		} 
		
		Node=Node->parent;
	}
}


void maintainheight(struct node *Node){


	
	if(Node !=NULL){
		
		if(Node->left==NULL && Node->right==NULL){
			Node->height=0;
		}
		
		else if(Node->left==NULL){
			Node->height=1+Node->right->height;
			maintainheight(Node->right);
		}
		
		else if(Node->right==NULL){
			Node->height=1+Node->left->height;
			maintainheight(Node->left);
		}	
				
		else{
			Node->height=1+max(Node->left->height, Node->right->height);
			maintainheight(Node->left);
			maintainheight(Node->right);

		
		}	
		
	}

}


int getBalance(struct node *N= new struct node) 
{ 

	if(N==NULL){
		return 0;
	}
	else if(N->left==NULL){
		return 0-N->right->height-1;
	}
	else if(N->right==NULL){
		return N->left->height-0+1;
	}
	
	return N->left->height-N->right->height;
} 


void right(struct node* tnode= new struct node){
	
	struct node* y=tnode->left;
	struct node* x=y->left;

	if(tnode->parent==NULL){
		
		y->parent = NULL;
		root = y;
	}	
	else{
		y->parent=tnode->parent;

		if(tnode->point->getword()<tnode->parent->point->getword()){
			tnode->parent->left=y;
		}
		else{
			tnode->parent->right=y;
		}
	
	}
	
		tnode->left=y->right;
		
		if(y->right!=NULL){
			y->right->parent=tnode;
		}
		
		tnode->parent=y;
		y->right = tnode;
	
		
	maintainheight(root);

}

void left(struct node* tnode= new struct node){

 	struct node* y=tnode->right;
	struct node* x=y->right;

	if(tnode->parent==NULL){
		
		y->parent = NULL;
		root = y;
	}	
	else{
		y->parent=tnode->parent;
		if(tnode->point->getword() > tnode->parent->point->getword()){
			tnode->parent->right=y;
		}
		else{
			tnode->parent->left=y;
		}
	}
	
		tnode->right=y->left;
		
		if(y->left!=NULL){
			y->left->parent=tnode;
		}
		
		tnode->parent=y;
		y->left = tnode;
			
		
	maintainheight(root);	
	
	
}

void rightleft(struct node* tnode= new struct node){
	
	struct node* z=tnode->right;

	struct node* y1=z->left;
	
	tnode->right=y1;
	y1->parent=tnode;
	z->left=y1->right;
	if(y1->right!=NULL){
		y1->right->parent=z;
	}
	z->parent=y1;
	y1->right=z;	

	if(tnode->parent==NULL){
		y1->parent=NULL;
		root=y1;
	}
	else{
		y1->parent=tnode->parent;
		if(tnode->point->getword() > tnode->parent->point->getword()){
		
			tnode->parent->right=y1;
		}
		else{
			tnode->parent->left=y1;	
		}
	}
	
	tnode->right=y1->left;
	if(y1->left!=NULL){
		y1->left->parent=tnode;
	}

	tnode->parent=y1;
	y1->left=tnode;
	
	
	maintainheight(root);
}

void leftright(struct node* tnode= new struct node){
	
	struct node* z=tnode->left;

	struct node* y1=z->right;
	
	tnode->left=y1;
	y1->parent=tnode;
	z->right=y1->left;
	if(y1->left!=NULL){
		y1->left->parent=z;
	}
	z->parent=y1;
	y1->left=z;	

	if(tnode->parent==NULL){
		y1->parent=NULL;
		root=y1;
	}
	else{
		y1->parent=tnode->parent;
		if(tnode->point->getword() < tnode->parent->point->getword()){
		
			tnode->parent->left=y1;
		}
		else{
			tnode->parent->right=y1;	
		}
	}
	
	tnode->left=y1->right;
	if(y1->right!=NULL){
		y1->right->parent=tnode;
	}

	tnode->parent=y1;
	y1->right=tnode;

	maintainheight(root);

}




//word comparison function
//add function manually

int addword(struct node* tempnode= new struct node){

	if (root==NULL){
		
		root=tempnode;
		maintainheight(root);
		return 1;
	}
	struct node* currnode =new struct node;
	currnode=root;
	
	while(1){
		
		if((currnode->point->getword().compare(tempnode->point->getword()))==0){
			
			currnode->point->getmeaning(tempnode->point->getmeaning());
			return 0;
		}
		else if((currnode->point->getword().compare(tempnode->point->getword()))<0){
			
			if(currnode->right==NULL){
			
				tempnode->parent=currnode;
				currnode->right=tempnode;
				break;
			}

			currnode=currnode->right;
		}
		else if((currnode->point->getword().compare(tempnode->point->getword()))>0){
			
			if(currnode->left==NULL){
				
				tempnode->parent=currnode;
				currnode->left=tempnode;
				break;
			}

			currnode=currnode->left;
		}
	}
	
	struct node* tnode= new struct node;
	tnode=tempnode;
	
	renewheight(tempnode);
	maintainheight(root);
	
	tnode=tempnode->parent;
	
	int balance;
	
	while(1){
	
	
		balance=getBalance(tnode);
		
		
		//Left Left Case
		if (balance > 1 && (tnode->left->point->getword()) > tempnode->point->getword()){ 
        		
        		right(tnode);
        		renewheight(tnode);
        		break;
        		 
	  	}
		// Right Right Case 
		if (balance < -1 && (tnode->right->point->getword()) < tempnode->point->getword()){ 
	      	//return leftRotate(node); 
	  		
	  		left(tnode);
	  		renewheight(tnode);
	  		break;
	  	}
		// Left Right Case 
		if (balance > 1 && (tnode->left->point->getword()) < tempnode->point->getword()) 
	    	{ 
	      	leftright(tnode);
	      	 renewheight(tnode);
	      	//return rightRotate(node); 

	      	break;
	    	} 
	  
	    	// Right Left Case 
	    	if (balance < -1 && (tnode->right->point->getword()) > tempnode->point->getword()) 
	    	{ 
	    	
	    		rightleft(tnode);
	    		renewheight(tnode);
	      	//node->right = rightRotate(node->right); 
	      	//return leftRotate(node); 


	    		break;
	    	} 
		
		
		if(tnode==root){
			maintainheight(root);
			break;
		}
		tnode=tnode->parent;
	}	


	return 1;

}


void search(string word){

	struct node* currnode=new struct node;
	currnode=root;
	while(1){
	
		if(currnode->point->getword()==word){
			cout<<"The word was found and its meaning is: "<<endl<<endl;
			cout<<currnode->point->getmeaning()<<endl<<endl<<endl;
			break;
		}
		else if(currnode->point->getword() < word && currnode->right!=NULL){
			currnode=currnode->right;
		}
		else if(currnode->point->getword() > word && currnode->left!=NULL){
			currnode=currnode->left;
		}
		else{
			cout<<"Sorry, no such word in the dictionary."<<endl<<endl<<endl;
			break;
		}
	}

}

//remove funtion manually

int removeword(string tempword){

	struct node* currnode =new struct node;
	currnode=root;

	while(1){
		
		if((tempword > currnode->point->getword())){
			
			if(currnode->right!=NULL){
				currnode=currnode->right;
			}
			
			else{
				cout<<"There is no such word in the dictionary."<<endl<<endl;
				return 0;
			}
			
		}
		else if((tempword < currnode->point->getword())){
		
			if(currnode->left!=NULL){
				currnode=currnode->right;
			}
			
			else {
				cout<<"There is no such word in the dictionary."<<endl<<endl;
				return 0;
			}
		}
		else if((tempword == currnode->point->getword())){
		
			if(currnode==root){
				cout<<"The list is now empty."<<endl<<endl;
				return 1;
			}
			break;
		}
		else{
			cout<<"There is no such word in the dictionary."<<endl<<endl;
			return 0;
		}
		
	}
	
	struct node* tnode =new struct node;
	tnode=currnode;

	if(tnode->left==NULL && tnode->right==NULL){
		tnode=tnode->parent;
		
		if(tempword > tnode->point->getword()){
			tnode->right->parent=NULL;	
			tnode->right=NULL;
			
		}
		
		else if(tempword < tnode->point->getword()){
			tnode->left->parent=NULL;	
			tnode->left=NULL;
		
		}
	}

	else if(tnode->left!=NULL){
		
		tnode=currnode->left;	

		while(tnode->right!=NULL){
			tnode=tnode->right;
		}

		currnode->point->getword(tnode->point->getword());
		currnode->point->getmeaning(tnode->point->getmeaning());	

		tnode=tnode->parent;
	
		tnode->right->parent=NULL;
		tnode->right=NULL;	
	}


	else if(tnode->right!=NULL){

		tnode=currnode->right;	
		while(tnode->right!=NULL){
			tnode=tnode->left;
		}	
		currnode->point->getword(tnode->point->getword());
		currnode->point->getmeaning(tnode->point->getmeaning());	
	
		tnode=tnode->parent;
	
		tnode->left->parent=NULL;
		tnode->left=NULL;	
		
	}	


	
	
	renewheight(tnode);
	maintainheight(root);
	
	int balance;	
	
	while(1){
	
	
		balance=getBalance(tnode);
		
		
		//Left Left Case
		if (balance > 1 && (tnode->left->point->getword()) > tempword){ 
        		
        		right(tnode);
        		renewheight(tnode);
        		if(tnode==root){
        			break;
        		}
        		
        		 
	  	}
		// Right Right Case 
		if (balance < -1 && (tnode->right->point->getword()) < tempword){ 
	      	//return leftRotate(node); 
	  		
	  		left(tnode);
	  		renewheight(tnode);
        		if(tnode==root){
        			break;
        		}
	  	}
		// Left Right Case 
		if (balance > 1 && (tnode->left->point->getword()) < tempword) 
	    	{ 
	      	leftright(tnode);
	      	 renewheight(tnode);
	      	//return rightRotate(node); 
        		if(tnode==root){
        			break;
        		}
	    	} 
	  
	    	// Right Left Case 
	    	if (balance < -1 && (tnode->right->point->getword()) > tempword) 
	    	{ 
	    	
	    		rightleft(tnode);
	    		renewheight(tnode);
	      	//node->right = rightRotate(node->right); 
	      	//return leftRotate(node); 
        		if(tnode==root){
        			break;
        		}
	    	} 
		
		
		if(tnode->parent==NULL){
			maintainheight(root);
			break;
		}
		tnode=tnode->parent;
	}
	
	return 1;	
		
}




int main(){

	int choice=1;

	int size=0;
	
	int flag;
	set<string> myset;
	
	while(choice!=0)
	{
		
		string word;
		string meaning;
		
		cout<<"1. Press 1 to enter the words manually in the AVL Tree."<<endl;	//Done
		cout<<"2. Press 2 to enter the words from a file in the AVL Tree"<<endl; //Done
		cout<<"3. Press 3 to remove a word from the AVL Tree."<<endl;
		cout<<"4. Press 4 to display the size of the AVL Tree."<<endl;  // Done
		cout<<"5. Press 5 to search for a word in the AVL Tree."<<endl;	//Done
		cout<<"6. Press 6 to display all the words in between two words."<<endl; //Done
		cout<<"7. Press 7 to display Pre-Order of the AVL TREE."<<endl; //Done
	
		cin>>choice;
	
		if(choice==1){
			
			
			//if the word is already present update its meaning.
			//if the word is not present then add the word in the dictionary.
			cout<<"Enter the word: "<<endl;
			cin>>word;
			cout<<"Enter the meaning: "<<endl;
			cin>>meaning;
			
			myset.insert(word);
			struct node* avltree =new struct node;
			entry* tempobject=new entry(word, meaning);
			avltree->point = tempobject;
			avltree->parent = NULL;
			avltree->left = NULL;
			avltree->right = NULL;
			avltree->height=0;
			flag=addword(avltree);
		
			if(flag==1){
				size++;
			}
		}
	
		else if(choice==2){
			
			//if the word is already present update its meaning.
			//if the word is not present then add the word in the dictionary.
			string input;
			cout<<"Enter the name of .txt file. Example 'abc.txt' "<<endl;
			cin>>input;

			fstream fin;
			fin.open(input.c_str(), ios::in);
			
			if(fin==NULL){
				cout<<"No such file present in this folder."<<endl<<endl;
			}
			
			while(fin>>word){	
				
				cout<<word<<endl;
				getline(fin, meaning);
				
				myset.insert(word);
				struct node* avltree =new struct node;
				entry* tempobject=new entry(word, meaning);
				avltree->point = tempobject;
				avltree->parent = NULL;
				avltree->left = NULL;
				avltree->right = NULL;
				avltree->height=0;
				flag=addword(avltree);
			
				if(flag==1){
					size++;
				}
				
			}		

		}
			
		else if(choice==3){
			cout<<"Enter the word you want to delete: "<<endl;
			cin>>word;
			
			flag=removeword(word);
			if(flag==1){
				size--;
			}
			
		}
		
		else if(choice==4){
			cout<<"The Size of the AVL tree is:  "<<size<<endl;
		}
		
		else if(choice==5){
			cout<<"Enter the word you want to search."<<endl;
			string searchword;
			cin>>searchword;
			search(searchword);
		}
		
		else if(choice==6){
			cout<<"Enter the two words."<<endl;
			string word1;
			cin>>word1;
			
			string word2;
			cin>>word2;
			
			int i;
			cout<<"The words are:"<<endl;
			set <string> :: iterator itr;
			
			for(itr = myset.begin(); itr != myset.end(); ++itr){
			
				if((*itr) <= word2 && (*itr) >= word1){
					cout<<*itr<<endl;
				}
			}

		}
		
		else if(choice==7){
		
			preOrder(root);
		}
		else if(choice==0){
			break;
		}
		
		else{
			
			cout<<endl<<"No valid choice was entered."<<endl<<endl<<endl;
			
		}
		
	}
}
