#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/lib/systemInterface.h"
#include "../../src/lib/system.h"
#include "../../src/lib/flowInterface.h"
#include "../../src/lib/flow.h"
#include "../../src/lib/modelInterface.h"
#include "../../src/lib/model.h"
#include "mem_usage.h"

#include <string>
#include <cstdio>
#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

void unit_Model_constructor();
void unit_Model_destructor();
void unit_Model_run();
void unit_Model_add_System();
void unit_Model_add_Flow();
void run_unit_test_Model();
#endif