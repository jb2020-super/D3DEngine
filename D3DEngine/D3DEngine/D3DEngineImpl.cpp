#include "pch.h"
#include "D3DEngineImpl.h"

namespace sjb{
	D3DEngineImpl::D3DEngineImpl()
	{
	}
	D3DEngineImpl::~D3DEngineImpl()
	{
	}
	HRESULT D3DEngineImpl::Init(HWND hwnd)
	{
		HRESULT hr{ S_OK };
		hr = m_pD3D9Render.Init(hwnd);
		return hr;
	}
}
