#include <imagine/util/preprocessor/repeat.h>
#include <emuframework/EmuInput.hh>
#include "EmuConfig.hh"

namespace EmuControls
{

const uint categories = 5;
const uint systemTotalKeys = gameActionKeys + gamepadKeys*4;

void transposeKeysForPlayer(KeyConfig::KeyArray &key, uint player)
{
	genericMultiplayerTranspose(key, player, 1);
}

static const char *gamepadName[gamepadKeys] =
{
	"Up",
	"Right",
	"Down",
	"Left",
	"Left+Up",
	"Right+Up",
	"Right+Down",
	"Left+Down",
	"Select",
	"Start",
	"A",
	"B",
	"Turbo A",
	"Turbo B",
	"A+B"
};

static const uint gamepadKeyOffset = gameActionKeys;
static const uint gamepad2KeyOffset = gamepadKeyOffset + gamepadKeys;
static const uint gamepad3KeyOffset = gamepad2KeyOffset + gamepadKeys;
static const uint gamepad4KeyOffset = gamepad3KeyOffset + gamepadKeys;

const KeyCategory category[MAX_CATEGORIES]
{
	EMU_CONTROLS_IN_GAME_ACTIONS_CATEGORY_INIT,
	{"Set Gamepad Keys", gamepadName, gamepadKeyOffset},
	{"Set Gamepad 2 Keys", gamepadName, gamepad2KeyOffset, 1},
	{"Set Gamepad 3 Keys", gamepadName, gamepad3KeyOffset, 1},
	{"Set Gamepad 4 Keys", gamepadName, gamepad4KeyOffset, 1}
};

const KeyConfig defaultKeyProfile[] =
{
	#ifdef CONFIG_BASE_ANDROID
	KEY_CONFIG_ANDROID_NAV_KEYS,
	#endif
	{
		Event::MAP_SYSTEM,
		0,
		"PC Keyboard",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_GENERIC_KB_PROFILE_INIT,

			Keycode::UP,
			Keycode::RIGHT,
			Keycode::DOWN,
			Keycode::LEFT,
			0, 0, 0, 0,
			Keycode::SPACE,
			Keycode::ENTER,
			Keycode::X,
			Keycode::Z,
			Keycode::S,
			Keycode::A,
		}
	},
	#ifdef CONFIG_INPUT_GAMEPAD_DEVICES
	{
		Event::MAP_SYSTEM,
		Device::SUBTYPE_GENERIC_GAMEPAD,
		"Generic Gamepad",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_ANDROID_GENERIC_GAMEPAD_PROFILE_INIT,

			Keycode::UP,
			Keycode::RIGHT,
			Keycode::DOWN,
			Keycode::LEFT,
			0, 0, 0, 0,
			Keycode::GAME_SELECT,
			Keycode::GAME_START,
			Keycode::GAME_A,
			Keycode::GAME_X,
			Keycode::GAME_B,
			Keycode::GAME_Y,
		}
	},
	#endif
	#ifdef CONFIG_ENV_WEBOS
	{
		Event::MAP_SYSTEM,
		0,
		"WebOS Keyboard",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_WEBOS_KB_PROFILE_INIT,

			EMU_CONTROLS_WEBOS_KB_8WAY_DIRECTION_PROFILE_INIT,
			Keycode::SPACE,
			Keycode::ENTER,
			Keycode::COMMA,
			Keycode::M,
			Keycode::I,
			Keycode::O,
		}
	},
	#endif
	#ifdef CONFIG_BASE_ANDROID
	{
		Event::MAP_SYSTEM,
		Device::SUBTYPE_PS3_CONTROLLER,
		"PS3 Controller",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_ANDROID_PS3_GAMEPAD_PROFILE_INIT,

			Keycode::PS3::UP,
			Keycode::PS3::RIGHT,
			Keycode::PS3::DOWN,
			Keycode::PS3::LEFT,
			0, 0, 0, 0,
			Keycode::PS3::SELECT,
			Keycode::PS3::START,
			Keycode::PS3::CROSS,
			Keycode::PS3::SQUARE,
			Keycode::PS3::CIRCLE,
			Keycode::PS3::TRIANGLE,
		}
	},
	{
		Event::MAP_SYSTEM,
		Device::SUBTYPE_OUYA_CONTROLLER,
		"OUYA Controller",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_OUYA_PROFILE_INIT,

			Keycode::Ouya::UP,
			Keycode::Ouya::RIGHT,
			Keycode::Ouya::DOWN,
			Keycode::Ouya::LEFT,
			0, 0, 0, 0,
			Keycode::Ouya::L3,
			Keycode::Ouya::R3,
			Keycode::Ouya::O,
			Keycode::Ouya::U,
			Keycode::Ouya::A,
			Keycode::Ouya::Y,
		}
	},
	{
		Event::MAP_SYSTEM,
		Device::SUBTYPE_NVIDIA_SHIELD,
		"NVidia Shield",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_NVIDIA_SHIELD_PROFILE_INIT,

			Keycode::UP,
			Keycode::RIGHT,
			Keycode::DOWN,
			Keycode::LEFT,
			0, 0, 0, 0,
			Keycode::GAME_LEFT_THUMB,
			Keycode::GAME_START,
			Keycode::GAME_A,
			Keycode::GAME_X,
			Keycode::GAME_B,
			Keycode::GAME_Y,
		}
	},
		#if __ARM_ARCH == 7
		{
			Event::MAP_SYSTEM,
			Device::SUBTYPE_XPERIA_PLAY,
			"Xperia Play",
			{
				EMU_CONTROLS_IN_GAME_ACTIONS_ANDROID_NAV_PROFILE_INIT,

				Keycode::XperiaPlay::UP,
				Keycode::XperiaPlay::RIGHT,
				Keycode::XperiaPlay::DOWN,
				Keycode::XperiaPlay::LEFT,
				0, 0, 0, 0,
				Keycode::XperiaPlay::SELECT,
				Keycode::XperiaPlay::START,
				Keycode::XperiaPlay::CROSS,
				Keycode::XperiaPlay::SQUARE,
				Keycode::XperiaPlay::CIRCLE,
				Keycode::XperiaPlay::TRIANGLE,
			}
		},
		{
			Event::MAP_SYSTEM,
			Device::SUBTYPE_MOTO_DROID_KEYBOARD,
			"Droid/Milestone Keyboard",
			{
				EMU_CONTROLS_IN_GAME_ACTIONS_ANDROID_NAV_PROFILE_INIT,

				Keycode::UP,
				Keycode::RIGHT,
				Keycode::DOWN,
				Keycode::LEFT,
				0, 0, 0, 0,
				Keycode::SPACE,
				Keycode::ENTER,
				Keycode::C,
				Keycode::X,
				Keycode::F,
				Keycode::D,
			}
		},
		#endif
	#endif
	#ifdef CONFIG_MACHINE_PANDORA
	{
		Event::MAP_SYSTEM,
		Device::SUBTYPE_PANDORA_HANDHELD,
		"Default Pandora",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_PANDORA_PROFILE_INIT,

			Keycode::Pandora::UP,
			Keycode::Pandora::RIGHT,
			Keycode::Pandora::DOWN,
			Keycode::Pandora::LEFT,
			0, 0, 0, 0,
			Keycode::Pandora::SELECT,
			Keycode::Pandora::START,
			Keycode::Pandora::X,
			Keycode::Pandora::A,
			Keycode::Pandora::B,
			Keycode::Pandora::Y,
		}
	},
	#endif
};

