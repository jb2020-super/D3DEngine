#pragma once
#include "D3DEngine.h"
#include "D3D9Render.h"
namespace sjb {
	class D3DEngineImpl :
		public D3DEngine
	{
	public:
		D3DEngineImpl();
		~D3DEngineImpl();
		// Í¨¹ý D3DEngine ¼Ì³Ð
		virtual HRESULT Init(HWND hwnd) override;
	private:
		D3D9Render m_pD3D9Render;
	};

}