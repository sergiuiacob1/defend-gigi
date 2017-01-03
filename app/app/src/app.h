// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef APP_H
#define APP_H

#include <ngrest/common/Service.h>
#include "./arena/arena.h"
#include <vector>

struct GameInfo{
  int userId;
  int arenaId;
};

std::vector <Arena> arenas;
//! Dummy description for the service
/*! Some detailed description of the service */
// '*location' comment sets resource path for this service
// *location: app
class app: public ngrest::Service
{
public:
    // Here is an example of service operation
    //! Dummy description for the operation
    /*! Some detailed description of the operation */
    // To invoke this operation from browser open: http://localhost:9098/app/World!
    //
    // '*location' metacomment sets path to operation relative to service operation.
    // Default value is operation name.
    // This will bind "echo" method to resource path: http://host:port/app/{text}
    // *location: /{text}
    //
    // '*method' metacomment sets HTTP method for the operation. GET is default method.
    // *method: GET
    //


    // *location: /hello?name={name}
    // *method: GET
    std::string hello(const std::string& name);

    // *location: /get_arena_info?id={id}&userid={userId}
    // *method: GET
    ArenaInfo getArenaInfo(const std::string& id, const std::string& userId);

    // *location: /startgame?name={name}
    // *method: POST
    GameInfo startGame(name);

    // *location: /update_arena_info?arenaid={arenaId}&userid={userId}&move={move}
    // *method: POST
    std::string updateArenaInfo(const std::string& arenaId, const std::string& userId, const std::srtring& move);

};


#endif // APP_H