const uint defaultKeyProfiles = sizeofArray(defaultKeyProfile);

#ifdef CONFIG_INPUT_APPLE_GAME_CONTROLLER

const KeyConfig defaultAppleGCProfile[] =
{
	{
		Event::MAP_APPLE_GAME_CONTROLLER,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_APPLEGC_PROFILE_INIT,
			AppleGC::UP,
			AppleGC::RIGHT,
			AppleGC::DOWN,
			AppleGC::LEFT,
			0, 0, 0, 0,
			AppleGC::RSTICK_LEFT,
			AppleGC::RSTICK_RIGHT,
			AppleGC::A,
			AppleGC::X,
			AppleGC::B,
			AppleGC::Y,
		}
	},
};

const uint defaultAppleGCProfiles = sizeofArray(defaultAppleGCProfile);

#endif

// Wiimote

const KeyConfig defaultWiimoteProfile[] =
{
	{
		Event::MAP_WIIMOTE,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_WIIMOTE_PROFILE_INIT,

			Wiimote::UP,
			Wiimote::RIGHT,
			Wiimote::DOWN,
			Wiimote::LEFT,
			0, 0, 0, 0,
			Wiimote::MINUS,
			Wiimote::PLUS,
			Wiimote::_2,
			Wiimote::_1,
		}
	},
};

