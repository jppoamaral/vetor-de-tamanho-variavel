//Nome: João Pedro de Paula Oliveira do Amaral
//TIA: 32049390
#include <iostream>

using namespace std;

//função que pula linha
void jumpLine()
{
	cout << "\n";
}

//função que otimisa os comandos de cin e cout
int outIn(string question)
{
	int answer;
	cout << question;
	cin >> answer;
	return answer;
}

//função que aumenta array
int* increaseArray(int arr[], int size, int new_size)
{
	int* new_arr = new int[new_size] {};
	for (int i = 0; i < size; i++)
		new_arr[i] = { arr[i] };
	return new_arr;
}

//função que printa o array
void printArray(int arr[], int contador, int size)
{
	int i = 0;
	jumpLine();
	for (i; i < contador; i++)
		cout << "array[" << i << "]: " << arr[i] << "\n";
	while (arr[i] <= 0 && i < size)
		cout << "array[" << i++ << "]: " << -1 << "\n";
}

int main()
{
	setlocale(LC_ALL, "pt_BR");
	int size, new_size, i, aux, case_num = 0, op, j, dif, contador = 0;
	bool continuar = true;
	
	size = outIn("Digite o tamanho do array: ");
	jumpLine();
	if (size >= 0)
	{
		int* arr = new int[size];
		do 
		{
			switch (case_num)
			{
				case 0:
					cout << "A seguir digite insira " << size <<" números:\n";
					for (i = 0; i < size; i++)
					{
						aux = outIn("Digite um número positivo: ");
						if (aux < 0) { 
							continuar = false;
							break; 
						} 
						else {
							arr[i] = aux;
							case_num = 1;
							contador++;
						}
					}
					jumpLine();
					break;
				case 1:
					cout << "O limite do array foi atingido.\n";
					op = outIn("Desenha aumentar o tamanho do array? (1)-SIM / (0)-NÃO: ");
					jumpLine();
					if (op == 1)
					{
						cout << "Tamanho atual: " << size << "\n" ;
						new_size = outIn("Digite o novo tamanho do array: ");
						jumpLine();
						if (new_size <= size) {
							continuar = false;
							cout << "O tamanho do novo array não pode ser menor ou igual ao atual.\n" << "Encerrando...\n";
						}
							
						else {
							dif = new_size - size;
						    arr = increaseArray(arr, size, new_size);
							size = new_size;
							cout << "A seguir digite " << dif << " números:\n";

							for (j = 0; j < dif; j++)
							{
								aux = outIn("Digite um número positivo: ");
								if (aux <= 0) {
									continuar = false;
									break;
								}
								else {
									arr[size + j - dif] = aux;
									contador++;
								}	
							}
							jumpLine();
							case_num = 1;
						}
					}
					else {
						continuar = false;
					}
					break;
			}
		} while (continuar);
		printArray(arr, contador, size);
		delete[] arr;
	}
}