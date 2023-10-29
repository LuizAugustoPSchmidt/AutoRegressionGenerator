//Próximo passo: adaptar para POSIX

/* Gerador de gráficos v3.0
Inputs: Nome (Título), Número de Gráficos, Número de Pontos, Pontos dos gráficos
Outputs: Pasta com o nome fornecido, arquivo .tex com os gráficos produzidos a partir dos pontos informados, um arquivo .dat para cada gráfico
*/

//Que bagunça de programa. Vou ter que dar um jeito nisso

#include <stdio.h>
#include <direct.h>
#include <string.h>
#define STD_SIZE 256

void inicializa_arq(const char* project_name, const char* author, const char* date){
	fprintf(fptr_main, "\\documentclass{article}\n");
	fprintf(fptr_main, "\\usepackage{graphicx}\n");
	fprintf(fptr_main, "\\usepackage{pgfplotstable}\n");
	fprintf(fptr_main, "\\usepackage{amsmath}\n");
	fprintf(fptr_main, "\\usepackage{amssymb}\n");
	fprintf(fptr_main, "\\title{%s}\n", project_name);
	fprintf(fptr_main, "\\author{%s}\n", author);
	fprintf(fptr_main, "\\date{%s}\n", date);
	fprintf(fptr_main, "\\begin{document} \n\\maketitle\n");
}

int main(){
	FILE *fptr_main; //This is a damn mess
	FILE *fptr_aux;
	const char grafico[] = "Grafico";
	char graf_copia[160] = "Grafico";
	const char dat[5] = ".dat";
	char project_name[STD_SIZE], xlabel[STD_SIZE], ylabel[STD_SIZE];
	char aux_file_names[2*STD_SIZE];
	char aux_points[2*STD_SIZE];
	char author[STD_SIZE];
	char date[12];
	int qtd_graf, i, c;
	int qtd_pontos;
	int sist_op;

	//getc();
	printf("Insira o título do projeto: ");
	fgets(project_name, sizeof(project_name), stdin);
	printf("Insira os autores: ");
	fgets(author, sizeof(author), stdin);
	printf("Insira a data no seguinte formato, com as barras (DD/MM/AAAA): ");
	fgets(date, sizeof(date), stdin);
	printf("Qual o sistema operacional?\n0 - Windows\n1 - POSIX");
	scanf("%d", &sist_op);
	
	for(i = 0; i < STD_SIZE; i++){
		if(project_name[i] == '\n'){
			project_name[i] = '\0';
		}
		if(author[i] == '\n'){
			author[i] = '\0';
		}
	}
	for(i =0; i < 12; i++){
		if(date[i] == '\n'){
			date[i] = '\0';
		}
	}
	//era uma casa muito engraçada, não tinha teto não tinha nada, ninguém podia dorminr na rede porque na casa não tinha parade 
	//please send help i am being held hostage by the twitter(x) feed, i havent seen the sunlight in days and i dont know my family, please elon free me
	inicializa_arq(project_name, author, date);

	//---------------------------------------------------------------------
	
	if(sist_op == 0){
		const char *parentFolder = "C:\\Users\\luiza\\Documents\\FilesGeneratedInC";

		// Combine parent folder path and new folder name
		char newPath[256];
		snprintf(newPath, sizeof(newPath), "%s\\%s", parentFolder, project_name);
		// Create a new directory
		if (_mkdir(newPath) != 0) {
			perror("_mkdir");
			//return 1;
		}
	}else{
		const char *parentFolder = "C:\\Users\\luiza\\Documents\\FilesGeneratedInC";

		// Combine parent folder path and new folder name
		char newPath[256];
		snprintf(newPath, sizeof(newPath), "%s\\%s", parentFolder, project_name);
		// Create a new directory
		if (mkdir(newPath, 0777) != 0) {
			perror("_mkdir");
			//return 1;
		}
	}
	//---------------------------------------------------------------------

	strcpy(aux_file_names, newPath);
	strcat(aux_file_names, "\\");
	strcat(aux_file_names, project_name);
	strcat(aux_file_names, ".tex");

	if((fptr_main = fopen(aux_file_names, "w")) != NULL){
		
		printf("Insira a quantidade de gráficos a gerar: ");
		scanf("%d", &qtd_graf);
		getchar();
		for(i = 0; i < qtd_graf; i++){ //Loop dos gráficos
			strcpy(aux_file_names, newPath);
			strcat(aux_file_names, "\\");
			strcat(aux_file_names, grafico);
			snprintf(aux_file_names, sizeof(aux_file_names), "%s%d", aux_file_names, i + 1);
			//printf("\n%s\n", aux_file_names);
			strcat(aux_file_names, dat); //(path)\(nome do projeto).dat
			//printf("%s", aux_file_names);

			if((fptr_aux = fopen(aux_file_names, "w")) != NULL){
				fputs("a\tb\n", fptr_aux); //Why isn't this command working?

				printf("Insira a quantidade de pontos do grafico %d: ", i+1);
				scanf("%d", &qtd_pontos);

				printf("Insira a legenda do eixo x: ");
				scanf(" %s", xlabel);
				printf("Insira a legenda do eixo y: ");
				scanf(" %s", ylabel);

				for(c = 0; c < qtd_pontos; c++){ //Loop dos dados
					getchar(); //Isso aqui ficou bem chato. Tenho que dar 2 enters toda vez que leio os dados. Não tem como tirar isso daqui?
					printf("Insira os pontos no formato x(TAB)y: ");
					gets(aux_points);
					//scanf(" %s", aux_points);
					strcat(aux_points, "\n");
					fputs(aux_points, fptr_aux);
				}
				strcpy(graf_copia, grafico);
				snprintf(graf_copia, sizeof(graf_copia), "%s%d", graf_copia, i+1);
				fprintf(fptr_main, "\\begin{tikzpicture}\n");
				fprintf(fptr_main, "\\begin{axis}[title=%s, xlabel={%s}, ylabel={%s},width=\\textwidth, grid=major, legend style={at={(0.9,0.2)}}]\n", graf_copia, xlabel, ylabel);
				strcat(graf_copia, dat);
				fprintf(fptr_main, "\\addplot[only marks, mark = *, blue, mark size=1.5] table{%s};\n", graf_copia);
				fprintf(fptr_main, "\\addplot[thick, red]table[x=a, y={create col/linear regression={y=b}}]{%s};\n", graf_copia);
				fprintf(fptr_main, "\\addlegendentry{Dados do Experimento};\n");
				fprintf(fptr_main, "\\addlegendentry{Melhor reta: $\\pgfmathprintnumber{\\pgfplotstableregressiona} \\cdot x \\pgfmathprintnumber[print sign]{\\pgfplotstableregressionb}$};\n");
				fprintf(fptr_main, "\\end{axis}\n");
				fprintf(fptr_main, "\\end{tikzpicture}\n\n");

				fclose(fptr_aux);
			}else{
				perror("Erro aqui");
			}
		}
		fprintf(fptr_main, "\n\\end{document}");//escreve em LaTeX
		fclose(fptr_main);
	}else{
		perror("Erro ao criar arquivo");
	}
	return 0;
}
