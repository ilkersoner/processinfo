#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

struct task_struct *task;
struct list_head *list;

SYSCALL_DEFINE2(my_syscall_2, int, p, int, k)
{
	if(p==0 && k==0){
		for_each_process( task ){ 
			printk(KERN_INFO "\nUID: %d PPID: %d PID: %d NAME:%s STATE:%ld",task->cred->uid, pid_vnr(task_pgrp(task)), task->pid, task->comm, task->state);
        
        		printk("-----------------------------------------------------");
		}   
	}
	else if(k==0){
		int flag=0;
		for_each_process(task){
			if(task->pid==p) {
				printk(KERN_INFO "PID: %d commandline: %s", task->pid,task->comm);
				flag=1;
				break;
			}
		}
		if(flag==0){
			printk(KERN_INFO "Process %d does not exist",p);
		}

	}
	else if(k==1){
		int flag=0;
		for_each_process(task){
			if(task->pid==p) {
				printk(KERN_INFO "Process %d was killed...",p);
				flag=1;
				break;
			}
		}
		if(flag==0){
			printk(KERN_INFO "Process %d does not exist",p);
		}
	}



	return 0;
}//son

