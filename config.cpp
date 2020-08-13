class CfgPatches
{
	class CUP_Weapons_KSVK
	{
		units[] = {};
		weapons[] = {"CUP_srifle_ksvk","CUP_srifle_ksvk_PSO3","CUP_optic_PSO_3","CUP_optic_PSO_3_open"};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Acc","A3_Weapons_F_Beta_Acc","A3_Weapons_F_EPA_Acc","A3_Weapons_F_EPB_Acc","A3_Weapons_F_Bootcamp","A3_Data_F","A3_UI_F","A3_Anims_F","A3_Weapons_F_LongRangeRifles_M320","asdg_jointrails"};
		magazines[] = {"CUP_5Rnd_127x108_KSVK_M"};
		ammo[] = {"CUP_B_127x108_Ball_Green_Tracer"};
	};
};
class CfgAmmo
{
        class Default;
	class BulletCore;
	class BulletBase: BulletCore{};
        class CUP_B_127x108_Ball_Green_Tracer: BulletBase
	{
		hit = 30;
		indirectHit = 0;
		indirectHitRange = 0;
		cartridge = "";
		visibleFire = 21;
		audibleFire = 22;
		visibleFireTime = 3;
		cost = 20;
		airLock = 1;
		airFriction = -0.00062618;
		caliber = 2.07;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_green";
		tracerScale = 1.5;
		tracerStartTime = 0.075;
		tracerEndTime = 1;
		ACE_caliber = 12.979;
		ACE_bulletLength = 64.008;
		ACE_bulletMass = 48.276;
		ACE_ammoTempMuzzleVelocityShifts[] = {-26.55,-25.47,-22.85,-20.12,-16.98,-12.8,-7.64,-1.53,5.96,15.17,26.19};
		ACE_ballisticCoefficients[] = {0.63};
		ACE_velocityBoundaries[] = {};
		ACE_standardAtmosphere = "ASM";
		ACE_dragModel = 1;
		ACE_muzzleVelocities[] = {820};
		ACE_barrelLengths[] = {728.98};
		class CamShakeExplode
		{
			power = "(13^0.5)";
			duration = "((round (13^0.5))*0.2 max 0.2)";
			frequency = 20;
			distance = "((13^0.5)*3)";
		};
		class CamShakeHit
		{
			power = 13;
			duration = "((round (13^0.25))*0.2 max 0.2)";
			frequency = 20;
			distance = 1;
		};
	};
};

class CfgMagazines
{
	class CA_Magazine;

	class CUP_5Rnd_127x108_KSVK_M: CA_Magazine
	{
		author = "$STR_CUP_AUTHOR_STRING";
		scope = 2;
		displayName = "Магазин КСВК 5 патронов";
		ammo = "CUP_B_127x108_Ball_Green_Tracer";
		count = 5;
		picture = "\CUP\Weapons\CUP_Weapons_Ammunition\data\ui\m_ksvk_ca.paa";
		descriptionShort = "CUP_dss_ksvk_5rnd_M";
		mass = 20;
		initSpeed = 820;
		model = "\CUP\Weapons\CUP_Weapons_Ammunition\magazines\CUP_mag_5Rnd_KSVK.p3d";
		modelSpecial = "\CUP\Weapons\CUP_Weapons_Ammunition\magazines_proxy\CUP_mag_5Rnd_KSVK.p3d";
		modelSpecialIsProxy = 1;
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"\cup\weapons\cup_weapons_ksvk\data\ksvk_co.paa"};
	};
	
};
class CfgMagazineWells
{
	
	class CBA_127x108_KSVK
	{
		CUP_mags[] = {"CUP_5Rnd_127x108_KSVK_M"};
	};
	
};


class CfgRecoils
{
	KSVKRecoil[] = {0,0,0,0.1,0.2,2,0.05,-0.02,-0.03,0.05,0,0};
	KSVKRecoilProne[] = {0,0,0,0.1,0.11,0.005,0.05,-0.22,-0.01,0.05,0,0};
};

