#include "Interfaz.h"

Interfaz::Interfaz() {
	
	Clientes = new ListaClientes();
	Pedidos = new ListaPedido();
	Repartidores = new ListaReparti();
	Restau = new ContenedorRest();
	
	//Inicializando listas con objetos
	
	//Clientes->Agregar(c1); Clientes->Agregar(c2); Clientes->Agregar(c3); 
	//Pedidos->agregar_pedido(p1); Pedidos->agregar_pedido(p2); Pedidos->agregar_pedido(p3);
	//Repartidores->agregar_reparti(r1); Repartidores->agregar_reparti(r2); Repartidores->agregar_reparti(r3); 
	
}

Interfaz::~Interfaz() {
	
}

/*
void Interfaz::GuardaRestaurante(){

string Escribir;


ofstream Resta("./Restaurante/ListaRestaurante.txt",ios::out);

while(Aux!=NULL){
Escribir= Aux->get_cliente()->TostringPer();
Resta<<Escribir;
Resta<<"\n\n";
Aux=Aux->get_siguiente();
}

Resta.close();

}
void Interfaz::LeerRestaurante(){

string Escribir;

ifstream Resta("./Restaurante/ListaRestaurante.txt",ios::in);

while(!Resta.eof()){

getline(Resta,Escribir);
Escribir.append("\n");
cout<<Escribir;
}

Resta.close();

}


void Interfaz::GuardaRepartidores(Repartidor *Nuevo){
	
	string Escribir;
	
	
	ofstream Reparti("./Repartidores/Lista/ListaRepartidores.txt",ios::app);
	
	Escribir = Nuevo->tostringRepa();
	
	Reparti<<Escribir;
	
	Reparti<<"\n=================================================================\n\n";
	
	Reparti.close();
	
}

void Interfaz::LeerRepartidores(){
	
	
	string Escribir;
	
	ifstream Reparti("./Repartidores/Lista/ListaRepartidores.txt",ios::in);
	
	while(!Reparti.eof()){
		
		getline(Reparti,Escribir);
		Escribir.append("\n");
		cout<<Escribir;
	}
	
	Reparti.close();
	
}

void Interfaz::GuardaClientes(Cliente *Nuevo){
	
	string Escribir;
	
	
	ofstream Client("./Cliente/Lista/ListaClientes.txt",ios::app);
	
	Escribir= Nuevo->TostringCliente();
	Client<<Escribir;
	Client<<"\n=================================================================\n\n";
	
	Client.close();
	
}

void Interfaz::LeerClientes(){
	
	string Escribir;
	
	
	ifstream Client("./Cliente/Lista/ListaClientes.txt",ios::in);
	
	while(!Client.eof()){
		
		getline(Client,Escribir);
		Escribir.append("\n");
		cout<<Escribir;
	}
	
	Client.close();
	
}*/

void Interfaz::GuardaPedidos(string id, Pedido *L){
	
	string Escribir;
	
	ofstream Pedi("./Cliente/Pedidos/"+id+".txt",ios::app);
	
	Escribir = L->tostring_pedido();
	Pedi<<Escribir;
	Pedi<<"\n=================================================================\n\n";
	
	Pedi.close();
}

void Interfaz::LeerPedidos(string id){
	
	string Escribir;
	
	
	ifstream Pedi("./Cliente/Pedidos/"+id+".txt",ios::in);
	
	while(!Pedi.eof()){
		
		getline(Pedi,Escribir);
		Escribir.append("\n");
		cout<<Escribir;
	}
	Pedi.close();
	
}

void Interfaz::Client_MayorP(){
	
	NodoCliente *Aux = Clientes->get_head();
	int mayor=0;
	string ElMayor;
	
	while(Aux!=NULL){
		if(Aux->get_cliente()->getNum_Pedidos()>mayor){
			mayor=Aux->get_cliente()->getNum_Pedidos();
			ElMayor=Aux->get_cliente()->TostringCliente();
		}
		Aux=Aux->get_siguiente();
	}
	cout<<ElMayor<<"\n";
	
}
void Interfaz::queja(string id, string recla){
	
	ofstream reclamo("./Repartidores/Quejas/"+id+".txt",ios::app); 
	
	
	reclamo<<'-'<<recla<<"\n";
	reclamo<<"==========================\n";
	
	reclamo.close();
	
}
void Interfaz::leer_queja(string id){
	
	string impri;
	
	ifstream reclamo("./Repartidores/Quejas/"+id+".txt",ios::in);
	
	while(!reclamo.eof()){
		
		getline(reclamo, impri);
		cout<<impri<<endl;
		
	}
	
	reclamo.close();
	
}

void Interfaz::guardar_listas(){
	
	ofstream cli;
	ofstream rep;
	
	cli.open("./Cliente/Lista/ListaClientes.txt");
	rep.open("./Repartidores/Lista/ListaRepartidores.txt");
	
	NodoCliente *aux1 = Clientes->get_head();
	NodoReparti *aux2 = Repartidores->get_ini();
	
	while(aux1!=NULL){
		
		Cliente *c = aux1->get_cliente();
		c->autosave(cli);
		aux1 = aux1->get_siguiente();
		delete c;
		
	}
	
	while(aux2!=NULL){
		
		Repartidor *r = aux2->get_dato();
		r->autosave(rep);
		aux2 = aux2->get_sig();
		delete r;		
		
	}
	
	cli.close();
	rep.close();
	
	delete aux1;
	delete aux2;
	
}

void Interfaz::cargar_lista_cliente(){
	
	Cliente *n = new Cliente();
	Cliente *aux = new Cliente();
	
	ifstream z;
	
	z.open("./Cliente/Lista/ListaClientes.txt");
	
	if(!z || z.good() == false){
		
		z.close();
		
	}else{
		
		while(z.eof() == false){
			
			n = &aux->autoread(z);
			
			if(n->get_nombre() != ""){
				
				Clientes->Agregar(n);
				
			}
			
		}
		
	}
	
	z.close();
	
	delete aux; 
	delete n;
	
}

void Interfaz::cargar_lista_reparti(){
	
	Repartidor *r = new Repartidor();
	Repartidor *aux1 =  new Repartidor();
	
	ifstream z;
	
	z.open("./Repartidores/Lista/ListaRepartidores.txt");
	
	if(!z || z.good() == false){
		
		z.close();
		
	}else{
		
		while(z.eof() == false){
			
			r = &aux1->autoread(z);
			
			if(r->get_nombre() != ""){
				
				Repartidores->agregar_reparti(r);
				
			}
			
		}
		
	}
	
	z.close();
	
	delete r; 
	delete aux1;
	
}

void Interfaz::guardar_restau(){
	
	ofstream res;
	
	res.open("restau.txt");
	
	Restaurante *aux;
	
	for(int i=0;i<7;i++){
		
		aux = Restau->contenedor[i];
		Restaurante *r = aux;
		r->autosave(res);
		delete r;
		
	}
	
	res.close();
	
	delete aux;
	
	
}

void Interfaz::cargar_restau(){
	
	Restaurante *r1 = new Restaurante();
	Restaurante *aux = new Restaurante();
	
	ifstream z;
	
	z.open("restau.txt");
	
	if(!z || z.good()!=true){
		
		z.close();
		
	}else{
		
		while(z.eof()!=true){
			
			for(int i=0;i<7;i++){
				
				r1 = &aux->autoread(z);
				
				if(r1->get_nombre() != ""){
					
					Restau->contenedor[i] = r1;
					
				}
				
			}
			
		}
		
	}
	
	z.close();
	
	delete r1; delete aux;
	
}
