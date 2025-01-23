class CfgMods
{
	class chgm
	{
		dir="chgm";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Cheezus Servers 1 Required";
		credits="Shark";
		author="Shark";
		authorID="92618";
		version="Version 1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"chgm/4_World"
				};
			};
			class gameScriptModule
            {
                value="CreateGameMod"; // when value is filled, default script module entry function name is overwritten by it
                files[]={"chgm/3_Game"};
            };
			class missionScriptModule
            {
                value="";
                files[]={"chgm/5_Mission"};
            };
		};
	};
};
class CfgPatches
{
	class VPP_chgm
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
