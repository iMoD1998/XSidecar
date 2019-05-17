#include "XSidecar.h"
#include <stdio.h>

HMODULE XSidecar = NULL;

XSidecarOpenEmulatorList_t XSidecarOpenEmulatorList = NULL;
XSidecarOpenListItem_t XSidecarOpenListItem = NULL;
XSidecarGetListItemCount_t XSidecarGetListItemCount = NULL;
XSidecarGetListItemName_t XSidecarGetListItemName = NULL;
XSidecarCloseList_t XSidecarCloseList = NULL;

XSidecarGetName_t XSidecarGetName = NULL;
XSidecarGetConsoleSerialNumber_t XSidecarGetConsoleSerialNumber = NULL;
XSidecarGetVersionInformation_t XSidecarGetVersionInformation = NULL;

XSidecarEmulatorOpenKdPipe_t XSidecarEmulatorOpenKdPipe = NULL;
XSidecarEmulatorCloseKdPipe_t XSidecarEmulatorCloseKdPipe = NULL;

XSidecarEmulatorSetPowerState_t XSidecarEmulatorSetPowerState = NULL;
XSidecarEmulatorGetPowerState_t XSidecarEmulatorGetPowerState = NULL;

XSidecarEmulatorPressTrayEject_t XSidecarEmulatorPressTrayEject = NULL;
XSidecarEmulatorGetTrayState_t XSidecarEmulatorGetTrayState = NULL;

XSidecarEmulatorSpiBegin_t XSidecarEmulatorSpiBegin = NULL;
XSidecarEmulatorSpiEnd_t XSidecarEmulatorSpiEnd = NULL;
XSidecarEmulatorSpiRead_t XSidecarEmulatorSpiRead = NULL;
XSidecarEmulatorSpiWrite_t XSidecarEmulatorSpiWrite = NULL;

XSidecarReadFpgaRegister_t XSidecarReadFpgaRegister = NULL;
XSidecarWriteFpgaRegister_t XSidecarWriteFpgaRegister = NULL;

bool XSidecarGetExports( HMODULE XSidecar )
{
	XSidecarOpenEmulatorList = (XSidecarOpenEmulatorList_t)GetProcAddress( XSidecar, "XSidecarOpenEmulatorList" );
	XSidecarOpenListItem = (XSidecarOpenListItem_t)GetProcAddress( XSidecar, "XSidecarOpenListItem" );
	XSidecarGetListItemCount = (XSidecarGetListItemCount_t)GetProcAddress( XSidecar, "XSidecarGetListItemCount" );
	XSidecarGetListItemName = (XSidecarGetListItemName_t)GetProcAddress( XSidecar, "XSidecarGetListItemName" );
	XSidecarCloseList = (XSidecarCloseList_t)GetProcAddress( XSidecar, "XSidecarCloseList" );

	XSidecarGetName = (XSidecarGetName_t)GetProcAddress( XSidecar, "XSidecarGetName" );
	XSidecarGetConsoleSerialNumber = (XSidecarGetConsoleSerialNumber_t)GetProcAddress( XSidecar, "XSidecarGetConsoleSerialNumber" );
	XSidecarGetVersionInformation = (XSidecarGetVersionInformation_t)GetProcAddress( XSidecar, "XSidecarGetVersionInformation" );

	XSidecarEmulatorOpenKdPipe = (XSidecarEmulatorOpenKdPipe_t)GetProcAddress( XSidecar, "XSidecarEmulatorOpenKdPipe" );
	XSidecarEmulatorCloseKdPipe = (XSidecarEmulatorCloseKdPipe_t)GetProcAddress( XSidecar, "XSidecarEmulatorCloseKdPipe" );

	XSidecarEmulatorSetPowerState = (XSidecarEmulatorSetPowerState_t)GetProcAddress( XSidecar, "XSidecarEmulatorSetPowerState" );
	XSidecarEmulatorGetPowerState = (XSidecarEmulatorGetPowerState_t)GetProcAddress( XSidecar, "XSidecarEmulatorGetPowerState" );

	XSidecarEmulatorPressTrayEject = (XSidecarEmulatorPressTrayEject_t)GetProcAddress( XSidecar, "XSidecarEmulatorPressTrayEject" );
	XSidecarEmulatorGetTrayState = (XSidecarEmulatorGetTrayState_t)GetProcAddress( XSidecar, "XSidecarEmulatorGetTrayState" );

	XSidecarEmulatorSpiBegin = (XSidecarEmulatorSpiBegin_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiBegin" );
	XSidecarEmulatorSpiEnd = (XSidecarEmulatorSpiEnd_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiEnd" );
	XSidecarEmulatorSpiRead = (XSidecarEmulatorSpiRead_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiRead" );
	XSidecarEmulatorSpiWrite = (XSidecarEmulatorSpiWrite_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiWrite" );

	XSidecarReadFpgaRegister = (XSidecarReadFpgaRegister_t)GetProcAddress( XSidecar, "XSidecarReadFpgaRegister" );
	XSidecarWriteFpgaRegister = (XSidecarWriteFpgaRegister_t)GetProcAddress( XSidecar, "XSidecarWriteFpgaRegister" );

	return true;
}

bool LoadXSidecar( )
{
	char DllPath[ 0x1000 ];

	memset( DllPath, 0, sizeof( DllPath ) );

	if ( GetEnvironmentVariableA( "XEDK", DllPath, 255 ) == 0 )
	{
		printf( "Couldn't load xsidecar.dll\nXEDK environment variable not set.\n" );

		return false;
	}

	strcat_s( DllPath, "\\bin\\win32\\xsidecar.dll" );

	XSidecar = LoadLibraryA( DllPath );

	if ( !XSidecar )
	{
		printf( "Couldn't load xsidecar.dll\n" );

		return false;
	}

	return XSidecarGetExports( XSidecar );
}

bool UnloadXSidecar( )
{
	return FreeLibrary( XSidecar );
}