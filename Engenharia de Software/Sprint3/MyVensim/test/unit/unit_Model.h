#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

#include "../../src/systemInterface.h"
#include "../../src/system.h"
#include "../../src/flowInterface.h"
#include "../../src/flow.h"
#include "../../src/modelInterface.h"
#include "../../src/model.h"
#include "mem_usage.h"

#include <string>
#include <cstdio>
#include <iostream>
#include <assert.h>

using namespace std;

void unit_Model_constructor();
void unit_Model_destructor();
void unit_Model_run();
void unit_Model_add_System();
void unit_Model_add_Flow();
void run_unit_test_Model();
#endif