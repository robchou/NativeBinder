/*
 * =====================================================================================
 *
 *       Filename:  libsever.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/2012 10:28:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zzz.Mraz (Programmer), zzz.Mraz@grandstream.com
 *   Organization:  ZSTU
 *
 * =====================================================================================
 */

#define LOG_TAG "libserver"
#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "libserver.h"

namespace android {

	int Libserver::instantiate() {
		int ret;

		LOGI("Libserver instantiating...");

		ret = defaultServiceManager()->addService(String16("service.Libserver"),
		new Libserver());

		LOGI("addService ret %d", ret);
		
		return ret;
	}                                           /* generate the unique instantiation */

	Libserver::Libserver() {
		LOGI("Libserver Created");
	}

	Libserver::~Libserver() {
		LOGI("Libserver destroyed");
	}

	/* 
	 * ===  FUNCTION  ======================================================================
	 *         Name:  Libserver::onTransact
	 *  Description:  
	 * =====================================================================================
	 */
	status_t Libserver::onTransact(uint32_t code, const Parcel &data, Parcel* reply, uint32_t flags) {
		LOGI("Libserver::onTransact code = %d", code);
		Mutex::Autolock _l(mLock);

		int a = data.readInt32();
		int b = data.readInt32();
		int sum = a + b;

		LOGI("sum = %d", sum);
		reply->writeInt32(sum);
		return NO_ERROR;
	}		/* -----  end of function Libserver::onTransact  ----- */
}		/* -----  end of namespace android  ----- */
