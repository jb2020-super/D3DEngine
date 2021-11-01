// D3D9Render.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"
#include "D3D9Render.h"

namespace sjb {
	D3D9Render::D3D9Render()
	{
	}

	D3D9Render::~D3D9Render()
	{
	}

	HRESULT D3D9Render::Init(HWND hwnd)
	{
		HRESULT hr{ S_OK };
		m_d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
		if (!m_d3d9) {
			// TODO log
			return E_FAIL;
		}
		auto vp = _check_HW_vertex_processing();

		D3DPRESENT_PARAMETERS d3d_params{};
		_fill_default_params(d3d_params);

		CheckHR(m_d3d9->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hwnd, // todo
			vp,
			&d3d_params,
			&m_d3d9Device));
		return hr;
	}

	int D3D9Render::_check_HW_vertex_processing()
	{
		int vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		do
		{
			HRESULT hr{ S_OK };
			D3DCAPS9 d3dcaps9{};
			CheckHR_Break(m_d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dcaps9));
			int vp{};
			if (d3dcaps9.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
				vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
			}
		} while (false);
		return vp;
	}

	void D3D9Render::_fill_default_params(D3DPRESENT_PARAMETERS & params)
	{
		params.BackBufferWidth = 1600;
		params.BackBufferHeight = 900;
		params.BackBufferFormat = D3DFMT_A8R8G8B8;
		params.BackBufferCount = 1;
		params.MultiSampleType = D3DMULTISAMPLE_NONE;
		params.MultiSampleQuality = 0;
		params.SwapEffect = D3DSWAPEFFECT_DISCARD; // most efficient
		params.hDeviceWindow = nullptr;
		params.Windowed = TRUE;
		params.EnableAutoDepthStencil = true;
		params.AutoDepthStencilFormat = D3DFMT_D24S8;
		params.Flags = 0;
		params.FullScreen_RefreshRateInHz = 0;
		params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	}
}