/*
 * Version.h
 *
 * Created: 8/2/2013 5:31:52 PM
 *  Author: Elmar
 */ 


#ifndef VERSION_H_
#define VERSION_H_

uint8_t version_getExt();

uint8_t version_getNonvolatileProgramMemoryType();

uint16_t version_getArchitectureIdentifier();

uint8_t version_getInternalSramSize();

uint8_t version_getSecondNonvolatileProgramMemorySize();

uint8_t version_getNonvolatileProgramMemorySize();

uint8_t version_getEmbeddedProcessor();

uint8_t version_getVersion();

uint8_t version_getOsVersion();

uint8_t version_getKernelVersion();

uint8_t version_getHardwareVersion();

#endif /* VERSION_H_ */