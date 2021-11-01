#pragma once
#include <Windows.h>
#include <atlbase.h>
#include <d3d9.h>
#include <d3d9types.h>

namespace sjb {
	class D3D9Render
	{
	public:
		D3D9Render();
		~D3D9Render();
		HRESULT Init(HWND hwnd);
	private:
		int _check_HW_vertex_processing();
		void _fill_default_params(D3DPRESENT_PARAMETERS &params);
	private:
		CComPtr<IDirect3D9> m_d3d9;
		CComPtr<IDirect3DDevice9> m_d3d9Device;
	};
}