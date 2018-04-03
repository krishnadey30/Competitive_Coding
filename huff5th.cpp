/*
    Name: Krishna Kumar Dey
    Institute: Indian Institute Of Information Technology, Chittoor,Sri City
*/
#include <bits/stdc++.h>
using namespace std;

struct Nodes
{
	int freq;
	char data;
	struct Nodes *left,*right;
	Nodes(int f,char data);
	void leftchild(Nodes *l);
	void rightchild(Nodes *r);
};
Nodes::Nodes(int f,char d)
{
	freq=f;
	data=d;
	left=right=NULL;
}
void Nodes::leftchild(Nodes *l)
{
	left=l;
}
void Nodes::rightchild(Nodes *r)
{
	right=r;
}
struct compare
{
	bool operator()(Nodes* l,Nodes* r) 
	{
		return (l->freq > r->freq);
	}
};

void print_huffmancodes(Nodes *root,map<char,string>* codes,string y)
{
	if(!root)
		return;
	if(root->data!='~')
	{
		(*codes)[root->data]=y;
	}
	print_huffmancodes(root->left,codes,y+"0");
	print_huffmancodes(root->right,codes,y+"1");
}

void Create_Huffman_tree(char data[],int freq[],int n)
{
	struct Nodes *left,*right,*top,*x;
	priority_queue<Nodes *, vector<Nodes *>,compare>queue;
	for (int i = 0; i < n; i++)
	{
		x=new Nodes(freq[i],data[i]);
		queue.push(x);
	}
	while(queue.size()!=1)
	{
		left=queue.top();
		queue.pop();
		right=queue.top();
		queue.pop();
		x=new Nodes((left->freq+right->freq),'~');
		(*x).leftchild(left);
		(*x).rightchild(right);
		queue.push(x);
	}
	top=queue.top();
	map<char,string>codes;
	print_huffmancodes(top,&codes,"");
	for (int i = 0; i < n; i++)
	{
		cout<<codes[data[i]]<<endl;
	}
}
int main()
{
	int t;
   	cin>>t;
    while(t--)
    {
    	int N;
    	cin>>N;
    	char data[N];
    	int freq[N];
    	for (int i = 0; i < N; ++i)
    	{
    		cin>>data[i]>>freq[i];
    	}
    	Create_Huffman_tree(data,freq,N);
    }
    return 0;	
}