class CUP_DovetailMount;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class CUP_srifle_ksvk: Rifle_Base_F
	{
		class EventHandlers
		{
			fired = "_this call CBA_fnc_weaponEvents";
		};
		class CBA_weaponEvents
		{
			handAction = "CUP_GestureRechamberKSVK";
			sound = "CUP_BoltActionSound";
			soundLocation = "RightHandMiddle1";
			delay = 0.02;
			onEmpty = 0;
			hasOptic = 1;
			cartridgeType = "FxCartridge_127";
			cartridgeEjectPosition[] = {-0.24,0.03,0.07};
			cartridgeEjectVelocity[] = {0,1.2,0.5};
			cartridgeEjectDelay = 0.555;
		};
		dlc = "CUP_Weapons";
		author = "$STR_CUP_AUTHOR_STRING";
		selectionFireAnim = "zasleh";
		scope = 2;
		maxZeroing = 2000;
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
		discreteDistanceInitIndex = 2;
		magazines[] = {"CUP_5Rnd_127x108_KSVK_M"};
		magazineWell[] = {"CBA_127x108_KSVK"};
		model = "\CUP\Weapons\CUP_Weapons_KSVK\CUP_ksvk.p3d";
		picture = "\CUP\Weapons\CUP_Weapons_KSVK\data\UI\gear_ksvk_X_ca.paa";
		dexterity = 1;
		inertia = 1;
		aimTransitionSpeed = 0.5;
		initSpeed = -1.0;
		handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_KSVK\data\Anim\KSVK.rtm"};
		msxRecoilSway = 0.03;
		swayDecaySpeed = 1.25;
		displayName = "$STR_CUP_dn_ksvk";
		opticsEffects[] = {};
		opticsFlare = 1;
		opticsDisablePeripherialVision = 1;
		class GunParticles
		{
			class FirstEffect
			{
				effectName = "SniperCloud";
				positionName = "Usti hlavne";
				directionName = "Konec hlavne";
			};
		};
		class Library
		{
			libTextDesc = "$STR_CUP_lib_ksvk";
		};
		descriptionShort = "$STR_CUP_dss_ksvk";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 264.5;
			class CUP_DovetailMountKSVK: CUP_DovetailMount
			{
				iconPosition[] = {0.67,0.39};
				iconScale = 0.15;
				iconPicture = "\A3\Weapons_F\Data\UI\attachment_top.paa";
				iconPinPoint = "Bottom";
			};
			class PointerSlot{};
			class MuzzleSlot{};
			class CowsSlot{};
		};
		opticsZoomMin = 0.25;
		opticsZoomMax = 1.25;
		opticsZoomInit = 0.75;
		distanceZoomMin = 100;
		distanceZoomMax = 350;
		bullet1[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_01",0.7943282,1,15};
		bullet2[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_02",0.7943282,1,15};
		bullet3[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_03",0.7943282,1,15};
		bullet4[] = {"A3\sounds_f\weapons\shells\7_62\metal_762_04",0.7943282,1,15};
		bullet5[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_01",0.7943282,1,15};
		bullet6[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_02",0.7943282,1,15};
		bullet7[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_03",0.7943282,1,15};
		bullet8[] = {"A3\sounds_f\weapons\shells\7_62\dirt_762_04",0.7943282,1,15};
		bullet9[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_01",0.70794576,1,15};
		bullet10[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_02",0.70794576,1,15};
		bullet11[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_03",0.70794576,1,15};
		bullet12[] = {"A3\sounds_f\weapons\shells\7_62\grass_762_04",0.70794576,1,15};
		soundBullet[] = {"bullet1",0.083,"bullet2",0.083,"bullet3",0.083,"bullet4",0.083,"bullet5",0.083,"bullet6",0.083,"bullet7",0.083,"bullet8",0.083,"bullet9",0.083,"bullet10",0.083,"bullet11",0.083,"bullet12",0.083};
		modes[] = {"Single","far_optic1","medium_optic2","far_optic2"};
		jsrs_soundeffect = "JSRS2_Distance_Effects_BigSniper";
		ACE_barrelTwist = 457.2;
		ACE_barrelLength = 999.998;
		reloadAction = "GestureReloadDMR07";
		class Single: Mode_SemiAuto
		{
			dispersion = 0.00038;
			soundContinuous = 0;
			reloadTime = 2;
			sounds[] = {"StandardSound","SilencedSound"};
			class BaseSoundModeType
			{
				weaponSoundEffect = "DefaultRifle";
				closure1[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_Closure_01",1,1,30};
				closure2[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_Closure_02",1,1,30};
				soundClosure[] = {"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[] = {"CUP_AS50_Shot_SoundSet","GM6Lynx_Tail_SoundSet","GM6Lynx_InteriorTail_SoundSet"};
				begin1[] = {"CUP\Weapons\CUP_Weapons_KSVK\data\sfx\KSVK_s1",1,1,2000};
				soundBegin[] = {"begin1",1};
				class SoundTails
				{
					class TailInterior
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_tail_interior",1.41254,1,2000};
						frequency = 1;
						volume = "interior";
					};
					class TailTrees
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_tail_trees",1,1,2000};
						frequency = 1;
						volume = "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_tail_forest",1,1,2000};
						frequency = 1;
						volume = "(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_tail_meadows",1,1,2000};
						frequency = 1;
						volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\DMR_05_tail_houses",1,1,2000};
						frequency = 1;
						volume = "(1-interior/1.4)*houses";
					};
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_01",1,1,300};
				begin2[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_02",1,1,300};
				begin3[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_short_03",1,1,300};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
				class SoundTails
				{
					class TailInterior
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_interior",1,1,300};
						frequency = 1;
						volume = "interior";
					};
					class TailTrees
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_trees",1,1,300};
						frequency = 1;
						volume = "(1-interior/1.4)*trees";
					};
					class TailForest
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_forest",1,1,300};
						frequency = 1;
						volume = "(1-interior/1.4)*forest";
					};
					class TailMeadows
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_meadows",1,1,300};
						frequency = 1;
						volume = "(1-interior/1.4)*(meadows/2 max sea/2)";
					};
					class TailHouses
					{
						sound[] = {"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_05_Cyrus\silencer_DMR_05_tail_houses",1,1,300};
						frequency = 1;
						volume = "(1-interior/1.4)*houses";
					};
				};
			};
			minRange = 2;
			minRangeProbab = 0.5;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 450;
			maxRangeProbab = 0.3;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 500;
		};
		class far_optic1: Single
		{
			showToPlayer = 0;
			minRange = 150;
			minRangeProbab = 0.2;
			midRange = 500;
			midRangeProbab = 0.7;
			maxRange = 1500;
			maxRangeProbab = 0.4;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 500;
			requiredOpticType = 1;
		};
		class medium_optic2: Single
		{
			showToPlayer = 0;
			minRange = 250;
			minRangeProbab = 0.2;
			midRange = 750;
			midRangeProbab = 0.7;
			maxRange = 1000;
			maxRangeProbab = 0.4;
			aiRateOfFire = 5;
			aiRateOfFireDistance = 1000;
			requiredOpticType = 2;
		};
		class far_optic2: far_optic1
		{
			minRange = 500;
			minRangeProbab = 0.2;
			midRange = 1200;
			midRangeProbab = 0.7;
			maxRange = 2100;
			maxRangeProbab = 0.3;
			aiRateOfFire = 7;
			aiRateOfFireDistance = 1000;
			requiredOpticType = 2;
		};
		reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_KSVK\data\sfx\Reload",1,1,35};
		drySound[] = {"CUP\Weapons\CUP_Weapons_KSVK\data\sfx\Dry",1,1,35};
		deployedPivot = "bipod";
		hasBipod = 1;
		soundBipodDeploy[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy",0.70794576,1,20};
		soundBipodFold[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold",0.70794576,1,20};
		soundBipodDown[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down",0.70794576,1,20};
		soundBipodUp[] = {"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up",0.70794576,1,20};
		recoil = "recoil_m320";
	};



        class CUP_srifle_ksvk_PSO3: CUP_srifle_ksvk
	{
		author = "$STR_CUP_AUTHOR_STRING";
		scope = 2;
		class LinkedItems
		{
			class LinkedItemsOptic
			{
				slot = "CUP_DovetailMountKSVK";
				item = "CUP_optic_PSO_3";
			};
		};
	};
};

class CBA_PIPItems
{
	CUP_optic_PSO_3_open = "CUP_optic_PSO_3_open_pip";
};
