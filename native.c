#include "jsmn.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MEM_START 32
#define MEM_MULTI 2

jsmntok_t *native_parse(const char *str){
    jsmn_parser parser;
    jsmn_init(&parser);
    uint32_t count = MEM_START;
    int r = JSMN_ERROR_NOMEM;
    jsmntok_t *tok = NULL;
    while(r = JSMN_ERROR_NOMEM){
        if(tok != NULL)free(tok);
        tok = malloc(sizeof(jsmntok_t) * count);
        r = jsmn_parse(&parser, str, strlen(str), tok, count);
        count *= MEM_MULTI;
    }
    if(r >= 0){
        return tok;
    }else{
        return NULL;
    }
}

uint32_t json_primitive() { return JSMN_PRIMITIVE; }
uint32_t json_object() { return JSMN_OBJECT; }
uint32_t json_array() { return JSMN_ARRAY; }
uint32_t json_string() { return JSMN_STRING; }
