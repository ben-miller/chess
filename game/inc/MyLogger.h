
#include <cassert>

//#define NO_LOGGER
//#define NDEBUG

#if !defined(MY_LOGGER)
#define MY_LOGGER

	// Non-Verbose
	#if defined(NO_LOGGER)
	
		#define DbgMsg(str);
		#define DbgMsgRC(str, row, col);
		#define DbgMsgRCB(str, row, col, button);
		
		// declare macros as empty
		#define PrintObject(functionName, objectName, objectPtr);
	
	// Verbose
	#else
		#include <iostream>
		#include <stdio.h>
	
		#define DbgMsg(str); \
			std::cout << "*** logger-DEBUG: " << str << std::endl;
	
		#define PrintObject(functionName, objectName, objectPtr); \
			DbgMsg(functionName << ": \"" << objectName \
			<< "\" (" << objectPtr << "):\n" << objectPtr->toString(1));
		
		#define dbg_str "*** logger-DEBUG: "
		
		#define DbgMsgRC(str, row, col) std::cout << dbg_str; \
			printf(str, row, col); std::cout << std::endl;
			
		#define DbgMsgRCB(str, row, col, button) std::cout << dbg_str; \
			printf(str, row, col, button); std::cout << std::endl;
	
	#endif

#endif
