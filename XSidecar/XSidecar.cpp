#include "XSidecar.h"
#include <stdio.h>

HMODULE XSidecar = NULL;

XSidecarOpenEmulatorList_t XSidecarOpenEmulatorList = NULL;
XSidecarEmulatorOpenKdPipe_t XSidecarEmulatorOpenKdPipe = NULL;
XSidecarEmulatorCloseKdPipe_t XSidecarEmulatorCloseKdPipe = NULL;
XSidecarGetListItemCount_t XSidecarGetListItemCount = NULL;
XSidecarOpenListItem_t XSidecarOpenListItem = NULL;
XSidecarEmulatorSetPowerState_t XSidecarEmulatorSetPowerState = NULL;
XSidecarEmulatorGetPowerState_t XSidecarEmulatorGetPowerState = NULL;
XSidecarGetName_t XSidecarGetName = NULL;
XSidecarGetConsoleSerialNumber_t XSidecarGetConsoleSerialNumber = NULL;
XSidecarGetVersionInformation_t XSidecarGetVersionInformation = NULL;
XSidecarCloseList_t XSidecarCloseList = NULL;
XSidecarEmulatorSpiBegin_t XSidecarEmulatorSpiBegin = NULL;
XSidecarEmulatorSpiEnd_t XSidecarEmulatorSpiEnd = NULL;
XSidecarEmulatorSpiRead_t XSidecarEmulatorSpiRead = NULL;
XSidecarEmulatorSpiWrite_t XSidecarEmulatorSpiWrite = NULL;

bool XSidecarGetExports( HMODULE XSidecar )
{
	XSidecarOpenEmulatorList = (XSidecarOpenEmulatorList_t)GetProcAddress( XSidecar, "XSidecarOpenEmulatorList" );
	XSidecarEmulatorOpenKdPipe = (XSidecarEmulatorOpenKdPipe_t)GetProcAddress( XSidecar, "XSidecarEmulatorOpenKdPipe" );
	XSidecarEmulatorCloseKdPipe = (XSidecarEmulatorCloseKdPipe_t)GetProcAddress( XSidecar, "XSidecarEmulatorCloseKdPipe" );
	XSidecarCloseList = (XSidecarCloseList_t)GetProcAddress( XSidecar, "XSidecarCloseList" );
	XSidecarGetListItemCount = (XSidecarGetListItemCount_t)GetProcAddress( XSidecar, "XSidecarGetListItemCount" );
	XSidecarOpenListItem = (XSidecarOpenListItem_t)GetProcAddress( XSidecar, "XSidecarOpenListItem" );
	XSidecarEmulatorSetPowerState = (XSidecarEmulatorSetPowerState_t)GetProcAddress( XSidecar, "XSidecarEmulatorSetPowerState" );
	XSidecarEmulatorGetPowerState = (XSidecarEmulatorGetPowerState_t)GetProcAddress( XSidecar, "XSidecarEmulatorGetPowerState" );
	XSidecarGetName = (XSidecarGetName_t)GetProcAddress( XSidecar, "XSidecarGetName" );
	XSidecarGetConsoleSerialNumber = (XSidecarGetConsoleSerialNumber_t)GetProcAddress( XSidecar, "XSidecarGetConsoleSerialNumber" );
	XSidecarGetVersionInformation = (XSidecarGetVersionInformation_t)GetProcAddress( XSidecar, "XSidecarGetVersionInformation" );
	XSidecarEmulatorSpiBegin = (XSidecarEmulatorSpiBegin_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiBegin" );
	XSidecarEmulatorSpiEnd = (XSidecarEmulatorSpiEnd_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiEnd" );
	XSidecarEmulatorSpiRead = (XSidecarEmulatorSpiRead_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiRead" );
	XSidecarEmulatorSpiWrite = (XSidecarEmulatorSpiWrite_t)GetProcAddress( XSidecar, "XSidecarEmulatorSpiWrite" );
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