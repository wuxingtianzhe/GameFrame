#pragma once
#include"stdin_channel.h"
class kernel
{
	int m_epollFd=-1;
	stdin_channel* pchannel = nullptr;
	kernel();
	static kernel _kernel;
public:
	void AddChannel(Ichannel* _pchannel);
	void DelChannel(Ichannel* _pchannel);
	void ModChannel_AddOut(Ichannel* _pchannel);
	void ModChannel_DelOut(Ichannel* _pchannel);
	 void run();
	virtual ~kernel();
	static kernel& getInstance() 
	{
		return _kernel;
	}
};

