/*
 * =====================================================================================
 *
 *       Filename:  main_client.cpp
 *
 *    Description:  test server
 *
 *        Version:  1.0
 *        Created:  12/06/2012 01:54:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zzz.Mraz (Programmer), zzz.Mraz@gmail.com
 *   Organization:  ZSTU
 *
 * =====================================================================================
 */
#define LOG_TAG "client"
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/Parcel.h>
#include <libserver/libserver.h>

using namespace android;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  binder client process 
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	sp<IServiceManager> sm = defaultServiceManager();
	sp<IBinder> mClient;
	Parcel data, reply;
	int sum = 0;
	while ( 1 ) {
		mClient = sm->getService(String16("service.Libserver"));

		if ( mClient == NULL ) {
			LOGE("Libserver not published, waiting...");
			usleep(1000000);
			continue;
		}

		else {
			LOGI("get server.Libserver success...");
			break;
		}
	}
	data.writeInt32(100);
	data.writeInt32(200);
	mClient->transact(0, data, &reply);
	sum = reply.readInt32();
	LOGI("sum = %d", sum);
	return 0;
}				/* ----------  end of function main  ---------- */

