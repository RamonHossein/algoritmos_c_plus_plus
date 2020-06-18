/*
	DAO - Data Access Object
	
	Data Access Object é um padrão para aplicações que utilizam persistência de dados e onde se tem uma separação das regras de negócio
	das regras de acesso ao banco de dados.
	
	No Data Access Object todas as funcionalidades referêntes ao banco de dados, tais como obter conexões, mapear objetos para tipo de
	dados SQL ou executar comandos SQL, devem ser feitas por uma classe "DAO".
*/

#include <bits/stdc++.h>

using namespace std;

/*----------------------------------------------------------------------------------------------------------------------------------------*/

class DocumentoDao {

public:
	virtual void savePessoas() = 0;
	virtual void updatePessoas() = 0;
	virtual void deletePessoas() = 0;

	virtual ~DocumentoDao() {
	}
};

/*----------------------------------------------------------------------------------------------------------------------------------------*/

class ArquivoDeTexto : public DocumentoDao {

public:
	void savePessoas() {
		cout << "Acao de Salvar realizada atraves de arquivo de documento" << endl << endl;
	}

	void updatePessoas() {
		cout << "Acao de Atualizar realizada atraves de arquivo de documento" << endl << endl;
	}

	void deletePessoas(){
		cout << "Acao de Apagar realizada atraves de arquivo de documento" << endl << endl;
	}
};

/*----------------------------------------------------------------------------------------------------------------------------------------*/

class ArquivoDeVideo : public DocumentoDao {

public:
	void savePessoas() {
		cout << "Acao de Salvar realizada atraves de arquivo de video" << endl << endl;
	}

	void updatePessoas() {
		cout << "Acao de Atualizar realizada atraves de arquivo de video" << endl << endl;
	}

	void deletePessoas(){
		cout << "Acao de Apagar realizada atraves de arquivo de video" << endl << endl;
	}
};

/*----------------------------------------------------------------------------------------------------------------------------------------*/

class ArquivoDeAudio : public DocumentoDao {

public:
	void savePessoas() {
		cout << "Acao de Salvar realizada atraves de arquivo de audio" << endl << endl;
	}

	void updatePessoas() {
		cout << "Acao de Atualizar realizada atraves de arquivo de audio" << endl << endl;
	}

	void deletePessoas(){
		cout << "Acao de Apagar realizada atraves de arquivo de audio" << endl << endl;
	}
};

/*----------------------------------------------------------------------------------------------------------------------------------------*/

class DocumentoController {

private:
	DocumentoDao *dao;

public:
	template<class T>
	DocumentoController(T *arquivo) {
		dao = arquivo;
	}

	void salvar() {
		dao->savePessoas();
	}

	void editar() {
		dao->updatePessoas();
	}

	void excluir() {
		dao->deletePessoas();
	}
};

/*----------------------------------------------------------------------------------------------------------------------------------------*/

int main() {

	DocumentoController *documentoUm = new DocumentoController(new ArquivoDeTexto());
	documentoUm->salvar();

	DocumentoController *documentoDois = new DocumentoController(new ArquivoDeVideo());
	documentoDois->salvar();

	DocumentoController *documentoTres = new DocumentoController(new ArquivoDeAudio());
	documentoTres->salvar();

	return 0;
}

