#include "kernel.h"



kernel::kernel()
{
}

void kernel::setChannel(stdin_channel * _pchannel)
{
	pchannel = _pchannel;
}

stdin_channel * kernel::getChannel()
{
	return pchannel;
}

void kernel::run()
{
	while (1)
	{
	string ret = pchannel->readfd();
	cout << ret << endl;

	}
}


kernel::~kernel()
{
}
