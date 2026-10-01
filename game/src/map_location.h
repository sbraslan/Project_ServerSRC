
#include "../../common/stl.h"

class CMapLocation : public singleton<CMapLocation>
{
public:
	typedef struct SLocation
	{
		int32_t addr;
		uint16_t port;
	} TLocation;

	bool Get(long x, long y, long& lMapIndex, int32_t& lAddr, uint16_t& wPort);
	bool Get(int iIndex, int32_t& lAddr, uint16_t& wPort);
	void Insert(long lIndex, const char* c_pszHost, uint16_t wPort);

protected:
	std::map<long, TLocation> m_map_address;
};
