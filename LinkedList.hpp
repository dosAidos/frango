
#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

template <class Elem>

class LinkedList{//implementação da lista
private:
    struct Node{ //estrutura de elemento da lista (info + apontador)
		Elem elem;
		Node *next;
    };
	Node *head;//1º elemento

public:
	LinkedList(){//declaraçao inicial
		head = nullptr;
	}

	bool empty() const{
		return head==nullptr;
	}

	unsigned int size() const{
		int total = 0;
		Node* aux = head;
		while(aux->next != nullptr){
			total++;
			aux = aux->next;
		}
		return total;
	}

	void append(Elem a){//inserção de novo elemento no fim da lista
		Node* n = new Node;
		n->elem = a;
		n->next = nullptr;

		if(empty()){//lista originalmente vazia
			head = n;
		}else{
			Node* aux = head;
			while(aux->next != nullptr){
				aux = aux->next;
			}
			aux->next = n;
		}
	}

	void push(Elem a){//inserção de novo elemento no início da lista
		 Node* n = new Node;
		 n->elem = a;
		 n->next = head;
		 head = n;
	}

	void insert(Elem a, unsigned int idx){//inserção de novo elemento num determinado índice
		if(idx>size()){
			cout << "index too high for insertion\n";
		}else if(idx==size()){
			append(a);
		}else if(idx==0){
			push(a);
		}else{
			Node* n = new Node;
			n->elem = a;

			Node* aux = head;
			for(unsigned int i=0; i<idx; i++){
				aux = aux->next;
			}
			aux->next = n;
		}
	}

	Elem fetch(unsigned int idx) const{//obter elemento especifico da lista
		Node* aux = head;
		for(unsigned int i=0; i<idx; i++){
			aux = aux->next;
			if(aux == nullptr){
				cout << "index too high for fetching, last item returned\n";
				return Mono();
			}
		}
		return aux->elem;
	}
 };

#endif /* LINKEDLIST_HPP_ */
