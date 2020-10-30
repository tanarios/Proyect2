#include "Interfaz.h"

Interfaz::Interfaz(Pedido *p1, Pedido *p2, Pedido *p3, Repartidor *r1, Repartidor *r2, Repartidor *r3, Cliente *c1, Cliente *c2, Cliente *c3) {
	
	Clientes = new ListaClientes();
	Pedidos = new ListaPedido();
	Repartidores = new ListaReparti();
	Restau = new ContenedorRest();
	
	//Inicializando listas con objetos
	
	Clientes->Agregar(c1); Clientes->Agregar(c2); Clientes->Agregar(c3); 
	Pedidos->agregar_pedido(p1); Pedidos->agregar_pedido(p2); Pedidos->agregar_pedido(p3);
	Repartidores->agregar_reparti(r1); Repartidores->agregar_reparti(r2); Repartidores->agregar_reparti(r3); 
	
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
*/

void Interfaz::GuardaRepartidores(){
	
	NodoReparti *Aux = Repartidores->get_ini();
	string Escribir;
	
	
	ofstream Reparti("./Repartidores/Lista/ListaRepartidores.txt",ios::app);
	
	while(Aux!=NULL){
		Escribir= Aux->get_dato()->tostringRepa();
		Reparti<<Escribir;
		Reparti<<"\n=================================================================\n\n";
		Aux=Aux->get_sig();
	}
	
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

void Interfaz::GuardaClientes(){
	
	NodoCliente *Aux = Clientes->get_head();
	string Escribir;
	
	
	ofstream Client("./Cliente/Lista/ListaClientes.txt",ios::app);
	
	while(Aux!=NULL){
		Escribir= Aux->get_cliente()->TostringCliente();
		Client<<Escribir;
		Client<<"\n=================================================================\n\n";
		Aux=Aux->get_siguiente();
	}
	
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
	
}

void Interfaz::GuardaPedidos(string id, Pedido *L){
	
	Cliente *Aux = Clientes->user(id);
	Aux->Aumentar();
	
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
