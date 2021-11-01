#include "pch.h"
#include "D3DEngine.h"

#include "D3DEngineImpl.h"

namespace sjb{
	HRESULT CreateD3DEngine(D3DEngine** pEngine)
	{
		HRESULT hr{ S_OK };
		if (pEngine) {
			*pEngine = new D3DEngineImpl();
			if (!*pEngine) {
				hr = E_OUTOFMEMORY;
			}
		}
		return hr;
	}
}