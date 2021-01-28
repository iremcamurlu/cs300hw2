#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include<fstream>
#include<vector>
#include <iomanip>
#include <sstream>
//NAZLI IREM CAMURLU HW2
using namespace std;
struct DocumentItem//struct to store the document name and count of each file
{
	string documentName;
	int count;
};
struct WordItem //struct to store the words and their document names and counts
{
	string word;
	DocumentItem worder1;//document items put into the struct to store the document name and count info of each word
	DocumentItem worder2;
	DocumentItem worder3;
	DocumentItem worder4;
	DocumentItem worder5;
	DocumentItem worder6;
};
struct AvlNode//avl tree node that has a left pointer node right pointer node word item element and height information
{
WordItem elem;
AvlNode *left;
AvlNode *right;
int height;
};
	AvlNode *root;//root initialized
template <class Key>
class AvlSearchTree
{

	//AvlNode<Key,Value>*clone();
AvlNode * find( const string & x,AvlNode *t)const//find function to find the searched query
	{
		if ( t == NULL )

			return NULL;

		else if( x < t->elem.word )//if the element searched is smaller alphabetically recursively go to left

			return find( x, t->left );

		else if( t->elem.word < x )//if the element searched is bigger alphabetically recursively go to right

			return find( x, t->right );

		else

			return t ; //if found return
	}


void insert( const string & x,const string & y,AvlNode *&t)//insert function to insert the new words in the tree
{
		
	if(t==NULL)//if the word havent been found in the tree than initialize a new node
	{
		int a =0;
		t = new AvlNode;
		t->elem.word=x;
		t->elem.worder1.documentName=y;
		t->height=0;
		t->left=NULL;
		t->right=NULL;
		t->elem.worder1.count=1;
	}
	
	
	else if(x==t->elem.word)//if the element is found before than initialize new document item or if the document name is the same than increase the counter
	{
			if(t->elem.worder1.documentName==y)
			{
			
			t->elem.worder1.count++;
			}
			else if(t->elem.worder2.documentName==y)
			{
				t->elem.worder2.count++;
			}
			else if(t->elem.worder3.documentName==y)
			{
				t->elem.worder3.count++;
			}
			else if(t->elem.worder4.documentName==y)
			{
				t->elem.worder4.count++;
			}
			else if(t->elem.worder5.documentName==y)
			{
				t->elem.worder5.count++;
			}
			else if(t->elem.worder6.documentName==y)
			{
				t->elem.worder6.count++;
			}
			else if(t->elem.worder2.documentName=="")
			{
				t->elem.worder2.documentName=y;
				t->elem.worder2.count=1;
			}
			else if(t->elem.worder3.documentName=="")
			{
				t->elem.worder3.documentName=y;
				t->elem.worder3.count=1;
			}
			else if(t->elem.worder4.documentName=="")
			{
				t->elem.worder4.documentName=y;
				t->elem.worder4.count=1;
			}
			else if(t->elem.worder5.documentName=="")
			{
				t->elem.worder5.documentName=y;
				t->elem.worder5.count=1;
			}
			else if(t->elem.worder6.documentName=="")
			{
				t->elem.worder6.documentName=y;
				t->elem.worder6.count=1;
			}


		
	}
	else if (x<t->elem.word)//if the word searched for is smaller alphabetically go to left recursively
	{
		insert(x,y,t->left);
		

	}
	else if(x>t->elem.word)////if the word searched for is bigger alphabetically go to right recursively
	{
		insert(x,y,t->right);
	

	}
	
	balance(t);//balance the tree
}

AvlNode* rotateWithLeftChild( AvlNode * & k2 )//single left rotation 
{
	
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
	k1->height = max( height( k1->left ), k2->height ) + 1;
	k2 = k1;
	return k2;
}
AvlNode*  rotateWithRightChild( AvlNode * & k2 )//single right rotation
{
	AvlNode *k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max( height( k2->right ), height( k2->left ) ) + 1;
	k1->height = max( height( k1->right ), k2->height ) + 1;
	k2 = k1;
	return k2;
}
AvlNode*  doubleWithLeftChild( AvlNode * & k3 )//double rotation if right left rotation is needed recursively
{
	rotateWithRightChild( k3->left );
	rotateWithLeftChild( k3 );
	return k3;
}
AvlNode* doubleWithRightChild( AvlNode * & k3 )//double rotation if left right rotation is needed recursively
{
	rotateWithLeftChild( k3->right );
	rotateWithRightChild( k3 );
	return k3;
}
AvlNode*  balance(AvlNode*&t)//balance function to make sure our tree is an avl tree in the proper way.
{
	if( t == nullptr )
         return t;

	if( height( t->left ) - height( t->right ) > 1 )//if the difference between height in the left node and the  right node is bigger than 1 
		if( height( t->left->left ) >= height( t->left->right ) )//if height in the left child left subtree node is bigger than the height in the left child and right subtree
			rotateWithLeftChild( t );//single rotation is enough
		else
			doubleWithLeftChild( t );//else double rotation is needed
	else
	if( height( t->right ) - height( t->left ) > 1 )//if the difference between height in the right node and the  left node is bigger than 1 
		if( height( t->right->right ) >= height( t->right->left ) )//if height in the right child right subtree node is bigger than the height in the right child and left subtree
			rotateWithRightChild( t );//single rotaton is enough
		else
			doubleWithRightChild( t );//else double rotation is needed

t->height = max( height( t->left ), height( t->right ) ) + 1;//to update the height we take the maximum height of the left node and right node and increase by 1 as the leaf nodes are considered as 0.
return t;

}
int height(AvlNode*t)const//height function if T is null the height is zero else we get the height of the function
{
	 if (t == NULL)
	return -1;
	
      return t->height;
}

AvlSearchTree * clone( AvlNode *t ) const//copy constructor function to clone the avltree if needed
{
if( t == nullptr )
return nullptr;
else
return new AvlNode{ t->elem, clone( t->left ), clone( t->right )};
}
void makeEmpty(AvlNode* t)//to destruct the tree recursively right and left trees are destructed
{
       if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
}

public:
	AvlSearchTree()//constructor
	{
		root=nullptr;
	}
	

