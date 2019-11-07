#ifndef	VETOR_h
#define	VETOR_h

template	<typename	T>

class	Vetor{
	private:
	  T* v;					//	vetor	de	elementos	do	tipo	T
	  int	tam;		   //	tamanho	do	vetor					 
	public:
		Vetor(int	t);
		~Vetor();
		int	tamanho();
		T	elemento	(int	i);
		bool procura(T	elem);
	  void remove	(int	i);
    void insere (T elemento, int i);
    Vetor agrupar(Vetor<T> v);
};

#endif