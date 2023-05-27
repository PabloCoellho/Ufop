#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

#include "../../src/systemInterface.h"
#include "../../src/system.h"
#include "../../src/model.h"
#include "../../src/modelInterface.h"
#include "mem_usage.h"

#include <string>
#include <cstdio>
#include <iostream>
#include <assert.h>

using namespace std;

void unit_System_constructor();
void unit_System_destructor();
void unit_System_setName();
void unit_System_setValue();
void unit_System_getName();
void unit_System_getValue();
void unit_System_operator();
void run_unit_test_System();

#endif