	AvlSearchTree(const AvlSearchTree&rhs)//copy constructor
	{
		root = clone( rhs.root );
	}

	~AvlSearchTree()//destructor
	{
		makeEmpty(root);
	}
	void insert_tree(Key x,Key y)//insert function
	{

		insert(x,y,root);
	}
	void finder(Key x)//public find function to reach to find function in private
	{
			AvlNode*root_x;
			root_x=find(x,root);//node is found
			if(root_x!=NULL)//if it is not NULL then cout the document names and counts of the searched word
			{
				if(root_x->elem.worder1.count>0)
				{
					cout<<"in Document "<<root_x->elem.worder1.documentName<<","<<x<<"  found "<<root_x->elem.worder1.count<<" times."<<endl;

				}
				if(root_x->elem.worder2.count>0)
				{
					cout<<"in Document "<<root_x->elem.worder2.documentName<<","<<x<<"  found "<<root_x->elem.worder2.count<<" times."<<endl;

				}
				if(root_x->elem.worder3.count>0)
				{
					cout<<"in Document "<<root_x->elem.worder3.documentName<<","<<x<<"  found "<<root_x->elem.worder3.count<<" times."<<endl;

				}
				if(root_x->elem.worder4.count>0)
				{
					cout<<"in Document "<<root_x->elem.worder4.documentName<<","<<x<<"  found "<<root_x->elem.worder4.count<<" times."<<endl;

				}
				if(root_x->elem.worder5.count>0)
				{
					cout<<"in Document "<<root_x->elem.worder5.documentName<<","<<x<<"  found "<<root_x->elem.worder5.count<<" times."<<endl;

				}
				if(root_x->elem.worder6.count>0)
				{
					cout<<"in Document "<<root_x->elem.worder6.documentName<<","<<x<<"  found "<<root_x->elem.worder6.count<<" times."<<endl;

				}
			

		}
			else
			{
				cout<<"No document contains the given query"<<endl;//if not found cout that is not found
			}


	}



};
string checkcharacter(string &word)//character check function to make sure all the characters are lowercase.
{
		int len = word.length();
		for(int i=0 ;i<len;i++){
			
		if (word[i] <= 'Z' && word[i] >= 'A')
        word[i]= word[i] + 32;
	
			}
return word;
}

int main()
{
	AvlSearchTree<string> myTree;//tree is initialized
	ifstream input;
	string line;
	string word;
	
	int num_files;
	string file_name;
	cout<<"Enter number of input files: ";
	cin>>num_files;
	for(int i =0;i<num_files;i++)//continue until all the file information is inserted into the tree.
	{
		cout<<"Enter "<<i+1<<". file name: ";
		cin>>file_name;
		input.open(file_name.c_str());
		while(getline(input,line))
		{
			istringstream stringStream(line);
			while(stringStream>>word)//while we get the input from the file is  inserted to the tree
			{
				word = checkcharacter(word);
				myTree.insert_tree(word,file_name);
			}
			
		}
		input.close();

		
	}
	cin.ignore();
	string keyword="";
	cout<<"Enter queried words in one line: ";//asking and getting the search words from the user
	while(getline(cin,keyword))
	{
	istringstream stream(keyword);
	string tempWord;
	while(stream>>tempWord)//initialized a string stream to make sure we get word by word if the user enters multiple words
	{
		checkcharacter(tempWord);//first make sure all the characters of the given string is lowercase
		myTree.finder(tempWord);//then find the corresponding node of the searched word.
	}

	}
	

}