const uint defaultWiimoteProfiles = sizeofArray(defaultWiimoteProfile);

const KeyConfig defaultWiiCCProfile[] =
{
	{
		Event::MAP_WII_CC,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_WII_CC_PROFILE_INIT,

			WiiCC::UP,
			WiiCC::RIGHT,
			WiiCC::DOWN,
			WiiCC::LEFT,
			0, 0, 0, 0,
			WiiCC::MINUS,
			WiiCC::PLUS,
			WiiCC::B,
			WiiCC::Y,
			WiiCC::A,
			WiiCC::X,
		}
	},
};

const uint defaultWiiCCProfiles = sizeofArray(defaultWiiCCProfile);

// iControlPad

const KeyConfig defaultIControlPadProfile[] =
{
	{
		Event::MAP_ICONTROLPAD,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_ICP_NUBS_PROFILE_INIT,

			iControlPad::UP,
			iControlPad::RIGHT,
			iControlPad::DOWN,
			iControlPad::LEFT,
			0, 0, 0, 0,
			iControlPad::SELECT,
			iControlPad::START,
			iControlPad::X,
			iControlPad::A,
			iControlPad::B,
			iControlPad::Y,
		}
	},
};

const uint defaultIControlPadProfiles = sizeofArray(defaultIControlPadProfile);

// iCade

const KeyConfig defaultICadeProfile[] =
{
	{
		Event::MAP_ICADE,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_UNBINDED_PROFILE_INIT,

			ICade::UP,
			ICade::RIGHT,
			ICade::DOWN,
			ICade::LEFT,
			0, 0, 0, 0,
			ICade::SELECT,
			ICade::START,
			ICade::A,
			ICade::X,
			ICade::B,
			ICade::Y,
		}
	},
};

const uint defaultICadeProfiles = sizeofArray(defaultICadeProfile);

// Zeemote

const KeyConfig defaultZeemoteProfile[] =
{
	{
		Event::MAP_ZEEMOTE,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_UNBINDED_PROFILE_INIT,

			Zeemote::UP,
			Zeemote::RIGHT,
			Zeemote::DOWN,
			Zeemote::LEFT,
			0, 0, 0, 0,
			Zeemote::C,
			Zeemote::POWER,
			Zeemote::B,
			Zeemote::A,
		}
	},
};

const uint defaultZeemoteProfiles = sizeofArray(defaultZeemoteProfile);

// PS3

const KeyConfig defaultPS3Profile[] =
{
	{
		Event::MAP_PS3PAD,
		0,
		"Default",
		{
			EMU_CONTROLS_IN_GAME_ACTIONS_GENERIC_PS3PAD_PROFILE_INIT,

			PS3::UP,
			PS3::RIGHT,
			PS3::DOWN,
			PS3::LEFT,
			0, 0, 0, 0,
			PS3::SELECT,
			PS3::START,
			PS3::CROSS,
			PS3::SQUARE,
			PS3::CIRCLE,
			PS3::TRIANGLE,
		}
	},
};

const uint defaultPS3Profiles = sizeofArray(defaultPS3Profile);

};
