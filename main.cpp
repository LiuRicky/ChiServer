#include "Server.h"
#include <signal.h>
#include "Conf.h"

int main(int argc, char **argv){

    char conf[100] = "ChiServerConf.conf";
    getconf().init(conf);

    Server server(getconf().getport().c_str(), 
        getconf().getio_thread());
    server.start();
}