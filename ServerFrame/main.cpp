#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<sys/file.h>
#include<sys/time.h>
#include<signal.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<arpa/inet.h>
#include"kernel.h"
#include"stdin_channel.h"
#include"stdout_channel.h"
int main(int argc, char *argv[])
{
	stdin_channel in_channel;
	stdout_channel out_channel;
	in_channel.m_out = &out_channel;
	kernel ker=kernel::getInstance();
	ker.AddChannel(&in_channel);
	ker.AddChannel(&out_channel);

	ker.run();
	return EXIT_SUCCESS;
}