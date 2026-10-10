#ifdef _WIN32

#ifdef _DEBUG
#include "vld.h"
#endif
#include "Engine.h"
#include "Player.h"
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>
#include "Scene0.h"
#include "Scene1.h"


INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT){ 
#else 
int main(int argc, char** argv) {
#endif	
	homer::Engine* eng = homer::Engine::Get();
	eng->Init("Dr.Mario", 800, 600);
	eng->World()->Register("Scene0", new Scene0());
	eng->World()->Register("Scene1", new Scene1());
	eng->World()->Load("Scene0");
	eng->Start();
	delete eng;
	return 0;
}