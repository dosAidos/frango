
#ifndef TADLISTA_H_
#define TADLISTA_H_

template <class Elem>

class tadLista{//implementação da lista
	private:
    struct nL{ //estrutura de elemento da lista (info + apontador)
		Elem x;
		nL *prox;
    };
	nL *in;//1º elemento
	nL *fin;// ultimo elemento

	public:
	tadLista(const tadLista &){}
	void operator=(const tadLista &);
	tadLista(){//declaraçao inicial
		in=nullptr;
		fin=nullptr;
	}

	 void ins_nL(Elem a){//inserção de novo elemento no fim da lista
		 nL *n= new nL;
		 n->x=a;
		 n->prox=nullptr;

		 if(in==nullptr){//lista originalmente vazia
			 in=n;
			 fin=n;
		 }
		 else{//lista ja com pelo menos 1 elemento
			 fin->prox=n;
			 fin=fin->prox;
		 }
	 }

	 Elem ver_Lt(){//obter todos elementos da lista
		 nL *n;
		 n=in;
		 while(n!=nullptr){
			return n->x;
		 }
	 }

	 Elem ver_nLe(int pos){//obter elemento especifico da lista
		 int aux=0;
		 nL *at;
		 at=in;
		 while(at!=nullptr){
			 if (aux==pos){
				return (at->x);
				break;
				}
			aux++;
			at=at->prox;
		 }
		 return at->x;
	 }
 };

#endif /* TADLISTA_H_ */
