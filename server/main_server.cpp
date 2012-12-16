/*
 * =====================================================================================
 *
 *       Filename:  main_server.cpp
 *
 *    Description:  binder server process
 *
 *        Version:  1.0
 *        Created:  12/06/2012 12:01:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zzz.Mraz (Programmer), zzz.Mraz@gmail.com
 *   Organization:  ZSTU
 *
 * =====================================================================================
 */
//#include <sys/types>
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <libserver/libserver.h>

using namespace android;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  start a process to invoke libserver's function
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();
	LOGI("ServiceManager: %p", sm.get());
	Libserver::instantiate();
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
}				/* ----------  end of function main  ---------- */

