#ifndef __LIBSERVER_H__
#define  __LIBSERVER_H__

#include <binder/Parcel.h>
#include <utils/threads.h>

namespace android {

	/*
	 * =====================================================================================
	 *        Class:  Libserver
	 *  Description:  
	 * =====================================================================================
	 */
	class Libserver : public BBinder
	{
		public:
			/* ====================  LIFECYCLE     ======================================= */
			Libserver ();                             /* constructor */
			virtual ~Libserver ();                    /* destructor */
			/* ====================  ACCESSORS     ======================================= */

			/* ====================  MUTATORS      ======================================= */
			static int instantiate();
			virtual status_t onTransact(uint32_t, const Parcel&, Parcel*, uint32_t);

			/* ====================  OPERATORS     ======================================= */

		protected:
			/* ====================  METHODS       ======================================= */

			/* ====================  DATA MEMBERS  ======================================= */

		private:
			/* ====================  METHODS       ======================================= */

			/* ====================  DATA MEMBERS  ======================================= */
			mutable Mutex mLock;

	}; /* -----  end of class Libserver  ----- */

}		/* -----  end of namespace android  ----- */
#endif   /* ----- #ifndef libserver_INC  ----- */
