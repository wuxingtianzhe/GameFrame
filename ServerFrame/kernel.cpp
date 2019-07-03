#include "kernel.h"
#include<sys/epoll.h>
kernel::kernel()
{
	m_epollFd = epoll_create(100);
}

void kernel::AddChannel(stdin_channel * _pchannel)
{
	//将参数和文件描述符0关联起来
	struct epoll_event fd_events;
	fd_events.events = EPOLLIN;
	fd_events.data.ptr = _pchannel;
	epoll_ctl(m_epollFd, EPOLL_CTL_ADD, 0, &fd_events);
}

stdin_channel * kernel::getChannel()
{
	return pchannel;
}

void kernel::run()
{
	while (1)
	{
	/*string ret = pchannel->readfd();
	cout << ret << endl;*/
		//1.等待输入(epoll)
		struct epoll_event arr_events[200];
		int num=epoll_wait(m_epollFd, arr_events, 200, -1);
		if (num==0)
		{
			if (EINTR==errno)
			{
				continue;
			}
		}
		if (num == -1)
		{
			perror("epoll_wait");
			
		}
		//2.调用输入通道的读取函数
		for (int i = 0; i < num; i++)
		{
		
		auto pchannel=static_cast<stdin_channel*>(arr_events[i].data.ptr);
		string content=pchannel->readfd();
		//3.回显到标准输出
		cout << content << endl;
		
		}


	}
}


kernel::~kernel()
{
}
