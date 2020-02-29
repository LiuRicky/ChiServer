#include "../Conf.h"
#include <iostream>

int main(){
	Conf conf = getconf();
	char* filepath = "../ChiServerConf.conf";
	conf.init(filepath);
	printf("%s\n", "read conf");
	cout<<conf.getport()<<endl;
	return 0;
}