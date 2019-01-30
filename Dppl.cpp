#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
void add(Node* head,int x){
    Node* newNode=new Node;
	Node* cur=head;
	while(cur->next!=NULL){
        if(cur->data==x) return;
        cur=cur->next;
	}
    if(cur->data==x)
        return;
    newNode->data=x;
    newNode->next=NULL;
    cur->next=newNode;
}
struct Node* build(int *arr,int length){
	Node* head=new Node;
	head->data=0;
	head->next=NULL;
	int i=0;
	while(i<length){
		add(head,arr[i]);
		i++;
	}
	return head;
}
void enumeratee(struct Node* head){
	Node* temp=head->next;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
int cardinality(Node* head){
	int c=0;
	Node* temp=head;
	while(temp->next!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}
void isEmpty(Node* head){
	if(head->next==NULL) cout<<"Set is NULL\n";
	else cout<<"Set isn't NULL\n";
}
bool is_element_of(Node* head,int x){
	Node* temp=head->next;
	while(temp!=NULL){
		if(temp->data==x) return true;;
		temp=temp->next;
	}
    return false;
}
void remove(Node* head,int x){
	Node* temp=head;
	while(temp->next!=NULL){
		if(temp->next->data==x){
			temp->next=temp->next->next;
			return;
		}
		temp=temp->next;
	}
}
bool is_empty_(struct Node *head){
if(head->next==NULL) return true;
return false;
}
struct Node* unin(struct Node *headx,struct Node *heady){
    Node *head = new Node;
    head->data = 0;
    head->next = NULL;
    Node* cur=headx->next;
    while(cur!=NULL){
        add(head,cur->data);
        cur=cur->next;
    }
    cur=heady->next;
    while(cur!=NULL){
        add(head,cur->data);
        cur=cur->next;
    }
    return head;
}
struct Node* diff(struct Node *headx,struct Node *heady){
    Node *head = new Node;
    head->data = 0;
    head->next = NULL;
    Node* cur=headx->next;
    while(cur!=NULL){
        if(!is_element_of(heady,cur->data)) add(head,cur->data);
        cur=cur->next;
    }
    return head;
}

bool Subset(struct Node *headx,struct Node *heady){
    Node* cur=heady->next;
    while(cur!=NULL){
        if(!is_element_of(headx,cur->data)) return false;
        cur=cur->next;
    }
    return true;
}
struct Node* Intersection(struct Node* headx,struct Node* heady){
    Node *head = new Node;
    head->data = 0;
    head->next = NULL;
    Node* cur=headx->next;
    while(cur!=NULL){
        if(is_element_of(heady,cur->data))
            add(head,cur->data);
        cur=cur->next;
    }
    return head;
}
    
int main()
{
	int a[5] , b[5] ;
    cout<<"\nEnter the elements of first set\n";
    for(int i=0;i<5;i++)
        cin>>a[i];
    cout<<"\nEnter the elements of second set\n";
    for(int j=0;j<5;j++)
        cin>>b[j];
	Node* head1=build(a,5);
	Node* head2=build(b,5);
	cout<<"First Set elements: ";
	enumeratee(head1);
	cout<<"\n";
	cout<<"Second Set elements: ";
	enumeratee(head2);
	cout<<"\n";
	cout<<"\n";
    cout<<"\nEnter Your Choice\n";
    cout<<"1.Cardinality 2.Deletion 3.Union  4.Intersection  5.Difference 6.Check if First is Subset of Second  7.Display 0.Exit\n";
    int choice , num;
    cin>>choice;
    while(choice!=0)
    {
        if(choice==1)
        {
            cout<<"The Cardinality of first and second set respectively are : "<<cardinality(head1)<<" "<<cardinality(head2);
        }
        else if(choice==2)
        {
            cout<<"\nEnter The Choice to delete the element of which set 1.First Set 2.Second Set\n";
            cin>>choice;
            if(choice==1)
            {
                cout<<"\nEnter the Number to be removed \n";
                cin>>num;
                remove(head1,num);
            }
            else
            {
                cout<<"\nEnter the number to be deleted\n";
                cin>>num;
                remove(head2,num);
            }

        }
        else if(choice==3)
        {
            Node* headxx=unin(head1,head2);
	        cout<<"Union is: ";
	        enumeratee(headxx);
        }
        else if(choice==4)
        {
           	Node *headxx=Intersection(head1,head2);
	        cout<<"Intersection is: ";
	        enumeratee(headxx);
        }
        else if(choice==5)
        {
            Node *difference=diff(head1,head2);
            cout<<"Difference is:";
            enumeratee(difference);
        }
        else if(choice==6)
        {
            if(Subset(head2,head1))
                cout<<"\nFirst is Subset of Second\n";
            else if(Subset(head1,head2))
            {
                cout<<"\nSecond is a subset of First\n";
            }
            

        }
        else if(choice==7)
        {
            enumeratee(head1);
            cout<<"\n";
            enumeratee(head2);
            cout<<"\n";
        }
        else if(choice==0)
            break;
        cout<<"\nEnter Your choice Again\n";
        cout<<"\n1.Cardinality 2.Deletion 3.Union  4.Intersection  5.Difference 6.Subset Check 7.Display 0.Exit\n";
        cin>>choice;
    }

}
