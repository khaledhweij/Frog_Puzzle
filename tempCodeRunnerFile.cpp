 // Node* head = new Node;
    // head->data="bbb-ggg";
    // head->prev=NULL;
    // head->next=NULL;
    // queue<Node*> open;
    // queue<Node*>closed;
    // std::vector< Node* > successors;
    // int counter=0;

    // open.push(head);
    // while(!open.empty()){
    //     Node* tmp = new Node;
    //     tmp=open.front();

    //     if(tmp->data.substr(0,7)=="ggg-bbb"){
    //         //returnPath();
    //         break;
    //     }
    //     else{
    //         open.pop();
    //         closed.push(tmp);
    //         successors = findSuccessor(tmp,counter);
    //         for(int i =0;i<successors.size();i++){
    //             open.push(successors[i]);

    //         }


    //     }

    // }
    // cout<<closed.size()<<endl;
    // showq(closed);