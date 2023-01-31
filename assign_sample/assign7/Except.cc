#include <iostream>
#include <string.h>
#include "Except.h"

Except::Except(const char *str) {

  error=strdup(str);

}
