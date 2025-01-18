class CfgPatches
{
    class CraftingBook
    {
        requiredVersion = 0.1;
        requiredAddons[] = {}; // DayZ base data dependency
    };
};

class CfgVehicles
{
    class CraftingBook
	{
    // The name for your mod will also show in the keybinds menu when Community Framework is installed
    name="Crafting Guide";
    type="mod";

     //This it path to the inputs.xml for defining your keybinds more to follow on this part
    inputs="CHBO\data\inputs.xml";

    //The list of dependencies for which modules you will be modding for this example we are only modding the Mission module
    dependencies[]={"Mission"};

    //This is the section where you define where the files are located for each module you are modding
    class defs
    {
      class missionScriptModule
      {
        files[]=
        {
          //This must be the path to the folder in which your scripts are contained for the specificed module
          "CHBO/scripts/5_Mission"
        };
      };
    };
  };
};