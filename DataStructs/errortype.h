#ifndef ERRORTYPE
#define ERRORTYPE

typedef enum ErrorType {
    SUCCESS,
    NULL_POINTER,
    SIZE_LIMIT,
    OUT_OF_BOUNDS,
    MEMORY_ALLOC_ERROR
} ErrorType;

#endif