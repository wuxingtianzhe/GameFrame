#include "kernel.h"
#include<sys/epoll.h>
kernel::kernel()
{
	m_epollFd = epoll_create(100);
}
kernel  kernel::_kernel;

void kernel::AddChannel(Ichannel * _pchannel)
{
	//将参数和文件描述符0|1关联起来
	struct epoll_event fd_events;
	fd_events.events = EPOLLIN;
	fd_events.data.ptr = _pchannel;
	epoll_ctl(m_epollFd, EPOLL_CTL_ADD, _pchannel->Getfd(), &fd_events);
}

void kernel::DelChannel(Ichannel * _pchannel)
{
	epoll_ctl(m_epollFd, EPOLL_CTL_DEL, _pchannel->Getfd(), NULL);

}

void kernel::ModChannel_AddOut(Ichannel * _pchannel)
{
	struct epoll_event fd_events;
	fd_events.events = EPOLLIN|EPOLLOUT;
	fd_events.data.ptr = _pchannel;
	epoll_ctl(m_epollFd, EPOLL_CTL_MOD, _pchannel->Getfd(), &fd_events);

}

void kernel::ModChannel_DelOut(Ichannel * _pchannel)
{
	struct epoll_event fd_events;
	fd_events.events = EPOLLIN;
	fd_events.data.ptr = _pchannel;
	epoll_ctl(m_epollFd, EPOLL_CTL_MOD, _pchannel->Getfd(), &fd_events);
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
			//检查是否有读事件
			if (arr_events[i].events&EPOLLIN)
			{
				//1.读出数据
				auto pchannel = static_cast<Ichannel*>(arr_events[i].data.ptr);
				string content = pchannel->readfd();
				//2.处理数据
				pchannel->data_process(content);
			}
		//检查是否是有写事件
			if (arr_events[i].events&EPOLLOUT)
			{
				//1.读出数据
				auto pchannel = static_cast<Ichannel*>(arr_events[i].data.ptr);
				pchannel->flushdata();
				//2.删掉输出发方向的epoll监听
				ModChannel_DelOut(pchannel);
			}
	 
		
		}
	}
}


kernel::~kernel()
{
}
