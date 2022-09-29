#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int n){
        this->val=n;
        this->next=NULL;
        this->prev=NULL;
    }
};

Node* n1=new Node(10);

void insertAtStart(Node* &n,int val){
    Node* nw = new Node(val);
    nw->next=n;
    nw->prev=NULL;
    n->prev=nw;
    n=nw;
}

void insertAtEnd(Node* &n,int val){
    Node* t1=n;
    while(t1->next!=NULL)t1=t1->next;

    Node* nw=new Node(val);

    t1->next=nw;
    nw->prev=t1;
}

void insertAtPos(Node* &n,int pos,int val){

    if(pos==1){
        insertAtStart(n,val);
        return ;
    }

    int cnt=0;
    Node* t1=n;
    Node* t2;

    while(cnt!=pos-1){
        if(cnt==pos-2)t2=t1;
        t1=t1->next;
        cnt++;
    }

    if(t1==NULL){
        insertAtEnd(t1,val);
        return;
    }

    Node* nw = new Node(val);

    t2->next=nw;
    nw->prev=t2;
    t1->prev=nw;
    nw->next=t1;

}

void delNode(Node*&n,int pos){
    if(pos==1){
        n->next->prev=NULL;
        n=n->next;
        return ;
    }

    int cnt=0;
    Node* t1=n;
    Node* t2;

    while(cnt!=pos-1){
        if(cnt==pos-2)t2=t1;
        t1=t1->next;
        cnt++;
    }

    if(t1->next==NULL){
        t2->next=NULL;
        return;
    }

    t2->next=t1->next;
    t1->next->prev=t2;
}

void delEnd(Node* &n){
    Node* t1=n;
    Node* t2;

    while(t1->next!=NULL){
        if(t1->next->next)t2=t1;
        t1=t1->next;
    }

    if(t1->next==NULL){
        t2->next=NULL;
        return;
    }
}

void Display(Node* n){
    Node* t=n;
    cout<<"\nElements in the list : ";
    while(t!=NULL){
        cout<<t->val<<" ";
        t=t->next;
    }
    cout<<endl;
}

void menu(){
    cout<<"\n******************MENU**********************\n";
    cout<<"* 1.Insert                                   *\n";
    cout<<"* 2.Delete                                   *\n";
    cout<<"* 3.Display                                  *\n";
    cout<<"* 4.Exit                                     *\n";
    cout<<"**********************************************\n";
    cout<<endl;
}

int main()
{
    int opt;
    do{
        menu();
        cout<<"\nEnter your choice : ";
        cin>>opt;
        system("cls");
        switch(opt){

        case 1:
            int val;
            cout<<"\nEnter the value to be inserted : ";
            cin>>val;

            cout<<"\n********************MENU**********************\n";
            cout<<"* 1.Insert at beginning                      *\n";
            cout<<"* 2.Insert at end                            *\n";
            cout<<"* 3.Insert after                             *\n";
            cout<<"* 4.cancel                                   *\n";
            cout<<"**********************************************\n";
            cout<<endl;

            int v1;
            cout<<"\nEnter your choice : ";
            cin>>v1;
            if(v1==1)insertAtStart(n1,val);
            if(v1==2)insertAtEnd(n1,val);
            if(v1==3){
                int ipos;
                cout<<"\nEnter the position to be inserted : ";
                cin>>ipos;
                insertAtPos(n1,ipos,val);
            }
            if(v1==4)break;
            cout<<"\nSuccessfully inserted";
            break;

        case 2:
            int dopt;
            cout<<"\n********************MENU**********************\n";
            cout<<"* 1.Delete at beginning                      *\n";
            cout<<"* 2.Delete at end                            *\n";
            cout<<"* 3.Delete specific Node                     *\n";
            cout<<"* 4.cancel                                   *\n";
            cout<<"**********************************************\n";
            cout<<endl;

            cout<<"\nEnter your choice : ";
            cin>>dopt;
            if(dopt==1)delNode(n1,1);
            if(dopt==2)delEnd(n1);
            if(dopt==3){
                int dpos;
                cout<<"\nEnter the position to be deleted : ";
                cin>>dpos;
                delNode(n1,dpos);
            }
            if(dopt==4)break;
            cout<<"\nSuccessfully deleted !!";
            break;


        case 3:
            if(n1->val==10)delNode(n1,1);
            Display(n1);
            break;
        if(opt!=4)
            cout<<"\nEnter an option from the above Menu\n";
        }
    }while(opt!=4);

    cout<<"Thank you !";

    return 0;
}
