#include <stdio.h>
#include <stdlib.h>
#define MAX 100

static void read (char field[], char buffer_f[], char question[])
{
    printf(question);
    scanf_s("%s", buffer_f, MAX);
    strcpy(field, buffer_f);
}

static void del (char field[]) 
{ 
    strcpy(field, ""); 
};

static void error () 
{ 
    printf("Opcao invalida! Digite novamente...\n"); 
}

int main()
{
    char buffer[MAX];
    int option;
    char name[50] = "";
    char profession[50] = "";
    char salary[50] = "";

    while (1)
    {
        printf("----------------------------------------------\n");
        printf("Nome: %s | Profissao: %s | Salario: %s", name, profession, salary);
        printf("\n-------------------- CRUD --------------------\n");
        printf("1 - Inserir Informacoes\n2 - Atualizar\n3 - Excluir\n4 - Outras Opcoes\n5 - Sair do Sistema\n");
        printf("----------------------------------------------\n");
        printf("Opcao: ");
        scanf_s("%i", &option);

        system("cls");

        if (option == 1) 
        {
            read(name, buffer, "Nome: ");
            system("cls");
            read(profession, buffer, "Profissao: ");
            system("cls");
            read(salary, buffer, "Salario: R$");
            system("cls");
        }
        else if (option == 2) 
        {
            while (1)
            {
                int option_c;

                printf("Editar quais campos?\n");
                printf("1 - Nome\n2 - Profissao\n3 - Salario\n");
                printf("----------------------------------------------\n");
                printf("Opcao: ");
                scanf_s("%i", &option_c);

                system("cls");

                if (option_c == 1) 
                {
                    read(name, buffer, "Nome: ");
                    system("cls");
                    break;
                }
                else if (option_c == 2) 
                {
                    read(profession, buffer, "Profissao: ");
                    system("cls"); 
                    break;
                }
                else if (option_c == 3) 
                {
                    read(salary, buffer, "Salario: R$");
                    system("cls");
                    break;
                }
                else 
                {
                    error();
                    continue;
                }
            }
        }
        else if (option == 3) 
        {
            while (1)
            {
                int option_c;

                printf("Deletar quais campos?\n");
                printf("1 - Nome\n2 - Profissao\n3 - Salario\n");
                printf("----------------------------------------------\n");
                printf("Opcao: ");
                scanf_s("%i", &option_c);

                system("cls");

                if (option_c == 1) 
                {
                    del(name);
                    system("cls");
                    break;
                }
                else if (option_c == 2) 
                {
                    del(profession);
                    system("cls");
                    break;
                }
                else if (option_c == 3) 
                {
                    del(salary);
                    system("cls");
                    break;
                }
                else 
                {
                    error();
                    continue;
                }
            }
        }
        else if (option == 4) 
        {
            while (1)
            {
                int option_c;
                float br_salary;


                printf("1 - Calculo de Salario Liquido\n");
                printf("----------------------------------------------\n");
                printf("Opcao: ");
                scanf_s("%i", &option_c);
                system("cls");

                if (option_c == 1) 
                {
                    double inss;

                    printf("Salario Bruto: R$");
                    scanf_s("%f", &br_salary);
                    system("cls");

                    if (br_salary <= 1412) 
                    { 
                        inss = (br_salary * 7.5) / 100;
                    }
                    else if (br_salary >= 1412.01 && br_salary <= 2666.68)
                    {
                        inss = (br_salary - 1412.01) * 0.09 + 105.90;
                    }
                    else if (br_salary >= 2666.69 && br_salary <= 4000.03)
                    {
                        inss = (br_salary - 2666.68) * 0.12 + 112.92;
                    }
                    else if (br_salary > 4000.03 && br_salary <= 7786.02)
                    {
                        inss = (br_salary - 4000.03) * 0.14 + 160.00;
                    }
                    else
                    {
                        inss = 713.10;
                    }

                    double convert_salary = br_salary - inss;

                    sprintf_s(salary, 50, "%.2f", convert_salary);

                    printf("Salario Liquido: %s", salary);
                }

            }
        }
        else if (option == 5) 
        {
            printf("Saindo do programa...");
            exit(0);
        }
        else 
        {
            error();
            continue;
        }
    }

    return 0;
}