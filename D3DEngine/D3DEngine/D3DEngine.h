#pragma once

#if defined D3DENGINE_EXPORTS
#define ENGINE_EXPORT __declspec(dllexport)
#else
#define ENGINE_EXPORT __declspec(dllimport)
#endif

namespace sjb {
	

	class ENGINE_EXPORT D3DEngine
	{
	public:
		D3DEngine() {};
		virtual ~D3DEngine() {};
		virtual HRESULT Init(HWND hwnd) = 0;
	private:

	};
	ENGINE_EXPORT HRESULT CreateD3DEngine(D3DEngine** pEngine);
}