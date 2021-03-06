#include <linux/list.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

#define METHOD 3

static int list_init(void)

{

    struct task_struct *task, *p;

    struct list_head *pos;

    int count;

    char *method;

    count = 0;

    p = NULL;

    task = NULL;

    pos = NULL;

    method = NULL;

    task = &init_task;

    printk(KERN_ALERT"PID\tCOMM\n");

    switch(METHOD) {

    case 1:

        method="list_for_each";

        break;

    case 2:

        method="for_each_process";

        break;

    case 3:

        method="list_for_each_entry";

        break;

    }

    printk( "The method is %s\n", method );

#if METHOD == 1

    list_for_each( pos, &task->tasks ) {

        p = list_entry( pos, struct task_struct, tasks );

        count++;

        printk( KERN_ALERT "%d\t%s state:%d,cpu:%d\n", p->pid, p->comm,p->state,p->on_cpu);

    }

#elif METHOD == 2

    for_each_process(task) {

        count++;

        printk( KERN_ALERT "%d\t%s\n", task->pid, task->comm);

    }

#elif METHOD == 3

    list_for_each_entry( p, &task->tasks, tasks ) {

        count++;

        printk( KERN_ALERT "%d\t%s\n", p->pid, p->comm );

    }

#endif

    printk("process num:%d", count);

    return 0;

}

static void list_exit(void)
{

    printk( KERN_ALERT "GOOD BYE!!\n");
     pid *find_get_pid

}

module_init( list_init );

module_exit( list_exit );

MODULE_AUTHOR( "Along" );

MODULE_LICENSE( "GPL" );
