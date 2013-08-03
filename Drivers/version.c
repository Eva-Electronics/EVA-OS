/*
 * Version.c
 *
 * Created: 8/2/2013 5:32:08 PM
 *  Author: Elmar
 */ 
#define KERNELVERSION 1
#define HARDWAREVERSION 1
#define OSVERSION 1

struct Version{
	uint8_t ext = (CHIPID_CIDR_EXT & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_EXT;
	uint8_t nonvolatileProgramMemoryType = (CHIPID_CIDR_NVPTYP_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_NVPTYP_Pos;
	uint16_t architectureIdentifier = (CHIPID_CIDR_ARCH_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_ARCH_Pos;
	uint8_t internalSramSize = (CHIPID_CIDR_SRAMSIZ_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_SRAMSIZ_Pos;
	uint8_t nonvolatileProgramMemorySize = (CHIPID_CIDR_EXT & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_EXT;
	uint8_t secondNonvolatileProgramMemorySize = (CHIPID_CIDR_EXT & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_EXT;
	uint8_t embeddedProcessor = (CHIPID_CIDR_EPROC_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_EPROC_Pos;
	uint8_t version = (CHIPID_CIDR_VERSION_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_VERSION_Pos;
	uint8_t osVersion = OSVERSION;
	uint8_t kernelVersion = KERNELVERSION;
	uint8_t hardware = HARDWAREVERSION;
};

uint8_t version_getExt()
{
	return (CHIPID_CIDR_EXT & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_EXT;
}

uint8_t version_getNonvolatileProgramMemoryType()
{
	return (CHIPID_CIDR_NVPTYP_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_NVPTYP_Pos;
}

uint16_t version_getArchitectureIdentifier()
{
	return (CHIPID_CIDR_ARCH_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_ARCH_Pos;
}

uint8_t version_getInternalSramSize()
{
	return (CHIPID_CIDR_SRAMSIZ_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_SRAMSIZ_Pos;
}

uint8_t version_getSecondNonvolatileProgramMemorySize()
{
	return (CHIPID_CIDR_NVPSIZ2_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_NVPSIZ2_Pos;
}

uint8_t version_getNonvolatileProgramMemorySize()
{
	return (CHIPID_CIDR_NVPSIZ_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_NVPSIZ_Pos;
}

uint8_t version_getEmbeddedProcessor()
{
	return (CHIPID_CIDR_EPROC_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_EPROC_Pos;
}

uint8_t version_getVersion()
{
	return (CHIPID_CIDR_VERSION_Msk & CHIPID->CHIPID_CIDR) >> CHIPID_CIDR_VERSION_Pos;
}

uint8_t version_getOsVersion()
{
	return 1;
}

uint8_t version_getKernelVersion()
{
	return 1;
}

uint8_t version_getHardwareVersion()
{
	return 1;
}