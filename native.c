#include "jsmn.h"
#include <stdint.h>

uint32_t json_primitive() { return JSMN_PRIMITIVE; }
uint32_t json_object() { return JSMN_OBJECT; }
uint32_t json_array() { return JSMN_ARRAY; }
uint32_t json_string() { return JSMN_STRING; }
