#pragma once

class noncopyable{
protected:
    noncopyable(){}
    ~noncopyable(){}

private:
    // make build method private and unvisible
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};