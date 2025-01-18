class Recipe
{
    string Name;
    string Ingredients;

    void Recipe(string name, string ingredients)
    {
        Name = name;
        Ingredients = ingredients;
    }
}

class RecipeList
{
    ref array<ref Recipe> Recipes;

    void RecipeList()
    {
        Recipes = new array<ref Recipe>;
        Recipes.Insert(new Recipe("Torch", "Stick + Rags"));
        Recipes.Insert(new Recipe("Fireplace", "Stick + Paper"));
        Recipes.Insert(new Recipe("Improvised Backpack", "Rope + Burlap Sack"));
    }

    array<ref Recipe> GetRecipes()
    {
        return Recipes;
    }
}