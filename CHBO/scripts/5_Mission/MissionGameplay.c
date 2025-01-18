modded class MissionGameplay
{
    private Widget m_CraftingGuideUI;
    private TextWidget m_CraftingText;
    private ButtonWidget m_CloseButton;
    private bool m_IsCraftingGuideOpen = false;

    private ref RecipeList m_RecipeList;

    override void OnInit()
    {
        super.OnInit();
        m_RecipeList = new RecipeList();
    }

    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets("CHBO/gui/layouts/crafting_book.layout");

        // Bind UI elements
        m_CraftingText = TextWidget.Cast(layoutRoot.FindAnyWidget("CraftingText"));
        m_CloseButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("CloseButton"));

        // Attach button event
        m_CloseButton.SetHandler(this);

        return layoutRoot;
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);

        if (GetGame().GetInput().LocalPress("UACraftingGuide")) // Check for hotkey press
        {
            if (!m_IsCraftingGuideOpen)
            {
                ShowCraftingGuide();
            }
            else
            {
                HideCraftingGuide();
            }
        }
    }

    void ShowCraftingGuide()
    {
        if (!m_RecipeList || !m_CraftingText) return;

        // Build recipe text dynamically
        string recipeText = "";
        foreach (Recipe recipe : m_RecipeList.GetRecipes())
        {
            recipeText += recipe.Name + ": " + recipe.Ingredients + "\\n";
        }

        m_CraftingText.SetText(recipeText);
        m_CraftingGuideUI.Show(true);
        m_IsCraftingGuideOpen = true;
    }

    void HideCraftingGuide()
    {
        m_CraftingGuideUI.Show(false);
        m_IsCraftingGuideOpen = false;
    }

    override bool OnClick(Widget w, int x, int y, int button)
    {
        if (w == m_CloseButton)
        {
            HideCraftingGuide();
            return true;
        }
        return super.OnClick(w, x, y, button);
    }
}