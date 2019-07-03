#pragma once
#include"stdin_channel.h"
class kernel
{
	int m_epollFd;
	stdin_channel* pchannel = nullptr;
public:
	kernel();
	void AddChannel(stdin_channel* _pchannel);
	stdin_channel* getChannel();
	 void run();
	virtual ~kernel();
};

