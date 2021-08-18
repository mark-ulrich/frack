/*
 * frack.cpp
 *
 *  frack game engine
 *  pong
 *
 * Created: 09/11/2018
 */

#include <cstdio>
#include <cstdlib>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Args.h"
#include "Engine.h"
#include "Macros.h"
#include "Types.h"



using std::shared_ptr;
using std::make_shared;


// TODO: move to Engine class?
shared_ptr<Args> g_args;


int main(int argc, const char *argv[])
{
    g_args = make_shared<Args>(Args(argc, argv));

    if (g_args->hasParm("-h") >= 0) {
        printf("there is no help for you\n");
        exit(0);
    }

    Engine& engine = Engine::getEngine();
    // engine.init();
    engine.run();

}

