#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
	ll value;
	node *lchild,*rchild;
};
node* create(ll arr[],ll lower,ll high)
{
	if(lower==high)
	{
		node *leaf=new node;
		leaf->value=arr[lower];
		leaf->lchild=leaf->rchild=NULL;
		return leaf;
	}
	node *lch=create(arr,lower,(lower+high)/2);
	node *rch=create(arr,(lower+high)/2 +1,high);
	node *temp=new node;
	temp->value=lch->value+rch->value;
	temp->lchild=lch;
	temp->rchild=rch;
	return temp;
}
ll query(node *root,ll lower,ll high,ll l,ll h)
{
	if(l==lower && h==high)
		return root->value;
	ll mid=(lower+high)/2;
	if(h>mid)
	{
		if(l>mid)
		{
			return query(root->rchild,mid+1,high,l,h);
		}
		return query(root->lchild,lower,mid,l,mid)+query(root->rchild,mid+1,high,mid+1,h);
	}
	else
	{
		return query(root->lchild,lower,mid,l,h);
	}
}
void update(node *root,ll lower,ll high,ll index,ll value)
{
	if(lower==index && high==lower)
	{
		root->value=value;
		return;
	}
	ll mid=(lower+high)/2;
	if(index>mid)
	{
		update(root->rchild,mid+1,high,index,value);
	}
	else
	{
		update(root->lchild,lower,mid,index,value);
	}
	root->value=root->lchild->value+root->rchild->value;
	return;
}
int main()
{
	ll n,arr[100000],q,qt,l,h;
	cin>>n;
	for (ll i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	node *root;
	root=create(arr,0,n-1);
	//print(root);
	cin>>q;
	for (ll i = 0; i < q; i++)
	{
		cin>>qt;
		if(qt==1)
		{
			cin>>l>>h;
			cout<<query(root,0,n-1,l,h)<<endl;
		}
		else
		{
			cin>>l>>h;
			update(root,0,n-1,l,h);
		}
	}
	return 0;
}