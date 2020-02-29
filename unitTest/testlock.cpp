#include "../Condition.h"

int main(){
    pthread_mutex_t a;
    MutexLock tid = MutexLock(a);
    MutexLockGuard lock = MutexLockGuard(tid);
    Condition cond = Condition(lock);
}