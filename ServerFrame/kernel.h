#pragma once
#include"stdin_channel.h"
class kernel
{
	stdin_channel* pchannel = nullptr;
public:
	kernel();
	void setChannel(stdin_channel* _pchannel);
	stdin_channel* getChannel();
	 void run();
	virtual ~kernel();
};

