#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include"IntermediateCodeGenerator.h"

int main()
{

	

	while (1)
	{
		system("CLS");
		printf("=========================================================================================\n");
		printf("=========================================================================================\n");
		printf("MENU\n");
		printf("=========================================================================================\n");
		printf("INPUT UR ASSEMBLY CODE\n\n");
		printf("10:load ur assembly language code\n");
		printf("11:display intermediate code\n");
		printf("12:display symbol table\n");
		printf("13:run program\n");
		printf("14:create intermediate code\n");
		printf("=========================================================================================\n");
		printf("Do you have intermediate\n\n\n");
		printf("21:enter your opcode file\n");
		printf("=========================================================================================\n");
		printf("100:exit\n");
		printf("=========================================================================================\n");
		printf("=========================================================================================\n");
		int ch;
		FILE *fp;
		char *outputfile;
		scanf("%d", &ch);
		int i;
		char *filename;
		switch (ch)
		{
		case 10:
			system("CLS");
			printf("enter file name\n");
			filename = (char *)malloc(100 * sizeof(char));
			scanf("%s", filename);

			generateIntermediate(filename);
			break;

		case 11:
			system("CLS");
			printf("\n\nintermediate table is\n");

			for (i = 1; i <= intermediatesize; i++)
			{
				printf("%d   %d", intermediatecode[i]->inNo, intermediatecode[i]->opcode);
				int j;
				for (j = 0; j < intermediatecode[i]->parametersize; j++)
				{
					printf("   %d ", intermediatecode[i]->parameters[j]);
				}
				printf("\n");
			}

			break;
		case 12:
			system("CLS");
			for (i = 0; i <= symboltablesize; i++)
				printf("%c  %d  %d\n", symboltables[i]->variable, symboltables[i]->address, symboltables[i]->size);
			break;
		case 13:
			system("CLS");
			analyseOutput();
			break;
		case 14:
			system("CLS");


			printf("enter filename to get intermediate language\n");
			outputfile = (char *)malloc(100 * sizeof(char));
			scanf("%s", outputfile);

			fp = fopen(outputfile, "w");

			for (i = 1; i <= intermediatesize; i++)
			{
				fprintf(fp, "%d %d", intermediatecode[i]->inNo, intermediatecode[i]->opcode);
				int j;
				for (j = 0; j < intermediatecode[i]->parametersize; j++)
				{
					fprintf(fp, " %d", intermediatecode[i]->parameters[j]);
				}
				fprintf(fp, "\n");
			}
			fclose(fp);


			printf("enter filename to get Symbol language\n");
			scanf("%s", outputfile);

			fp = fopen(outputfile, "w");

			for (i = 0; i <= symboltablesize; i++)
			{
				fprintf(fp, "%c %d %d", symboltables[i]->variable, symboltables[i]->address, symboltables[i]->size);
				fprintf(fp, "\n");
			}
			fclose(fp);


			break;
		case 21:
			system("CLS");
			initializeIntermediate();
			initializeLabelTable();
			initializeSymbolTable();
			initializeOpCodes();
			initializeRegister();
			stack = (int *)malloc(100 * sizeof(int));

			analyseFile();
			break;
		case 100:
			return 0;


		}


	}






	return 0;
}