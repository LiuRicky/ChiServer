文件说明
---
* packet.h：函数封装
* MutexLock.h, Condition.h: IPC
* Conf.h: configuration
* MemoryPool.h: using memory pool to allocate memory

命名规则
---
* SP_*：智能指针share_ptr<T>
* WP_*：智能指针weak_ptr<T>
* UP_*：智能指针unique_ptr<T>

HighLight
---
* C++11 new feature
* reintepret_cast, static_cast
* smart pointer
* && move
* std::function
* use memory pool to manage memory
* Reactor model
* one loop per thread + non-blocking I/O
* epoll
* RAII
* GET

Need to do
---
some bugs need to be fixed
complete log system