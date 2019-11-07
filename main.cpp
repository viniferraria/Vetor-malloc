#include	<iostream>
#include <stdlib.h>
#include "vetor.h"
using namespace std;

template<typename T>
Vetor<T>::Vetor(int	t)
{
  v = (T*) malloc (t*sizeof(T*)); //equivale a T[t] == int v[100]
	if(v==NULL)
	  throw	new	std::string("memoria	insuficiente");
	tam = t;
}			
				
template	<typename	T>
Vetor<T>::~Vetor()
{
	delete	v;
}
			
template	<typename	T>
int	Vetor<T>::tamanho()
{
  return tam;
}

template	<typename	T>
T Vetor<T>::elemento(int	i)
{
  if(i<0 || i>=tam)
    throw new std::string("Out of index");
  return v[i];
}

template	<typename	T>
bool Vetor<T>::procura(T elem)
{
  for(int i = 0; i<tam;i++){
    if (v[i]==elem)
      return true;
  }
    return false;
}

template	<typename	T>
void	Vetor<T>::remove(int	i)
{
  if (i<0 ||i>=tam)
    throw new std::string("Out of index");
  for(int j=i; j<tam-1; j++){
    v[i]= v[i+1];
}
  v[tam-1] = NULL;
}

template <typename T>
void Vetor<T>::insere(T elemento, int i){
  if(i<0 || i>=tam){
    throw new std::string("Valor inválido");
  }
  v[i] = elemento;
}

template <typename T>
Vetor<T> Vetor<T>::agrupar(Vetor<T> v){
int tamtotal = tam + v.tamanho();
Vetor <T> y(tamtotal);
for(int i=0;i<tam;i++){
  y.insere(elemento(i),i);
}
for(int i = 0; i<v.tamanho(); i++){
  y.insere(v.elemento(i),tam+i);
}
return y;
}

int main(){

Vetor<int> A(3);
for(int i=0;i<2;i++){
  A.insere(i*9,i);
}

Vetor<int> B(4);
for(int i=0;i<B.tamanho();i++){
  B.insere(i*5, i);
}

Vetor<int> C(A.agrupar(B));
cout<<"[";

for(int i =0;i<C.tamanho();i++)
{
  if (i==0)
    cout<<C.elemento(i);
  if(i>0)
  cout<<", "<<C.elemento(i);
}
cout<<"]"<<endl;


}
