#include "Server.h"
#include <signal.h>
#include "Conf.h"
#include "MemoryPool.h"
#include "Conf.h"

int main(int argc, char **argv){
    init_memorypool();
    char conf[100] = "ChiServerConf.conf";
    getconf().init(conf);
    Server server(getconf().getport().c_str(), 
                    getconf().getio_thread());
    server.start();
}