#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"

int main(){
    
    run_unit_test_Flow();
    run_unit_test_System();
    run_unit_test_Model();
    
    return 0;
}