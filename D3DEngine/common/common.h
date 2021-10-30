#pragma once

#define CheckHR(func)\
	hr = (func);\
	if (FAILED(hr)){\
		return hr;\
	}

#define CheckHR_Break(func)\
	hr = (func);\
	if (FAILED(hr)){\
		break;\
	}

namespace sjb {

}