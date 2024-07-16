#include "ctx.hpp"
#include "Crypt.h"
#include "overlay.hpp"
#include "grdv/global.h"
#include "grdv/binary/bytes.h"
#include "Cache.hpp"
#include "auth.hpp"
#include "lazy.h"

#define FOREGROUND_WHITE 0x0007
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN )
#pragma section(".SPN", read, write, execute)
__declspec(allocate(".SPN")) bool SpnProtected = true;


void SetConsoleColor(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void PrintColoredChar(char character, WORD color)
{
	SetConsoleColor(color);
	std::cout << character;
}


void PrintStyledChars(char openingChar, char contentChar, char closingChar, WORD openingColor, WORD contentColor, WORD closingColor)
{
	SetConsoleColor(openingColor);
	std::cout << openingChar;
	SetConsoleColor(contentColor);
	std::cout << contentChar;
	SetConsoleColor(closingColor);
	std::cout << closingChar;
	SetConsoleColor(FOREGROUND_WHITE);
}

using namespace KeyAuth;

auto name = ("priv");
auto ownerid = ("qhmn2aIwBh");
auto secret = ("bdc885d9da8dcb335e04461f30f471ca03db34cc162de6ea32af8e9e5d2b7685");
auto version = ("1.0");
auto url = ("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

const wchar_t* ٽيسٽ = (L"C:\\Windows\\System32\\Drivers\\NtVuln.sys");
const wchar_t* بنياد = (L"C:\\Windows\\System32\\Drivers\\Ntware.sys");

NTSTATUS Status = STATUS_UNSUCCESSFUL;

void LoadDrivers() {


	const char* filePath = "C:\\Windows\\System32\\Drivers\\Ntware.sys";
	std::ofstream outFile(filePath, std::ios::binary);

	if (outFile.is_open()) {
		outFile.write(reinterpret_cast<char*>(drv), sizeof(drv));
		outFile.close();
	}
	const char* outpt = "C:\\Windows\\System32\\Drivers\\NtVuln.sys";
	std::ofstream vuln(outpt, std::ios::binary);

	if (vuln.is_open()) {
		vuln.write(reinterpret_cast<const char*>(shell_mapper), sizeof(shell_mapper));
		vuln.close();
	}



	Status = WindLoadDriver((PWCHAR)ٽيسٽ, (PWCHAR)بنياد, FALSE);

	if (NT_SUCCESS(Status))
	{
		PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
		std::cout << " Driver Loaded Successfully. \n";
	}
	else
	{
		PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
		std::cout << " Driver Failed To Load. \n";
	}
	Sleep(2000);
}



int main()
{

	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	std::cout << (E(" Connecting to servers... \n")) << std::flush;

	KeyAuthApp.init(false, false);

	KeyAuthApp.check();

	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	printf(" Welcome to DriverFN \n ");


	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	printf(" Enter Your License Key: ");

	std::string key;
	std::cin >> key;
	KeyAuthApp.license(key);
	if (!KeyAuthApp.data.success)
	{
		LI_FN(system)(E("cls"));
		PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
		std::cout << (E(" License Is Invalid \n")) << std::flush;
		LI_FN(Sleep)(1500);
		exit(0);
	}

	LI_FN(system)(E("cls"));
	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	std::cout << (E(" Do you want to load drivers (NON UEFI) y/n: ")) << std::flush;
	std::string opt;
	std::cin >> opt;


	if (opt == "y") {
		LoadDrivers();
	}
	


	io::find_driver();

	if (!io::find_driver()) {
		PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
		std::cout << " Driver has not been loaded. \n" << std::endl;
		Sleep(1500);
		exit(0);
	}
	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	std::cout << " Found Driver Handle: " << io::driver_handle << "\n" << std::endl;
	Sleep(1000);

	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	std::cout << (E(" Press F8 in lobby \n")) << std::flush;

	while (GetAsyncKeyState(VK_F8) == 0) {
		// Keep waiting until F8 is pressed
		Sleep(100);  // Sleep for a short duration to avoid high CPU usage
	}
	io::process_id = io::find_process("FortniteClient-Win64-Shipping.exe");
	//ctx->GetCr3(ctx->pid);
	base_address = io::get_base_address();

	PrintStyledChars('[', '~', ']', FOREGROUND_WHITE, FOREGROUND_INTENSITY | FOREGROUND_YELLOW, FOREGROUND_WHITE);
	std::cout << " Game Image Base: " << base_address << "\n" << std::endl;
	Sleep(1000);

	mouse_interface();

	auto win32u = LI_FN(LoadLibraryA).safe_cached()(E("win32u.dll"));
	void* NtUserInjectMouseInputAddress = (void*)LI_FN(GetProcAddress).safe_cached()(win32u, E("NtUserInjectMouseInput"));
	*(void**)&_NtUserInjectMouseInput = NtUserInjectMouseInputAddress;
	LI_FN(FreeLibrary).get()(win32u);

	Hijack();

	Init();

	std::thread(EntityCache).detach();

	//std::thread(PredicitonCache).detach();


	//std::thread(LootCache).detach();

	Draw();
}