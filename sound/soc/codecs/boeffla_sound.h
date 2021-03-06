/*
 * Author: andip71
 * 
 * Version 1.1.0
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/mfd/wcd9xxx/core.h>
#include <linux/mfd/wcd9xxx/wcd9xxx_registers.h>
#include <linux/mfd/wcd9xxx/wcd9330_registers.h>
#include <linux/mfd/wcd9xxx/pdata.h>
#include "wcd9320.h"
#include "wcd9xxx-resmgr.h"
#include "wcd9xxx-common.h"


/*****************************************/
// Function declarations
/*****************************************/

// wcd9320 functions
extern unsigned int tomtom_read(struct snd_soc_codec *codec,
				unsigned int reg);
extern int tomtom_write(struct snd_soc_codec *codec, unsigned int reg,
	unsigned int value);
extern int tomtom_write_no_hook(struct snd_soc_codec *codec, unsigned int reg,
	unsigned int value);

// boeffla sound functions
void boeffla_sound_hook_tomtom_codec_probe(struct snd_soc_codec *codec_pointer);
unsigned int boeffla_sound_hook_tomtom_write(unsigned int reg, unsigned int value);


/*****************************************/
// Definitions
/*****************************************/

// Boeffla sound general
#define BOEFFLA_SOUND_DEFAULT 	0
#define BOEFFLA_SOUND_VERSION 	"1.1.0"
#define DEBUG_DEFAULT 			0

// headphone levels
#define HEADPHONE_DEFAULT		0
#define HEADPHONE_REG_OFFSET	0
#define HEADPHONE_MIN 			-30
#define HEADPHONE_MAX 			30

// speaker levels
#define SPEAKER_DEFAULT			0
#define SPEAKER_REG_OFFSET		-4
#define SPEAKER_MIN 			-30
#define SPEAKER_MAX 			30

// Microphone control
#define MICLEVEL_DEFAULT_GENERAL		0
#define MICLEVEL_REG_OFFSET_GENERAL		0
#define MICLEVEL_MIN_GENERAL			0
#define MICLEVEL_MAX_GENERAL			31

#define MICLEVEL_DEFAULT_CAM		0
#define MICLEVEL_REG_OFFSET_CAM		0
#define MICLEVEL_MIN_CAM			0
#define MICLEVEL_MAX_CAM			31
