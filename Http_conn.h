#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
//#include <sys/mman.h>
#include <memory>
#include <functional>

using namespace std;

enum METHOD{METHOD_GET,METHOD_POST};
enum HTTPVERSION{HTTP_10,HTTP_11};
enum PARSESTATE{PARSE_ERROR,PARSE_METHOD,PARSE_HEADER,PARSE_SUCCESS};

class Channel;
typedef shared_ptr<Channel> SP_Channel;

class Http_conn{
public:
    Http_conn(SP_Channel channel);
    ~Http_conn();

private:
    typedef function<PARSESTATE()> CallBack;
    CallBack handleparse[4];
    SP_Channel channel;
    bool keepalive;
    int pos;
    int size;
    string inbuffer;
    string storage;
    string path;
    string filetype;
    METHOD method;
    HTTPVERSION version;
    PARSESTATE parsestate;
    unordered_map<string, string> header;
    PARSESTATE parseMethod();
    PARSESTATE parseHeader();
	PARSESTATE parseError();
	PARSESTATE parseSuccess();
    void parse();
    void send();
    bool Read(string& msg, string str);
    void initmsg();
    void handleError(int errornum, string msg);   
};