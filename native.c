#include "jsmn.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MEM_START 32
#define MEM_MULTI 2

jsmntok_t *native_parse(const char *str, uint32_t *count){
    jsmn_parser parser;
    jsmn_init(&parser);
    *count = MEM_START;
    int r = JSMN_ERROR_NOMEM;
    jsmntok_t *tok = NULL;
    while(r == JSMN_ERROR_NOMEM){
        if(tok != NULL)free(tok);
        tok = malloc(sizeof(jsmntok_t) * *count);
        r = jsmn_parse(&parser, str, strlen(str), tok, *count);
        *count *= MEM_MULTI;
    }
    if(r >= 0){
        *count = (uint32_t)r;
        return tok;
    }else{
        return NULL;
    }
}

int32_t json_primitive() { return (int)JSMN_PRIMITIVE; }
int32_t json_object() { return (int)JSMN_OBJECT; }
int32_t json_array() { return (int)JSMN_ARRAY; }
int32_t json_string() { return (int)JSMN_STRING; }
int32_t json_undefined() { return (int)JSMN_UNDEFINED; }
