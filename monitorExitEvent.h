#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>


	bool ctrlhandler( DWORD fdwctrltype );
	
	if(<span style="color:#FF0000;"> SetConsoleCtrlHandler( (PHANDLER_ROUTINE) ctrlhandler, true )</span> )
    {
    }
	else
	{
		LOG4CPP(LOG_LEVEL_ERROR,"install signal handler error");
	}


<span style="color:#FF0000;">	bool ctrlhandler( DWORD fdwctrltype )
	{
		switch( fdwctrltype )
		{
		// handle the ctrl-c signal.
		case CTRL_C_EVENT:
			//printf( "ctrl-c event\n\n" );
			//return( true );
		// ctrl-close: confirm that the user wants to exit.
		case CTRL_CLOSE_EVENT:
			//printf( "ctrl-close event\n\n" );
			//return( true );
		// pass other signals to the next handler.
		case CTRL_BREAK_EVENT:
			//printf( "ctrl-break event\n\n" );
			//return false;
		case CTRL_LOGOFF_EVENT:
			//printf( "ctrl-logoff event\n\n" );
			//return false;
		case CTRL_SHUTDOWN_EVENT:
			//printf( "ctrl-shutdown event\n\n" );
			//return false;
			//清理
			return true;
		default:
			return false;
		}
	} 
</span>