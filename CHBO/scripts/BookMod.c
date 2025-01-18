modded class MissionGameplay
{
	private Widget m_CloseBtn;
    protected ref Widget m_CraftingGuideUI; // UI widget for the guide
    protected bool m_IsCraftingGuideOpen = false; // Tracks if the UI is open
	
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/cui.day_z_ingamemenu.layout");
			
		m_CraftingText			= layoutRoot.FindAnyWidget( "ContinueBtn" );
		m_CraftingGuideUI				= layoutRoot.FindAnyWidget( "ExitBtn" );
		return layoutRoot;
	}
	override Widget Init()
	{
		m_CraftingGuideUI =           GetGame().GetWorkspace().CreateWidgets("BookMod/gui/layouts/crafting_guide.layout");
		
		m_CraftingText			 		= layoutRoot.FindAnyWidget( "CraftingText" );
		m_CloseButton					= layoutRoot.FindAnyWidget( "CloseButton" );
	}

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);

        // Check if the hotkey (B) is pressed
        if (GetGame().GetInput().LocalPress("UACraftingGuide")) // Matches keybinding in inputActions.txt
        {
            ToggleCraftingGuideUI();
        }
    }
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w == m_CloseButton)  // Check if the "Close" button was clicked
		{
			CloseCraftingGuide();  // Call the function to close the crafting book
			return true;
		}

		return super.OnClick(w, x, y, button);  // Pass any other clicks to the parent class
	}

    void ToggleCraftingGuideUI()
    {
        if (m_IsCraftingGuideOpen)
        {
            m_CraftingGuideUI.Show(false); // Hide the UI
            m_IsCraftingGuideOpen = false;
        }
        else
        {
            m_CraftingGuideUI.Show(true); // Show the UI
            m_IsCraftingGuideOpen = true;
        }
    }
	
	void CloseCraftingGuide()
	{
		if (m_IsCraftingGuideOpen)
		{
			m_CraftingGuideUI.Show(false); // Close the guide
			m_IsCraftingGuideOpen = false;
		}
	}
};