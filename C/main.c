#include <stdio.h>
#include <stdlib.h>

static void read (char field[], char buffer_f[], char question[])
{
    printf(question);
    scanf_s("%s", buffer_f, 50);
    strcpy(field, buffer_f);
}

static void del (char field[]) { strcpy(field, ""); };

static void error () { printf("Opcao invalida! Digite novamente...\n"); }

int main()
{
    char buffer[50];
    int option;
    char name[50] = "";
    char profession[50] = "";
    char salary[50] = "";

    while (1)
    {
        printf("----------------------------------------------\n");
        printf("Nome: %s | Profissao: %s | Salario: %s", name, profession, salary);
        printf("\n-------------------- CRUD --------------------\n");
        printf("1 - Inserir Informacoes\n2 - Editar\n3 - Excluir\n4 - Sair do programa\n");
        printf("----------------------------------------------\n");
        printf("Opcao: ");
        scanf_s("%i", &option);

        system("cls");

        if (option == 1) {
            read(name, buffer, "Nome: ");
            system("cls");
            read(profession, buffer, "Profissao: ");
            system("cls");
            read(salary, buffer, "Salario: R$");
            system("cls");
        }
        else if (option == 2) {
            while (1)
            {
                int option_c;

                printf("Editar quais campos?\n");
                printf("1 - Nome\n2 - Profissao\n3 - Salario\n");
                printf("----------------------------------------------\n");
                printf("Opcao: ");
                scanf_s("%i", &option_c);

                system("cls");

                if (option_c == 1) {
                    read(name, buffer, "Nome: ");
                    system("cls");
                    break;
                }
                else if (option_c == 2) {
                    read(profession, buffer, "Profissao: ");
                    system("cls"); 
                    break;
                }
                else if (option_c == 3) {
                    read(salary, buffer, "Salario: R$");
                    system("cls");
                    break;
                }
                else {
                    error();
                    continue;
                }
            }
        }
        else if (option == 3) {
            while (1)
            {
                int option_c;

                printf("Deletar quais campos?\n");
                printf("1 - Nome\n2 - Profissao\n3 - Salario\n");
                printf("----------------------------------------------\n");
                printf("Opcao: ");
                scanf_s("%i", &option_c);

                system("cls");

                if (option_c == 1) {
                    del(name);
                    system("cls");
                    break;
                }
                else if (option_c == 2) {
                    del(profession);
                    system("cls");
                    break;
                }
                else if (option_c == 3) {
                    del(salary);
                    system("cls");
                    break;
                }
                else {
                    error();
                    continue;
                }
            }
        }
        else if (option == 4) {
            printf("Saindo do programa...");
            exit(0);
        }
        else {
            error();
            continue;
        }
    }

    return 0;
}