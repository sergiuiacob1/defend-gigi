// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef APP_H
#define APP_H

#include <ngrest/common/Service.h>

//! Dummy description for the service
/*! Some detailed description of the service */
// '*location' comment sets resource path for this service
// *location: api
class app: public ngrest::Service
{
public:
    // *location: /hello?name={name}
    // *method: GET
    std::string hello(const std::string& name);

    // *location: /get_arena_info?id={id}&userid={userId}
    // *method: GET
    std::string getArenaInfo(const std::string& id, const std::string& userId);

    // *location: /startgame?name={name}&id={id}
    // *method: POST
    std::string startGame(const std::string& name, const std::string& id);

    // *location: /endgame?id={id}
    // *method: POST
    std::string endGame(const std::string& id);

    // *location: /update_arena_info?arenaid={arenaId}&userid={userId}&move={move}
    // *method: POST
    std::string updateArenaInfo(const std::string& arenaId, const std::string& userId, const std::string& move);

    // *location: /fire?arenaid={arenaId}&userid={userId}&x={x}&y={y}
    // *method: POST
    std::string fire(const std::string& arenaId, const std::string& userId, const std::string& x, const std::string& y);

};


#endif // APP_H



