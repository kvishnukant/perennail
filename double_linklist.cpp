#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	int data;
	node *next;
	node *pre;
	public:
	node(int);
	int getdata();
	void setdata(int);
	void setnext(node*);
	node * getnext();
	void setpre(node*);
	node *getpre();
};
node::node(int data)
{
	this->data=data;
	this->next=NULL;
	this->pre=NULL;
}
int node::getdata()
{
	return data;
}
void node::setdata(int data)
{
	this-> data=data;
}
node *node::getnext()
{
	return next;
}
void node::setnext(node *next)
{
	this->next=next;
}
node *node::getpre()
{
	return pre;
}
void node::setpre(node *pre)
{
	this->pre=pre;
}
class doublelink
{
	node *start;
	public:
	doublelink();
	void insertbeg(int);
	void traversefront();
	void insertend(int);
	void insertpos(int,int);
	void deletebeg();
	void deleteend();
	void deletepos(int);
};
doublelink::doublelink()
{
	start=NULL;
}
void doublelink::insertbeg(int data)
{
	node *temp=new node(data);
	if(start!=NULL)
	{
	start->setpre(temp);
	}
	temp->setnext(start);
	start=temp;
	temp->setpre(NULL);
}
void doublelink::insertend(int data)
{
	node *temp=new node(data);
	node *p=start;
	while(p->getnext()!=NULL)
		p=p->getnext();
	        p->setnext(temp);
		temp->setpre(p);

}
void doublelink::traversefront()
{
	node *p=start,*temp;
	if(start==NULL)
	{
		cout<<"no data "<<"\n";
		return ;
	}

	while(p!=NULL)
	{
		cout<<p->getdata()<<"\t";	
		temp=p;
		p=p->getnext();
	}
	cout<<"\n";
	while(temp!=NULL)
	{
		cout<<temp->getdata()<<"\t";
		temp=temp->getpre();
	}
	cout<<"\n";
}
void doublelink::insertpos(int data,int pos)
{
	int i=1;
	if(start==NULL||pos==1)
	{
		insertbeg(data);
		return ;
	}
	node *temp=new node(data);
	node *p=start,*t;
	while(p->getnext()!=NULL)
	{
		if(i==pos-1)
		
		{
			t=p->getnext();
			t->setpre(temp);
			temp->setnext(p->getnext());
			temp->setpre(p);
			p->setnext(temp);
			return ;
		}
		i++;
		p=p->getnext();
	}
	p->setnext(temp);
	temp->setpre(p);


}
void doublelink::deletebeg()
{
	node *p=start;
	if(start==NULL)
	{
		cout<<"no data"<<"\n";
		return ;
	}
	start=start->getnext();
	start->setpre(NULL);
	delete p;
}
void doublelink::deleteend()
{
	if(start==NULL)
	{
		cout<<"no data"<<"\n";
		return ;
	}
	node *p=start;
	while(p->getnext()->getnext()!=NULL)
	{
		p=p->getnext();
	}
	delete p->getnext();
	p->setnext(NULL);
}
void doublelink::deletepos(int pos1)
{
	int i=1;
	if(start==NULL)
	{
		cout<<"no data"<<"\n";
	}
	node *p=start,*t;
	while(p->getnext()!=NULL)
	{
		if(p->getnext()->getnext()==NULL)
		{
			deleteend();
			return ;
		}
		if(i==pos1-1)
		{
			t=p->getnext()->getnext();
			delete p->getnext();
			p->setnext(t);
			t->setpre(p);
			return ;
		}
		i++;
		p=p->getnext();
	}
}
		
int main()
{
	int da,x=1,pos;
	doublelink l;
	while(x!=0)
	{
	cout<<"enter the choice"<<"\n"<<"1 for insert at begning"<<"\n"<<"2 for insert at end"<<"\n"<<"3 for traverse"<<"\n"<<"4 for insert at any position"<<"\n"<<"5 for delete from front"<<"\n"<<"6 for delete from end"<<"\n"<<"7 for delete at position"<<"\n"<<"0 for exit"<<"\n";
		cin>>x;
		switch (x)
		{
			case 1:
				cout<<"enter the number"<<"\n";
				cin>>da;
				l.insertbeg(da);
				break;
			case 2:
				cout<<"enter the number"<<"\n";
				cin>>da;
				l.insertend(da);
				break;
			case 3:
				l.traversefront();
				break;
			case 4:
				cout<<"enter the number"<<"\n";
				cin>>da;
				cout<<"enter the position"<<"\n";
				cin>>pos;
				l.insertpos(da,pos);
			case 5:
				l.deletebeg();
				break;
			case 6:
				l.deleteend();
				break;
			case 7:
				cout<<"enter the position"<<"\n";
				cin>>pos;
				l.deletepos(pos);
				break;
			case 0:
				break;
			default :
				cout<<"invalid input"<<"\n";
		}
	}
	return 0;
}

