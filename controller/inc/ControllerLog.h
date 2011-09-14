/*
#include <iostream>
#include <stdio.h>

// comment this out if you want debug output
//#define NO_CONTROLLER_LOG

#ifndef CONTROLLER_LOG_H
#define CONTROLLER_LOG_H

	// non-verbose mode
	#ifdef NO_CONTROLLER_LOG

		// declare macros as empty
		#define controller_debug_1(str)
		#define controller_debug_3(str, row, col)
		#define controller_debug_4(str, row, col, button)

	// verbose mode 
	#else
	
		#define dbg_str "*** logger-DEBUG: "
	
		#define controller_debug_1(str) std::cout << dbg_str << str << std::endl;
		
		#define controller_debug_3(str, row, col) std::cout << dbg_str; \
			printf(str, row, col); std::cout << std::endl;
			
		#define controller_debug_4(str, row, col, button) std::cout << dbg_str; \
			printf(str, row, col, button); std::cout << std::endl;
	
	#endif


#endif
*/
