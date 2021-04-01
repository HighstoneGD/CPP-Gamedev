#include <stdio.h>

enum ErrorType {
    SUCCESS,
    FILE_WRITE_ERROR,
    FILE_READ_ERROR
};

#define ErrorType enum ErrorType

int compare_by_beginning(const void* str1, const void* str2);

int compare_by_end(const void* str1, const void* str2);

ErrorType write_result(char** text, int strs_amount, FILE* fp);