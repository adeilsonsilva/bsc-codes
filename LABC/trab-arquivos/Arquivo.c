#include <stdio.h>
#define TAM 50

typedef struct Cliente{
	int codigo;
	char nome[TAM];
	int ativo;
	}Cliente;
	
void cabecalho(char *titulo){
	//system(clear); // Linux
	//system(cls); // Windows
	printf("\n\n--==[%s]==--\n\n", titulo);
}

int main (){
	FILE *arq;
	Cliente cli;
	int op, pos;
	char resp = 's';
	
	//arq = fopen("teste.txt", "rw+");
	arq = fopen("teste.bin", "w+b");
	
	if (arq == NULL)
		printf("\nErro ao tentar abrir o arquivo.");
	else {
		do{
			cabecalho("Menu Principal");
			printf("\n1 - Incluir");
			printf("\n2 - Alterar");
			printf("\n3 - Excluir");
			printf("\n4 - Consultar");
			printf("\n5 - Relatorio");
			printf("\n6 - Sair");
			printf("\nOpção: ");
			scanf("%d", &op);
			getchar();
			
				switch(op){
					case 1:
						cabecalho("Inclusão");
						cli.ativo = 1;
						printf("\n Digite o código do cliente: ");
						scanf(" %d", &cli.codigo);
						//fflush(stdin);
						printf("\n Digite o nome do cliente: ");
						scanf(" %[^\n]s", cli.nome);
						//gets(cli.nome);
						
						//Escrita do registro no arquivo
						
						fwrite(&cli, sizeof(Cliente), 1, arq);
						//fprintf(arq, "%d\n%s\n%d", cli.codigo, cli.nome, cli.ativo);
						
						if (ferror(arq))
							printf("\n Erro na gravação do arquivo..");
						else 
							printf("\n Cliente cadastrado com sucesso...");
						break;
					case 2:
						cabecalho("Alteração");
						printf("\n Digite a posição que deseja alterar. ");
						scanf(" %d", &pos);
						//getchar();
						
						//posicionamento do cursor sobre o registro
						
						fseek(arq, sizeof(Cliente)*(pos-1), SEEK_SET);
						
						if (ferror(arq))
							printf("\n Erro no posicionamento do cursor.");
						else{
							// Le o arquivo e movimenta o cursor para o proximo registro.
							//fscanf(arq, "%d\n%s\n%d", &cli.codigo, cli.nome, &cli.ativo);
							fread(&cli, sizeof(Cliente),1, arq);
							
							if (ferror(arq))
								printf("\n Erro na leitura do arquivo.");
							else{
								printf("\nCliente Código: %d", cli.codigo);
								printf("\nCliente Nome:   %s", cli.nome);
								printf("\nCliente Ativo:  %d", cli.ativo);	
							}
							
						}
						printf("\nDigite o novo código do cliente: ");
						scanf(" %d", &cli.codigo);
						printf("\nDigite o novo nome do cliente: ");
						scanf(" %[^\n]s", cli.nome);
						
						//posicionamento novamente do cursor sobre o registro
						
						fseek(arq,sizeof(Cliente)*(pos-1), SEEK_SET);
						// gravação do registro no arquivo
						//fprintf(arq, "%d\n%s\n%d", cli.codigo, cli.nome, cli.ativo);
						fwrite(&cli, sizeof(Cliente), 1, arq);
						break;
					case 3:
						cabecalho("Exclusão");
						printf("\n Digite a posição que deseja excluir");
						scanf(" %d", &pos);
						getchar();
						
						//posiciona novamente o cursor sobre o registro
						fseek(arq, sizeof(Cliente)*(pos-1), SEEK_SET);
						
						if (ferror(arq))
							printf("\n Erro no posicionamento do cursor. ");
						else{
							// Le o registro e movimenta o cursor para o proximo registro
							//fscanf(arq, "%d\n%s\n%d", &cli.codigo, cli.nome, &cli.ativo);
							fread(&cli, sizeof(Cliente), 1, arq);
							if (ferror(arq))
								printf("\n Erro na leitura do arquivo.");
							else{
								printf("\nCliente Código: %d", cli.codigo);
								printf("\nCliente Nome:   %s", cli.nome);
								printf("\nCliente Ativo:  %d", cli.ativo);
						}
						
				}
				do{
					printf("Confirma a exclusão? (s/n): ");
					scanf(" %c", &resp);
					//resp = tolower(getchar());
					} while(resp != 's' && resp != 'n');
					if (resp == 's'){
						//posiciona o cursor no arquivo desejado
						
						fseek(arq, sizeof(Cliente)*(pos-1), SEEK_SET);
						
						//tornar o cliente inativo
						
						cli.ativo= 0;
						
						//gravar alteração
						
						//fprintf(arq,"%d\n%s\n%d", cli.codigo, cli.nome, cli.ativo);
						fwrite(&cli, sizeof(Cliente), 1, arq);
						
						if (ferror(arq))
							printf("\n Erro na exclusão do arquivo");
						else
							printf("\n Exclusão efetuada com sucesso");
						
					}
					else
						printf("\n\n Exclusão não efetuada.");
					
					break;
					
					case 4:
						cabecalho("Consulta");
						printf("\n Digite a posição que deseja consultar: ");
						scanf(" %d", &pos);
						//getchar();
						
						//posicionamento do cursor sobre o registro
						
						fseek(arq, sizeof(Cliente)*(pos-1), SEEK_SET);
						
						if (ferror(arq))
							printf("\n Erro no posicionamento do cursor");
						else{
							// Le o registro e movimenta o cursor para o proximo registro
							
							//fscanf(arq, "%d\n%s\n%d", &cli.codigo, cli.nome, &cli.ativo);
							fread(&cli, sizeof(Cliente), 1, arq);
							
							if (ferror(arq))
								printf("\n Erro na leitura do registro.");
							else {
								printf("\nCliente Código: %d", cli.codigo);
								printf("\nCliente Nome:   %s", cli.nome);
								printf("\nCliente Ativo:  %d", cli.ativo);
							}
							
						}
						getchar();
						break;
						
					case 5:
						cabecalho("Relatorio");
						//reposiciona o cursor no inicio do arquivo.
						
						rewind(arq);
						//pos=1;
						if (ferror(arq))
							printf("\n Erro no posicionamento do cursor.");
						else{
							while(!feof(arq)){
								//le o registro e movimenta o cursor para o proximo registro
																
								/*fscanf(arq, "%d\n%s\n%d", &cli.codigo, cli.nome, &cli.ativo);
								fseek(arq, (pos-1), SEEK_CUR);
								pos++;*/
								
								fread(&cli, sizeof(Cliente), 1, arq);
								
								if (ferror(arq))
									printf("\n Erro na leitura do registro.");
								else{
									// este comando evita a impressão duplicada do ultimo registro.
									if (!feof(arq)){
										if(cli.ativo){
											printf("\n Cliente código: %d", cli.codigo);
											printf("\n Cliente nome: %s\n", cli.nome);
										}
									}
								}
							}
						}
						getchar();
					
			
		}
		
		
		
	}while(op!= 6);
		
	
	}
		//fecha o arquivo
		fclose(arq);
		
		return 0;
}
