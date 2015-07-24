#include <general.h>
#include <data_group.h>

dVec2D pairUp(dVec data1, dVec data2)
{
	return std::make_pair(data1, data2);
}

void pairPlot(uint n, dVec2D data)
{
	DataGroup obj(n, data.first, data.second);
	obj.plot2D();
}
