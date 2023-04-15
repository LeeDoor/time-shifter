#pragma once
#include "game_object.hpp"

//builder class for game object class
//see more about builder pattern here: https://github.com/RefactoringGuru/design-patterns-cpp/blob/main/src/Builder/Conceptual/main.cc
class GameObjectBuilder {
private:
    GameObjectShar value; // builded value

public:
    GameObjectShar getValue(); // returns value

    GameObjectBuilder* reset(Vector2i pos_); // resets value
    // builds Drawable component for value
    GameObjectBuilder* buildDrawable(Vector2i size_, SDL_Renderer *ren_, const char *pathToImage_);
    // builds Physic component for value
    GameObjectBuilder* buildPhysic(Vector2i size_);

    /*
        keep adding other build functions for other components
    */
};

typedef std::shared_ptr<GameObjectBuilder> GameObjectBuilderShar;
typedef std::unique_ptr<GameObjectBuilder> GameObjectBuilderPtr;