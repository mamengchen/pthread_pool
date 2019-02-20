#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

typedef struct threadpool_t threadpool_t;

/*创建线程池*/
threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size);

/*释放线程池*/
int threadpool_free(threadpool_t *pool);

/*销毁线程池*/
int threadpool_destroy(threadpool_t *pool);

/*管理线程池*/
void *admin_thread(void *threadpool);

/*线程是否存在*/
//int is_thread_alive(pthread_t tid);

/*工作线程*/
void *threadpool_thread(void *threadpool);

/*向线程池的任务队列中添加一个任务*/
int threadpool_add_task(thraedpool_t *pool, void *(*function)(void *arg), void *arg);

#endif
