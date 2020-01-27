
#ifndef __STRING_DEFINITIONS_HEADER__
#define __STRING_DEFINITIONS_HEADER__

// GET_ADD_INFO: class runtime information for child classes
// of VirtualBaseInit
#define VBI_STRING 	0x01	// next 1 byte contains element size
#define VBI_ARRAY	0x02	// next 2 byte contain element size
							// next 1 byte contains sign

#endif // __STRING_DEFINITIONS_HEADER__