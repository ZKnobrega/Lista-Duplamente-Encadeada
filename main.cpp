#include <iostream>
#include <locale>
#include <stdlib.h>

using namespace std;

typedef struct no
{
	int valor;
	struct no *prox;
	struct no *anterior;
} no;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	no *lista;
	lista = NULL;
	no *novo;
	int num, posicao;
	no *aux;
	no *aux2; //usado em excluir e pesquisar e inserir por posição.
	int op;
	int cont = 0;

inicio:

	cout << "Escolha a opção desejada: \n1 - Inserir.\n2 - Excluir.\n3 - Listar.\n4 - limpar.\n5 - Inserir por Posição.\n6 - Listar do final.\n7 - Sair." << endl;
	cout << "Escolha: ";
	cin >> op;
	cout << "\n\n";
	switch (op)
	{
        cont = 0;
        do
			{
				cout << cont + 1 << "º " << aux->valor << endl;
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
			} while (aux != NULL);


	case 1:
		//inserir;
		cout << "Digite um valor inteiro para inserir na lista: ";
		cin >> num;
		novo = new no; //O ponteiro 'novo' recebe o local dinâmicamente indicado por NEW com o tamanho de espaço para variavel do tipo no
		novo -> valor = num; // 'novo' já com o local de memoria aloocado apontando para o valor que irá receber o numero informado pelo usuario

		if (lista == NULL)
        {
            lista = novo;
            lista -> prox = NULL;
            lista -> anterior = novo;
        }

		else
            {
                novo -> prox = lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior sendo assim "liata" sempre será o ultimo valor incrementado na lista apontando para o seu proximo torndando 'lista' a cabeça.6
                lista -> anterior = novo;
                lista = novo; // para não perdermos o valor de referencia da lista.
            }
		cout << "\n\n";
		goto inicio;

	case 2:

		//excluir;
		int ind; // será a posição da variavel a ser excluida.
		no *morta; // o ponteiro que irá retirar a variavel da lista.
		aux = novo;
		cout << "A lista é:\n";
        cont = 0;
		do
        {
				cout << cont + 1 << "º " << aux->valor << endl;
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
        }while (aux != NULL);
        cout << "\nDigite a posição do valor a ser excluido: "<< endl;
		cin >> ind;
		aux = novo;
        if (ind != 1 && ind <= cont)
        {

            for (int i = 0; i < ind - 2; i++)
            {
                aux = aux->prox;
            }

            morta = aux->prox;
            aux->prox = morta->prox;
            morta->anterior = morta -> prox;

            cout << "\n\n";
        }
        else if (ind == 1)
        {
            novo = aux -> prox;
        }
        else if (ind < 1 | ind > cont)
        {
            cout << "Opção Invalida!!\n";
        }

		goto inicio;
		break;


	case 3:
		//listar

		if (lista == NULL)
		{
			cout << "Lista vazia!" << endl;
		}
		else
		{
			cout << "\n\n" << endl << "\nA lista é:" << endl;
			aux = novo;
			int cont = 0;
			do
			{
				cout << cont + 1 << "º " << aux->valor << endl;
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
			} while (aux != NULL);
			cout << "\n\n";
			cout << "A lista possui " << cont << " Valores." << endl;
		}
		cout << "\n\n";
		goto inicio;
		break;


	case 4:
		//limpar;
		lista = NULL; //perde-se o local do ultimo valor informado
		cout << "\n\n";
		goto inicio;
		break;


    case 5:
        // inserir por posição
        aux = lista;
        cont = 0;
        do
			{
				aux = aux->prox; //O ptr 'aux' agora vai apontar para o proximo valor
				cont++;
			} while (aux != NULL);
        no *anterior;
        cout << "Informe o Valor a ser inserido: \n";
		cin >> num;
        int posicao;
        cout << "Informe a posição a ser inserida: \n";
        cin >> posicao;
        novo = new no; //O ponteiro 'novo' recebe o local indicado por new;
		novo->valor = num;

        if (posicao > 1 && posicao <= cont)
        {
            aux = lista;
            anterior = lista;
                for (int i=0; i<posicao; ++i)
                {
                    aux = aux -> prox;
                }

            for (int i=0; i<posicao-1; ++i)
                {
                    anterior = anterior -> prox;
                }

            anterior -> prox = novo;

            if (posicao-1 == cont)
            {

                novo -> prox =NULL;
            }
            else
            {
                novo -> prox = aux;
            }

        }

        else if(posicao == 1){
            novo -> valor = num;
            novo -> prox = lista; //Lista inicialmente vale NULL, depois de ser inserido algum valor 'lista' vai ser igual ao ptr anterior
            lista = novo;
        }
        else
            {
                cout << "Valor Invalido"<< endl;
            }
		goto inicio;
        break;

    case 7:
		//Sair
		cout << "Obrigado Por usar o Programa.";
		break;




    case 6:
            // listar com anterior.

            if (lista == NULL)
                {
                    cout << "Lista vazia!" << endl;
                }


            else
            {
                cout << "\n\nA lista é:" << endl;
                aux = novo;

                do
                {
                    //cout << cont + 1 << "º " << aux->valor << endl;
                    aux2 = aux;
                    aux = aux->prox ; //O ptr 'aux' agora vai apontar para o proximo valor
                    cont++;
                } while (aux != NULL);


                int cont = 0;
                do
                {
                    cout << cont + 1 << "º " << aux2->valor << endl;
                    aux2 = aux2->anterior ; //O ptr 'aux' agora vai apontar para o proximo valor
                    cont++;
                } while (aux2 != NULL);
                cout << "\n\n";
                cout << "A lista possui " << cont << " Valores." << endl;
            }
            cout << "\n\n";
            goto inicio;
            break;

	default:
		cout << "Opção inválida!" << endl;

		goto inicio;
	}
}
