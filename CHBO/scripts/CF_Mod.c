modded class CF_Mod
{
    override void OnInit()
    {
        super.OnInit();

        // Register keybinding (B key)
        CF_Keybinds.Get().RegisterKeyBind("ToggleCraftingGuide", "Toggle Crafting Guide", KeyCode.KB_B, GetCFModId());
    }
}