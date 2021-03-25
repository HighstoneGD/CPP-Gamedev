#include "declarations.h"

int compare_by_beginning(const void* str1, const void* str2) {
    const char **i_str1 = (const char **) str1;
    const char **i_str2 = (const char **) str2;
    return strcmp(*i_str1, *i_str2);
}

int compare_by_end(const void* str1, const void* str2) {
    const char **i_str1 = (const char **) str1;
    const char **i_str2 = (const char **) str2;
    strrev(*i_str1);
    strrev(*i_str2);
    int result = strcmp(*i_str1, *i_str2);
    strrev(*i_str1);
    strrev(*i_str2);
    return result;
}

ErrorType write_result(char** text, int strs_amount, FILE* fp) {
    ErrorType status = SUCCESS;
    for (int i = 0; i < strs_amount; i++) {
        if (fprintf(fp, "%s\n", text[i]) < 0)
            status = FILE_WRITE_ERROR;
    }
    return status;
}