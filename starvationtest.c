#include "types.h"
#include "stat.h"
#include "user.h"

void long_task(int pid, int cnt) {
    int i;//, pp = 0;//get_proc_priority(pid);
    for (i = 0; i < cnt; i++) {
        if (i % 100 == 0) // pp != get_proc_priority(pid))
		{
			//pp = get_proc_priority(pid);
            printf(1, "Process %d is running\n", pid);
			ps();
		}
    }
	ps();
}

int main(void) {
    int p1, p2, p3, p4;

    p1 = fork();
    if (p1 == 0) {
        set_proc_priority(getpid(), 4);
        long_task(getpid(), 5000);
        exit();
    }

    p2 = fork();
    if (p2 == 0) {
        set_proc_priority(getpid(), 4);
        long_task(getpid(), 5000);
        exit();
    }

    p3 = fork();
    if (p3 == 0) {
        set_proc_priority(getpid(), 10);
        long_task(getpid(), 500);
        exit();
    }

	p4 = fork();
    if (p4 == 0) {
        set_proc_priority(getpid(), 5);
        long_task(getpid(), 500);
        exit();
    }

    wait();
    wait();
    wait();
	wait();

	ps();

    exit();
}