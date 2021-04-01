#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <locale.h>
#include "declarations.h"

int main() {
    setlocale(LC_ALL, "rus");

    FILE *file = fopen("input.txt", "r");

    struct stat tmp;
    fstat(fileno(file), &tmp);
    long size = tmp.st_size;

    char *text = (char*) malloc(size + 1);
    text[size] = '\n';
    fread(text, size, 1, file);

    fclose(file);

    int str_amount = 0;

    for (int i = 0; i < size + 1; i++)
        if (text[i] == '\n') {
            text[i] = '\0';
            str_amount++;
        }
    
    size -= str_amount - 1;

    char **pointers = (char**) malloc(sizeof(char*) * str_amount);
    int pointer_index = 1;
    pointers[0] = &text[0];

    for (int i = 1; i < size; i++) {
        if (text[i] == '\0') {
            pointers[pointer_index] = &text[i + 1];
            pointer_index++;
        }
    }

    FILE *res_file = fopen("output.txt", "w");
    
    qsort(pointers, str_amount, sizeof(char**), compare_by_beginning);

    ErrorType beg_sort_result_status = write_result(pointers, str_amount, res_file);

    if (beg_sort_result_status == SUCCESS)
        printf("\nSorted from beginning successfully");
    else
        printf("\nError writing in file (sorting from beginning)");

    qsort(pointers, str_amount, sizeof(char**), compare_by_end);

    fprintf(res_file, "\n");

    ErrorType end_sort_result_status = write_result(pointers, str_amount, res_file);

    if (end_sort_result_status == SUCCESS)
        printf("\nSorted from end successfully");
    else
        printf("\nError writing in file (sorting from end)");
    
    fprintf(res_file, "\n");
    for (int i = 0; i < size + 1; i++) {
        if (text[i] == '\0')
            fputc('\n', res_file);
        else
            fputc(text[i], res_file);
    }

    fclose(res_file);

    free(pointers);
    free(text);
    
    return 0;
}