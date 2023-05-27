#include "mem_usage.h"

using namespace std;

void memory_usage(double& vm_usage, double& resident_set) { //uso da memoria
    vm_usage = 0.0;
    resident_set = 0.0;

    ifstream stat_stream("/proc/self/stat", ios_base::in); //pega informacoes do diretorio proc
    
    //Cria variaveis para pegar as informacoes
    string pid, comm, state, ppid, pgrp, session, tty_nr;
    string tpgid, flags, minflt, cminflt, majflt, cmajflt;
    string utime, stime, cutime, cstime, priority, nice;
    string O, itrealvalue, starttime;
    unsigned long vsize;
    long rss;

    stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
                >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
                >> utime >> stime >> cutime >> cstime >> priority >> nice
                >> O >> itrealvalue >> starttime >> vsize >> rss;
    stat_stream.close();
    vm_usage = vsize / 1024.0;
}