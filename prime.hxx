
/* Include guard */
#ifndef __prime_hxx
	#define __prime_hxx 201506L

	/* Require C++ */
	#ifndef __cplusplus
		#error C++ is required

	/* Require C++ 14 */
	#elif __cplusplus < 201402L
		#error C++14 language standard is required

	/* Everything is OK */
	#else
		#include "__prime.hxx"

	#endif
#endif