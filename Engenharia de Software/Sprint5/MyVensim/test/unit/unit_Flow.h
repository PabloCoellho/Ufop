#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

#include "../../src/lib/systemInterface.h"
#include "../../src/lib/system.h"
#include "../../src/lib/flowInterface.h"
#include "../../src/lib/flow.h"
#include "mem_usage.h"

#include <string>
#include <cstdio>
#include <iostream>
#include <assert.h>

using namespace std;

void unit_Flow_constructor();
void unit_Flow_destructor();
void unit_Flow_setSource();
void unit_Flow_setDestination();
void unit_Flow_getSource();
void unit_Flow_getDestination();
void unit_Flow_operator();
void run_unit_test_Flow();

#endif